//
//  UCSImageMsg.h
//  ucsimlib
//
//  Created by FredZhang on 15/5/5.
//  Copyright (c) 2015年 ucpaas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UCSMsgContent.h"


/*!
 *  @brief  图片消息类型，继承UCSMsgContent
 */
@interface UCSImageMsg : UCSMsgContent


/*!
 *  @brief  缩略图本地路径
 */
@property(nonatomic, copy) NSString *thumbnailLocalPath;

/*!
 *  @brief  大图的远程url。自己发送的图片消息，这个字段为空。
 */
@property(nonatomic, copy) NSString *imageRemoteUrl;

/*!
 *  @brief  大图的本地路径。收到的图片消息，这个字段为空。
 */
@property(nonatomic, copy) NSString *imageLocalPath;

/*!
 *  @brief  原始图
 */
@property(nonatomic, strong) UIImage *originalImage;

/*!
 *  @brief  附加信息
 */
@property(nonatomic, strong) NSString *extra;

@end
