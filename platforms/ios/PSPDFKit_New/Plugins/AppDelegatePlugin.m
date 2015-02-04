//
//  AppDelegatePlugin.m
//  PSPDFKit_New
//
//  Created by Shnoudi on 2/4/15.
//
//

#import "AppDelegate.h"
#import "MainViewController.h"

@implementation AppDelegate (AppDelegatePlugin)

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions
{
    NSSetUncaughtExceptionHandler(&uncaughtExceptionHandler);
    
    NSLog(@"Application Did Finish Launching With Options!!!");
    
    self.viewController = [[MainViewController alloc] init];
    
    return YES;
}

void uncaughtExceptionHandler(NSException *exception){
    NSLog(@"CRASH: %@", exception);
}

@end
