//
//  PSPDFRichMediaExecuteAction.h
//  PSPDFKit
//
//  Copyright (c) 2013-2014 PSPDFKit GmbH. All rights reserved.
//
//  THIS SOURCE CODE AND ANY ACCOMPANYING DOCUMENTATION ARE PROTECTED BY INTERNATIONAL COPYRIGHT LAW
//  AND MAY NOT BE RESOLD OR REDISTRIBUTED. USAGE IS BOUND TO THE PSPDFKIT LICENSE AGREEMENT.
//  UNAUTHORIZED REPRODUCTION OR DISTRIBUTION IS SUBJECT TO CIVIL AND CRIMINAL PENALTIES.
//  This notice may not be removed from this file.
//

#import "PSPDFAction.h"

@class PSPDFRichMediaAnnotation;

/// A rich-media-execute action identifies a rich media annotation and specifies a command to be sent to that annotation’s handler. (See Section 9.6, “Rich Media” on page 76. of the Adobe® Supplement to the ISO 32000)
@interface PSPDFRichMediaExecuteAction : PSPDFAction

/// Designated initializer.
- (instancetype)initWithCommand:(NSString *)command argument:(NSString *)argument annotation:(PSPDFRichMediaAnnotation *)annotation;

/// The rich media action command.
@property (nonatomic, copy, readonly) NSString *command;

/// The rich media action command argument
@property (nonatomic, copy, readonly) NSString *argument;

/// The associated screen annotation. Optional. Will link to an already existing annotation.
@property (nonatomic, weak, readonly) PSPDFRichMediaAnnotation *annotation;

@end
