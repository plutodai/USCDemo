//
//  UCSIMClientDelegate.h
//  ucsimlib
//
//  Created by FredZhang on 15-4-7.
//  Copyright (c) 2015年 ucpaas. All rights reserved.
//

#ifndef ucsimlib_UCSIMClientDelegate_h
#define ucsimlib_UCSIMClientDelegate_h
#import "UCSIMDefine.h"
#import "UCSTcpDefine.h"

/*!
 *  @brief  收到服务器消息和错误的回调
 */

@protocol UCSIMClientDelegate<NSObject>

/*!
 *  @brief  收到服务器推送的消息时回调
 *
 *  @param errorCode 错误码。具体参考UCSErrorCode
 *  @param msgIdArr  消息数组。数组中每一个元素是一个UCSMessage对象
 */
- (void)didReceiveMessage:(UCSErrorCode) errorCode withData:(NSArray*)msgArr;


/*!
 *  @brief  和服务器的连接出现错误时回调
 *
 *  @param errorCode 错误码
 */
- (void)didReceiveServerError:(UCSErrorCode) errorCode;

@end
#endif
