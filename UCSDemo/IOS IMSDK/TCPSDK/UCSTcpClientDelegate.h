//
//  UCSTcpClientDelegate.h
//  ucsimlib
//
//  Created by FredZhang on 15-4-7.
//  Copyright (c) 2015年 ucpaas. All rights reserved.
//


#ifndef ucsimlib_UCSTcpClientDelegate_h
#define ucsimlib_UCSTcpClientDelegate_h
#import "UCSTcpDefine.h"

/*!
 *  @brief  这个类是回调事件给IMSDK和VoipSDK的,开发者不要关注这个类，也不要使用这个类的任何方法。请忽略这个类。
 */

@protocol UCSIMDelegate<NSObject>

/*!
 *  @brief  连接成功时回调
 */
- (void)didImConnectServerSuccess:(NSString *)userId
                     withLoginType:(UCSTCPLoginType)loginType
                  withClientNumber:(NSString *)clientNumber
                         withPhone:(NSString *)phone;

/*!
 *  @brief  收到服务器的数据时回调
 */
- (void)didImReceiveMessage:(UCSErrorCode) errorCode
                   withData:(NSData *)reciveData;


/*!
 *  @brief  收到服务器的错误时回调
 */
- (void)didImReceiveServerError:(UCSErrorCode) errorCode;

@end



@protocol UCSVoipDelegate<NSObject>

/*!
 *  @brief  连接成功时回调
 */
- (void)didVoipConnectServerSuccess:(NSString *)userId
                      withLoginType:(UCSTCPLoginType)loginType
                   withClientNumber:(NSString *)clientNumber
                          withPhone:(NSString *)phone;

/*!
 *  @brief  收到服务器过来的数据回调
 */
- (void)didVoipReceiveMessage:(UCSErrorCode) errorCode
                     withData:(NSData *)reciveData;

/*!
 *  @brief  收到服务器的错误时回调
 */
- (void)didVoipReceiveServerError:(UCSErrorCode) errorCode;


@end
#endif
