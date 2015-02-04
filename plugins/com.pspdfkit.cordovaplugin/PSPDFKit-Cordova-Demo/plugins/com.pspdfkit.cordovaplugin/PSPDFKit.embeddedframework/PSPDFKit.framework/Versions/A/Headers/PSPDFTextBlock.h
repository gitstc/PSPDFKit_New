//
//  PSPDFTextBlock.h
//  PSPDFKit
//
//  Copyright (c) 2012-2014 PSPDFKit GmbH. All rights reserved.
//
//  THIS SOURCE CODE AND ANY ACCOMPANYING DOCUMENTATION ARE PROTECTED BY INTERNATIONAL COPYRIGHT LAW
//  AND MAY NOT BE RESOLD OR REDISTRIBUTED. USAGE IS BOUND TO THE PSPDFKIT LICENSE AGREEMENT.
//  UNAUTHORIZED REPRODUCTION OR DISTRIBUTION IS SUBJECT TO CIVIL AND CRIMINAL PENALTIES.
//  This notice may not be removed from this file.
//

#import <Foundation/Foundation.h>

/// Represents multiple words forming a text block. (e.g. a Column)
@interface PSPDFTextBlock : NSObject <NSCopying, NSSecureCoding>

/// Designated initializer.
- (instancetype)initWithGlyphs:(NSArray *)glyphs NS_DESIGNATED_INITIALIZER;

/// Frame of the text block. Not rotated.
@property (nonatomic, assign, readonly) CGRect frame;

/// All glyphs of the current text block.
@property (nonatomic, copy, readonly) NSArray *glyphs;

/// All words of the current text block. Evaluated lazily.
@property (nonatomic, copy, readonly) NSArray *words;

/// Returns the content of the text block (all words merged together)
@property (nonatomic, copy, readonly) NSString *content;

/// Compare.
- (BOOL)isEqualToTextBlock:(PSPDFTextBlock *)otherBlock;

@end