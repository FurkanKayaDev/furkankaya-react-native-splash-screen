/**
 * SplashScreen
 * Author:Furkankayadev
 * GitHub:https://github.com/furkankayadev 
 */ 
#import <React/RCTBridgeModule.h>
#import <UIKit/UIKit.h>

@interface RNSplashScreen : NSObject<RCTBridgeModule>
+ (void)showSplash:(NSString*)splashScreen inRootView:(UIView*)rootView;
+ (void)show;
+ (void)hide;
@end
