//
//  UCSTcpClient.h
//  ucstcplib
//
//  Created by FredZhang on 15-4-11.
//  Copyright (c) 2015年 ucpaas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UCSTcpClientDelegate.h"
#import "UCSTcpDefine.h"


/*!
 *  @brief UCSTcpClient是云之讯Tcp Sdk核心能力类，为IM、Voip等能力提供支持。
 */

@interface UCSTcpClient : NSObject

/*!
 *  @brief  实例化UCSTcpClient的一个单例对象
 
 *  @discussion 这个方法是生成UCSTcpClient的唯一方法，请不要使用init()等其他初始化方法，否知会出现未知的错误
 
 *  @return UCSTcpClient类型的单例对象
 */
+ (instancetype)sharedTcpClientManager;


/*!
 *  @brief  设置im能力的代理
 
 *  @discussion  如果需要使用IM能力，就必须设置。如果不需要，就不需要调用这个方法
 
 *  @param delegate im能力代理
 */
- (void)setIMDelegate:(id <UCSIMDelegate>)delegate;


/*!
 *  @brief  设置voip能力代理
 
 *  @discussion 如果需要使用voip能力，就必须设置。如果不需要，就不需要调用这个方法
 
 *
 *  @param delegate viop能力代理
 */
- (void)setVoipDelegate:(id <UCSVoipDelegate>)delegate;



/*!
 *  @brief  连接云平台.
 
 *  @discussion (注意: 除非是为了兼容旧的IMSDK,否则请使用这个登陆方式)。
 
 *  @param token        加密的token
 *  @param successBlock 成功回调
 *  @param errorBlock   失败回调
 */
- (void)login_connect:(NSString *)token
              success:(void (^)(NSString *userId))successBlock
                error:(void (^)(UCSErrorCode status))errorBlock;


/*!
 *  @brief 连接云平台.
 
 *  @discussion  (注意：这个登陆方式是为了兼容旧的IMSDK,后面可能会废弃)。 使用这个接口的唯一场景是: 用户已经在现有的app中集成了我们旧的IMSDK,并且不希望更改成新的登陆方式(云之讯建议你更改成新的登陆方式)。其他场景下，请使用新的登陆方式。
 
 *  @param accountSid   账号sid
 *  @param accountToken 账号token
 *  @param clientNumber clientNumber
 *  @param clientPwd    clientPwd
 *  @param successBlock 成功回调
 *  @param errorBlock   失败回调
 */
- (void)login_connect_old:(NSString *)accountSid
         withAccountToken:(NSString *)accountToken
         withClientNumber:(NSString *)clientNumber
            withClientPwd:(NSString *)clientPwd
                  success:(void (^)(NSString *userId))successBlock
                    error:(void (^)(UCSErrorCode status))errorBlock;


/*!
 *  @brief  查询客户端与云平台的连接状态
 
 *  @discussion
 *
 *  @return yes，已连接；no，断开连接
 */
- (BOOL)login_isConnected;


/*!
 *  @brief  断开客户端和云平台的连接
 *
 *  @discussion 在客户端不需要继续与云平台保持连接的时候，调用这个方法断开连接。断开连接后，客户端将不会在收到与云平台的消息推送，也无法发送消息到云平台。
            断开连接，不会影响APNS离线推送功能.
 *
 */
- (void)login_uninit;








#pragma mark 下面的方法只提供给上层SDK调用，开发者请忽略以下方法。

/*!
 *  @brief      忽略此方法
 
 *  @discussion 这个方法是TCPSDK提供给 IMSDK、VoipSDK调用的方法，开发者不需要关注这个方法，也不要在你的项目中调用这个方法
 
 *
 *  @param sendData
 *  @param modelType
 */
-(void)sendMessage:(NSData *)sendData modelType:(UCSTCPmodelType)modelType;

@end
