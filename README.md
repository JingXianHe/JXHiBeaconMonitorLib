# JXHiBeaconMonitorLib
iBeacon Monitor, send notification when enter or exit iBeacon region, custom region range! 
JXHiBeaconMonitorLib is very useful static library. It monitors iBeacons region. With it you can easily know when you enter or exit a iBeacon region and do some programming about those events.

How to use it?

1. Download JXHiBeaconMonitorLib.a and Singleton.h and drag them into your project.
2. Import CoreLocation.framework.
3. In your AppDelegate.m, import "Singleton.h".
4. Within didFinishLaunchingWithOptions function, just type: 
[Singleton registeriBeacon:@"FDA50693-A4E2-4FB1-AFCF-C6EB07647825" withMajor:@"10002" withRange:5.0];

Done! I will explain those parameters one by one. The first one is uuid, the second one is major number and the last one is range.

How to receive the exit and enter zone notification?
For example, you want to receive the nofification in UiviewController. In viewDidLoad, you may add two Observers.

1. [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(enterZone:) name:@"JXHiBeaconEnterRegion" object:nil];
    
2. [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(exitzone:) name:@"JXHiBeaconExitRegion" object:nil];

enterZone:is the function you wanna trigger when you enter the region and exitzone: is the function would be triggered when you exit the zone. The function would look like this. minorNum is the minor number of the iBeacon that you are entering its region. exitzone: function would be the same.

- (void)enterZone:(NSNotification *)notification {
    NSNumber *minorNum = (NSNumber *)notification.object;
    NSLog(@"%d", minorNum.intValue);
}


PS: Don't forget to remove observers.
- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

JXHiBeaconMonitorLib works on iOS 7.0 and above. To use CoreLocation.framework, you need to add NSLocationAlwaysUsageDescription in your plist.

Thanks gus, if you have any suggestion or advice, please let me know! Stay awesome.
