/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "OCSDKSDWebImageCompat.h"
#import "OCSDKSDWebImageOperation.h"
#import "OCSDKSDWebImageDownloader.h"
#import "OCSDKSDImageCache.h"

typedef NS_OPTIONS(NSUInteger, OCSDKSDWebImageOptions) {
    /**
     * By default, when a URL fail to be downloaded, the URL is blacklisted so the library won't keep trying.
     * This flag disable this blacklisting.
     */
    OCSDKSDWebImageRetryFailed = 1 << 0,

    /**
     * By default, image downloads are started during UI interactions, this flags disable this feature,
     * leading to delayed download on UIScrollView deceleration for instance.
     */
    OCSDKSDWebImageLowPriority = 1 << 1,

    /**
     * This flag disables on-disk caching
     */
    OCSDKSDWebImageCacheMemoryOnly = 1 << 2,

    /**
     * This flag enables progressive download, the image is displayed progressively during download as a browser would do.
     * By default, the image is only displayed once completely downloaded.
     */
    OCSDKSDWebImageProgressiveDownload = 1 << 3,

    /**
     * Even if the image is cached, respect the HTTP response cache control, and refresh the image from remote location if needed.
     * The disk caching will be handled by NSURLCache instead of SDWebImage leading to slight performance degradation.
     * This option helps deal with images changing behind the same request URL, e.g. Facebook graph api profile pics.
     * If a cached image is refreshed, the completion block is called once with the cached image and again with the final image.
     *
     * Use this flag only if you can't make your URLs static with embeded cache busting parameter.
     */
    OCSDKSDWebImageRefreshCached = 1 << 4,

    /**
     * In iOS 4+, continue the download of the image if the app goes to background. This is achieved by asking the system for
     * extra time in background to let the request finish. If the background task expires the operation will be cancelled.
     */
    OCSDKSDWebImageContinueInBackground = 1 << 5,

    /**
     * Handles cookies stored in NSHTTPCookieStore by setting
     * NSMutableURLRequest.HTTPShouldHandleCookies = YES;
     */
    OCSDKSDWebImageHandleCookies = 1 << 6,

    /**
     * Enable to allow untrusted SSL ceriticates.
     * Useful for testing purposes. Use with caution in production.
     */
    OCSDKSDWebImageAllowInvalidSSLCertificates = 1 << 7,

    /**
     * By default, image are loaded in the order they were queued. This flag move them to
     * the front of the queue and is loaded immediately instead of waiting for the current queue to be loaded (which 
     * could take a while).
     */
    OCSDKSDWebImageHighPriority = 1 << 8,
    
    /**
     * By default, placeholder images are loaded while the image is loading. This flag will delay the loading
     * of the placeholder image until after the image has finished loading.
     */
    OCSDKSDWebImageDelayPlaceholder = 1 << 9
};

typedef void(^OCSDKSDWebImageCompletionBlock)(UIImage *image, NSError *error, OCSDKSDImageCacheType cacheType, NSURL *imageURL);

typedef void(^OCSDKSDWebImageCompletionWithFinishedBlock)(UIImage *image, NSError *error, OCSDKSDImageCacheType cacheType, BOOL finished, NSURL *imageURL);


@class OCSDKSDWebImageManager;

@protocol OCSDKSDWebImageManagerDelegate <NSObject>

@optional

/**
 * Controls which image should be downloaded when the image is not found in the cache.
 *
 * @param imageManager The current `OCSDKSDWebImageManager`
 * @param imageURL     The url of the image to be downloaded
 *
 * @return Return NO to prevent the downloading of the image on cache misses. If not implemented, YES is implied.
 */
- (BOOL)imageManager:(OCSDKSDWebImageManager *)imageManager shouldDownloadImageForURL:(NSURL *)imageURL;

/**
 * Allows to transform the image immediately after it has been downloaded and just before to cache it on disk and memory.
 * NOTE: This method is called from a global queue in order to not to block the main thread.
 *
 * @param imageManager The current `OCSDKSDWebImageManager`
 * @param image        The image to transform
 * @param imageURL     The url of the image to transform
 *
 * @return The transformed image object.
 */
- (UIImage *)imageManager:(OCSDKSDWebImageManager *)imageManager transformDownloadedImage:(UIImage *)image withURL:(NSURL *)imageURL;

@end

/**
 * The OCSDKSDWebImageManager is the class behind the UIImageView+WebCache category and likes.
 * It ties the asynchronous downloader (SDWebImageDownloader) with the image cache store (SDImageCache).
 * You can use this class directly to benefit from web image downloading with caching in another context than
 * a UIView.
 *
 * Here is a simple example of how to use OCSDKSDWebImageManager:
 *
 * @code

OCSDKSDWebImageManager *manager = [OCSDKSDWebImageManager sharedManager];
[manager downloadWithURL:imageURL
                 options:0
                progress:nil
               completed:^(UIImage *image, NSError *error, OCSDKSDImageCacheType cacheType, BOOL finished, NSURL *imageURL) {
                   if (image) {
                       // do something with image
                   }
               }];

 * @endcode
 */
@interface OCSDKSDWebImageManager : NSObject

@property (weak, nonatomic) id <OCSDKSDWebImageManagerDelegate> delegate;

@property (strong, nonatomic, readonly) OCSDKSDImageCache *imageCache;
@property (strong, nonatomic, readonly) OCSDKSDWebImageDownloader *imageDownloader;

/**
 * The cache filter is a block used each time OCSDKSDWebImageManager need to convert an URL into a cache key. This can
 * be used to remove dynamic part of an image URL.
 *
 * The following example sets a filter in the application delegate that will remove any query-string from the
 * URL before to use it as a cache key:
 *
 * @code

[[OCSDKSDWebImageManager sharedManager] setCacheKeyFilter:^(NSURL *url) {
    url = [[NSURL alloc] initWithScheme:url.scheme host:url.host path:url.path];
    return [url absoluteString];
}];

 * @endcode
 */
@property (strong) NSString *(^cacheKeyFilter)(NSURL *url);

/**
 * Returns global OCSDKSDWebImageManager instance.
 *
 * @return OCSDKSDWebImageManager shared instance
 */
+ (OCSDKSDWebImageManager *)sharedManager;

/**
 * Downloads the image at the given URL if not present in cache or return the cached version otherwise.
 *
 * @param url            The URL to the image
 * @param options        A mask to specify options to use for this request
 * @param progressBlock  A block called while image is downloading
 * @param completedBlock A block called when operation has been completed.
 *
 *   This parameter is required.
 * 
 *   This block has no return value and takes the requested UIImage as first parameter.
 *   In case of error the image parameter is nil and the second parameter may contain an NSError.
 *
 *   The third parameter is an `OCSDKSDImageCacheType` enum indicating if the image was retrived from the local cache
 *   or from the memory cache or from the network.
 *
 *   The last parameter is set to NO when the SDWebImageProgressiveDownload option is used and the image is 
 *   downloading. This block is thus called repetidly with a partial image. When image is fully downloaded, the
 *   block is called a last time with the full image and the last parameter set to YES.
 *
 * @return Returns an NSObject conforming to OCSDKSDWebImageOperation. Should be an instance of OCSDKSDWebImageDownloaderOperation
 */
- (id <OCSDKSDWebImageOperation>)downloadImageWithURL:(NSURL *)url
                                         options:(OCSDKSDWebImageOptions)options
                                        progress:(OCSDKSDWebImageDownloaderProgressBlock)progressBlock
                                       completed:(OCSDKSDWebImageCompletionWithFinishedBlock)completedBlock;

/**
 * Saves image to cache for given URL
 *
 * @param image The image to cache
 * @param url   The URL to the image
 *
 */

- (void)saveImageToCache:(UIImage *)image forURL:(NSURL *)url;

/**
 * Cancel all current opreations
 */
- (void)cancelAll;

/**
 * Check one or more operations running
 */
- (BOOL)isRunning;

/**
 * Check if image has already been cached
 */
- (BOOL)cachedImageExistsForURL:(NSURL *)url;
- (BOOL)diskImageExistsForURL:(NSURL *)url;

/**
 *Return the cache key for a given URL
 */
- (NSString *)cacheKeyForURL:(NSURL *)url;

@end


#pragma mark - Deprecated

typedef void(^OCSDKSDWebImageCompletedBlock)(UIImage *image, NSError *error, OCSDKSDImageCacheType cacheType) __deprecated_msg("Block type deprecated. Use `SDWebImageCompletionBlock`");
typedef void(^OCSDKSDWebImageCompletedWithFinishedBlock)(UIImage *image, NSError *error, OCSDKSDImageCacheType cacheType, BOOL finished) __deprecated_msg("Block type deprecated. Use `SDWebImageCompletionWithFinishedBlock`");


@interface OCSDKSDWebImageManager (Deprecated)

/**
 *  Downloads the image at the given URL if not present in cache or return the cached version otherwise.
 *
 *  @deprecated This method has been deprecated. Use `downloadImageWithURL:options:progress:completed:`
 */
- (id <OCSDKSDWebImageOperation>)downloadWithURL:(NSURL *)url
                                    options:(OCSDKSDWebImageOptions)options
                                   progress:(OCSDKSDWebImageDownloaderProgressBlock)progressBlock
                                  completed:(OCSDKSDWebImageCompletedWithFinishedBlock)completedBlock __deprecated_msg("Method deprecated. Use `downloadImageWithURL:options:progress:completed:`");

@end
