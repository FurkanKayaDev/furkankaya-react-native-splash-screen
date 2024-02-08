/**
 * SplashScreen
 * Author:Furkankayadev
 * GitHub:https://github.com/furkankayadev 
 */ 
#import <React/RCTBridge.h>
#import <UIKit/UIKit.h>

@interface RNSplashScreen : NSObject <RCTBridgeModule>

RCT_EXPORT_MODULE(SplashScreen);

/**
 * Shows a custom splash screen image in the given root view.
 *
 * @param screenName Name of the nib file containing the splash screen image.
 * @param rootView The root view where the splash screen should be displayed.
 */
RCT_EXPORT_METHOD(showSplash:(NSString *)screenName rootView:(UIView *)rootView);

/**
 * Shows the default splash screen.
 */
RCT_EXPORT_METHOD(show);

/**
 * Hides the splash screen.
 */
RCT_EXPORT_METHOD(hide);

@end