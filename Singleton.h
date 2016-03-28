//
//  Singleton.h
//  testExtension
//
//  Created by beihaiSellshou on 9/22/15.
//  Copyright (c) 2015 beihaiSellshou. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
@interface Singleton : NSObject<CLLocationManagerDelegate>

@property (nonatomic, assign)CGFloat range;

+(void)registeriBeacon:(NSString *)uuid withMajor:(NSString *)major withRange:(CGFloat)range;
@end
