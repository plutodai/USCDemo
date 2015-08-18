//
//  UCSVoiceMsg.h
//  ucsimlib
//
//  Created by FredZhang on 15/5/5.
//  Copyright (c) 2015年 ucpaas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UCSMsgContent.h"


/*!
 *  @brief  语音消息类型，继承UCSMsgContent
 */
@interface UCSVoiceMsg : UCSMsgContent

/*!
 *  @brief  wav格式的data
 */
@property(nonatomic, strong) NSData *wavAudioData;

/*!
 *  @brief  语音的本地路径。
 */
@property(nonatomic, copy) NSString *voicePath;

/*!
 *  @brief  语音时长
 */
@property(nonatomic, assign) long duration;

/*!
 *  @brief  附加信息
 */
@property(nonatomic, copy) NSString *extra;

@end
