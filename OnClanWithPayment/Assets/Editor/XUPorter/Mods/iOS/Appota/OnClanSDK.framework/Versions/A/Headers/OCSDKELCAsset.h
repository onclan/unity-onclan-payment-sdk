//
//  Asset.h
//
//  Created by ELC on 2/15/11.
//  Copyright 2011 ELC Technologies. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AssetsLibrary/AssetsLibrary.h>

@class OCSDKELCAsset;

@protocol ELCAssetDelegate <NSObject>

@optional
- (void)assetSelected:(OCSDKELCAsset *)asset;

@end

@interface OCSDKELCAsset : NSObject

@property (nonatomic, retain) UIImage *imageThumb;
@property (nonatomic, retain) ALAsset *asset;
@property (nonatomic, assign) id<ELCAssetDelegate> parent;
@property (nonatomic, assign) BOOL selected;

- (id)initWithAsset:(ALAsset *)asset;

@end