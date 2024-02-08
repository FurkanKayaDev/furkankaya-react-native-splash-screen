# react-native-splash-screen


<p align="center" >
  <img alt="NPM package version" src="https://img.shields.io/npm/v/furkankaya-react-native-splash-screen?style=for-the-badge">

  <img alt="NPM package downloads" src="https://img.shields.io/npm/dt/furkankaya-react-native-splash-screen?style=for-the-badge">
 
  <img alt="License" src="https://img.shields.io/badge/license-MIT-blue.svg?style=for-the-badge" />
</p>

Splash screen for React Native that hides automatically after the app loads, works on both iOS and Android

## Content

- [Installation](#installation)
- [Examples](#examples)
- [Getting started](#getting-started)
- [API](#api)


## Examples  
* [Examples](https://github.com/crazycodeboy/react-native-splash-screen/tree/master/examples)




## Installation

### First step(Download):
Run 

`npm i furkankaya-react-native-splash-screen --save` or

`yarn  add furkankaya-react-native-splash-screen` 
#### Installation  

**Android:**

1. In your `android/settings.gradle` file, make the following additions:
```java
include ':furkankaya-react-native-splash-screen'   
project(':furkankaya-react-native-splash-screen').projectDir = new File(rootProject.projectDir, '../node_modules/furkankaya-react-native-splash-screen/android')
```

2. In your android/app/build.gradle file, add the `:furkankaya-react-native-splash-screen` project as a compile-time dependency:

```java
...
dependencies {
    ...
    implementation project(':furkankaya-react-native-splash-screen')
}
```

### Important Notice for React Native 0.73 and above
As of React Native 0.73, Kotlin has become the recommended language for Android development. This means that while the previous versions required changes to the MainApplication.java file, for React Native 0.73 and above, you need to make the necessary changes to the MainActivity.kt

#####react-native < 0.73 

3. Update the MainApplication.java file to use `furkankaya-react-native-splash-screen` via the following changes:


```java
// react-native-splash-screen >= 0.3.1
import org.devio.rn.splashscreen.SplashScreenReactPackage;
// react-native-splash-screen < 0.3.1
import com.cboy.rn.splashscreen.SplashScreenReactPackage;

public class MainApplication extends Application implements ReactApplication {

    private final ReactNativeHost mReactNativeHost = new ReactNativeHost(this) {
        @Override
        public boolean getUseDeveloperSupport() {
            return BuildConfig.DEBUG;
        }

        @Override
        protected List<ReactPackage> getPackages() {
            return Arrays.<ReactPackage>asList(
                    new MainReactPackage(),
            new SplashScreenReactPackage()  //here
            );
        }
    };

    @Override
    public ReactNativeHost getReactNativeHost() {
        return mReactNativeHost;
    }
}
```

#####react-native >= 0.73

3. Update the MainActivity.kt file to use `furkankaya-react-native-splash-screen` via the following changes:

```java
import com.facebook.react.ReactActivity
import com.facebook.react.ReactActivityDelegate
import com.facebook.react.defaults.DefaultNewArchitectureEntryPoint.fabricEnabled
import com.facebook.react.defaults.DefaultReactActivityDelegate

import org.devio.rn.splashscreen.SplashScreen;  //here
import android.os.Bundle //here

class MainActivity : ReactActivity() {
 
  override fun getMainComponentName(): String = "splashScreenTest"

 
  override fun onCreate(savedInstanceState: Bundle?) { // this function 
      SplashScreen.show(this) 
      super.onCreate(savedInstanceState)
    }

  override fun createReactActivityDelegate(): ReactActivityDelegate =
      DefaultReactActivityDelegate(this, mainComponentName, fabricEnabled)
}

```

**iOS:**

1. `cd ios`
2. `run pod install`
 


### Third step(Plugin Configuration):

**iOS:**

Update `AppDelegate.mm` with the following additions:


```obj-c
#import "AppDelegate.h"

#import <React/RCTBundleURLProvider.h> 

#import "RNSplashScreen.h" //here

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  self.moduleName = @"splashTest";

  self.initialProps = @{};
  
  //------------------------------------------------------------//

  bool didLaunchFinish = [super application:application didFinishLaunchingWithOptions:launchOptions]; //here

  [RNSplashScreen show]; //here
  
  return didLaunchFinish; //here
  
  //------------------------------------------------------------//
  
  OR
  
  //------------------------------------------------------------//
  
    [RNSplashScreen show];  // here
	
    return YES;
	
  //------------------------------------------------------------//
}

@end

```

###Example

Before
![before](https://github.com/FurkanKayaDev/react-native-splash-screen/assets/103508575/2a4c1afc-3f6a-4943-98b4-76453912640f)


After
![after](https://github.com/FurkanKayaDev/react-native-splash-screen/assets/103508575/0ec8a935-feb6-4d07-aebf-b3a1d80bbbfe)


## Getting started  

Import `furkan-kaya-react-native-splash-screen` in your JS file.

`import SplashScreen from 'furkan-kaya-react-native-splash-screen`    

### Android:

Create a file called `launch_screen.xml` in `app/src/main/res/layout` (create the `layout`-folder if it doesn't exist). The contents of the file should be the following:

```xml
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:orientation="vertical" android:layout_width="match_parent"
    android:layout_height="match_parent">
    <ImageView android:layout_width="match_parent" android:layout_height="match_parent" android:src="@drawable/launch_screen" android:scaleType="centerCrop" />
</RelativeLayout>
```

### iOS    

Customize your splash screen via `LaunchScreen.storyboard` or `LaunchScreen.xib`。

Tutorial Video:



## Usage

Use like so:

```javascript
import SplashScreen from 'furkankaya-react-native-splash-screen';

const App = () => {

  useEffect(() => {
      SplashScreen.hide();
  }, []);
  
  return (
    ....
};
```

## API


| Method | Type     | Optional | Description                         |
|--------|----------|----------|-------------------------------------|
| show() | function | false    | Open splash screen (Native Method ) |
| hide() | function | false    | Close splash screen                 |


