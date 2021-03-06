//
//  PSPDFPolygonAnnotation.h
//  PSPDFKit
//
//  Copyright (c) 2013-2014 PSPDFKit GmbH. All rights reserved.
//
//  THIS SOURCE CODE AND ANY ACCOMPANYING DOCUMENTATION ARE PROTECTED BY INTERNATIONAL COPYRIGHT LAW
//  AND MAY NOT BE RESOLD OR REDISTRIBUTED. USAGE IS BOUND TO THE PSPDFKIT LICENSE AGREEMENT.
//  UNAUTHORIZED REPRODUCTION OR DISTRIBUTION IS SUBJECT TO CIVIL AND CRIMINAL PENALTIES.
//  This notice may not be removed from this file.
//

#import "PSPDFAbstractLineAnnotation.h"

typedef NS_ENUM(NSInteger, PSPDFPolygonAnnotationIntent) {
    PSPDFPolygonAnnotationIntentNone = 0,         /// No intent.
    PSPDFPolygonAnnotationIntentPolygonCloud,     /// The annotation is intended to function as a cloud object.
    PSPDFPolygonAnnotationIntentPolygonDimension, /// The polygon annotation is intended to function as a dimension. (not implemented)
};

/// Polygon annotations (PDF 1.5) display closed polygons on the page. Such polygons may have any number of vertices connected by straight lines. Polyline annotations (PDF 1.5) are similar to polygons, except that the first and last vertex are not implicitly connected.
@interface PSPDFPolygonAnnotation : PSPDFAbstractLineAnnotation

/// Designated initializer.
- (instancetype)init;

/// The points of the polygon.
/// Contains `NSValue` objects that box a `CGPoint`.
/// @warning These values are generated on the fly from an internal representation, so use carefully.
@property (nonatomic, copy) NSArray *points;

/// Defines the annotation intent. (Optional; PDF 1.6). Defaults to `PSPDFPolygonAnnotationIntentNone`.
@property (nonatomic, assign) PSPDFPolygonAnnotationIntent intentType;

@end
