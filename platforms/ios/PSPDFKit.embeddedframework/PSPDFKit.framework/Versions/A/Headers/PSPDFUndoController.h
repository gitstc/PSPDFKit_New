//
//  PSPDFUndoManager.h
//  PSPDFKit
//
//  Copyright (c) 2011-2014 PSPDFKit GmbH. All rights reserved.
//
//  THIS SOURCE CODE AND ANY ACCOMPANYING DOCUMENTATION ARE PROTECTED BY INTERNATIONAL COPYRIGHT LAW
//  AND MAY NOT BE RESOLD OR REDISTRIBUTED. USAGE IS BOUND TO THE PSPDFKIT LICENSE AGREEMENT.
//  UNAUTHORIZED REPRODUCTION OR DISTRIBUTION IS SUBJECT TO CIVIL AND CRIMINAL PENALTIES.
//  This notice may not be removed from this file.
//

#import <Foundation/Foundation.h>
#import "PSPDFUndoProtocol.h"

// Sent once we have new undo operations available.
extern NSString * const PSPDFUndoControllerAddedUndoActionNotification;

/// This is a custom undo manager that can coalesce similar changes within the same group.
/// This class is also completely thread safe.
@interface PSPDFUndoController : NSObject

/// Designated initializer.
/// If `undoEnabled` is set to NO, the `performBlock*` operations will directly call block.
- (instancetype)initWithUndoEnabled:(BOOL)undoEnabled NS_DESIGNATED_INITIALIZER;

/// Returns YES if the undo controller is currently either undoing or redoing.
- (BOOL)isWorking;

/// Returns YES if the undo controller is currently undoing.
- (BOOL)isUndoing;

/// Returns YES if the undo controller is currently redoing.
- (BOOL)isRedoing;

/// Returns YES if undoable operations have been recorded.
- (BOOL)canUndo;

/// Returns YES if redoable operations have been recorded.
- (BOOL)canRedo;

/// Performs an undo operation.
- (void)undo;

/// Performs a redo operation.
- (void)redo;

/// Begin/end an undo group.
/// @note `-performBlockAsGroup:` is preferred since it is less error prone.
/// If `groupName` is nil, a default name for the changes will be inferred.
- (void)beginUndoGrouping;
- (void)endUndoGroupingWithName:(NSString *)groupName;

/// Helper that will infer a good name for `changedProperty` of `object`.
- (void)endUndoGroupingWithProperty:(NSString *)changedProperty ofObject:(id)object;

/// Removes all recorded actions.
- (void)removeAllActions;

/// Removes all recorded actions with the provided target.
/// Implement `performUndoAction:` from `PSPDFUndoProtocol` to add support for conditional
/// removal of `PSPDFUndoProtocol` tracked (observed) changes.
- (void)removeAllActionsWithTarget:(id)target;

/// Register/unregister objects.
- (void)registerObjectForUndo:(NSObject <PSPDFUndoProtocol> *)object;
- (void)unregisterObjectForUndo:(NSObject <PSPDFUndoProtocol> *)object;
- (BOOL)isObjectRegisteredForUndo:(NSObject <PSPDFUndoProtocol> *)object;

/// Performs a block and groups all observed changes into one event.
- (void)performBlockAsGroup:(void (^)(void))block name:(NSString *)groupName;

/// Performs a block and ignores all observed changes.
- (void)performBlockWithoutUndo:(void (^)(void))block;

/// Support for regular invocation based undo
/// Perform the call you would normally invoke after [undoManager prepareWithInvocationTarget:target]
/// on the proxy passed into the block.
- (void)prepareWithInvocationTarget:(id)target block:(void (^)(id proxy))block;

/// Undo can be disabled globally, set this before any objects are registered on the controller.
@property (nonatomic, assign, getter=isUndoEnabled, readonly) BOOL undoEnabled;

/// Provides access to the underlying `NSUndoManager`. You are strongly encouraged to not use this
/// property since it is not thread safe and `PSPDFUndoController` manages the state of this undo manager.
/// However, since `UIResponders` can provide an undo manager, this property is exposed.
@property (nonatomic, strong, readonly) NSUndoManager *undoManager;

/// Specifies the time interval that is used for `PSPDFUndoCoalescingTimed`. Defaults to 0.5 seconds.
@property (nonatomic, assign) NSTimeInterval timedCoalescingInterval;

/// Specifies the levels of undo we allow. Defaults to 40. More means higher memory usage.
@property (nonatomic, assign) NSUInteger levelsOfUndo;

/// Required for conditional undo removal support using `removeAllActionsWithTarget:`.
/// @see PSPDFUndoProtocol
- (void)performUndoAction:(PSPDFUndoAction *)action;

@end

@interface PSPDFUndoController (TimeCoalescingSupport)

/// Commits all incomplete undo actions. This method is automatically called before undoing or redoing,
/// so there's usually no need to call this method directly.
- (void)commitIncompleteUndoActions;

/// Indicates that there are still incomplete undo actions because of a coalescing policy.
- (BOOL)hasIncompleteUndoActions;

/// Returns the name of the most recent incomplete action or nil.
- (NSString *)incompleteUndoActionName;

@end

// Executes undo block if the undo controller is available.
extern void PSPDFPerformBlockAsGroup(PSPDFUndoController *undoController, dispatch_block_t block, NSString *name);

// Executes undo block if the undo controller is available.
extern void PSPDFPerformBlockWithoutUndo(PSPDFUndoController *undoController, dispatch_block_t block);
