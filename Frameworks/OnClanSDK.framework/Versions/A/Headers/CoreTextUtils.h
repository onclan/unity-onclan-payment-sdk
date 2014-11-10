//
//  CoreTextUtils.h
//  OHAttributedLabel
//
//  Created by Olivier Halligon on 23/09/12.
//  Copyright (c) 2012 AliSoftware. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreText/CoreText.h>

/////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Text Alignment Convertion
/////////////////////////////////////////////////////////////////////////////////////

CTTextAlignment OCSDKCTTextAlignmentFromUITextAlignment(NSTextAlignment alignment);
CTLineBreakMode OCSDKCTLineBreakModeFromUILineBreakMode(NSLineBreakMode lineBreakMode);

/////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Flipping Coordinates
/////////////////////////////////////////////////////////////////////////////////////

CGPoint OCSDKCGPointFlipped(CGPoint point, CGRect bounds);
CGRect OCSDKCGRectFlipped(CGRect rect, CGRect bounds);

/////////////////////////////////////////////////////////////////////////////////////
#pragma mark - NSRange / CFRange
/////////////////////////////////////////////////////////////////////////////////////

NSRange OCSDKNSRangeFromCFRange(CFRange range);

/////////////////////////////////////////////////////////////////////////////////////
#pragma mark - CoreText CTLine/CTRun utils
/////////////////////////////////////////////////////////////////////////////////////

CGRect OCSDKCTLineGetTypographicBoundsAsRect(CTLineRef line, CGPoint lineOrigin);
CGRect OCSDKCTRunGetTypographicBoundsAsRect(CTRunRef run, CTLineRef line, CGPoint lineOrigin);
BOOL OCSDKCTLineContainsCharactersFromStringRange(CTLineRef line, NSRange range);
BOOL OCSDKCTRunContainsCharactersFromStringRange(CTRunRef run, NSRange range);
