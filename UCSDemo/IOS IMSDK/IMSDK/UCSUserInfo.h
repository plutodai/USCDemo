//
//  UCSUserInfo.h
//  ucsimlib
//
//  Created by FredZhang on 15/5/5.
//  Copyright (c) 2015年 ucpaas. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 *  @brief  用户信息类型
 */
@interface UCSUserInfo : NSObject

/*!
 *  @brief  用户ID
 */
@property(nonatomic, copy) NSString *userId;

/*!
 *  @brief  用户名
 */
@property(nonatomic, copy) NSString *name;

/*!
 *  @brief  头像URL
 */
@property(nonatomic, copy) NSString *portraitUri;

@end
