//
//  UCSMessage.h
//  ucsimlib
//
//  Created by FredZhang on 15/5/5.
//  Copyright (c) 2015年 ucpaas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UCSMsgContent.h"
#import "UCSIMDefine.h"

/*!
 *   @brief  IM消息元数据,用于描述消息的所有信息
 */

@interface UCSMessage : NSObject

/*!
 *  @brief  消息对应的会话类型。单聊会话、讨论组会话、群会话
 */
@property(nonatomic, assign) UCS_IM_ConversationType conversationType;

/*!
 *  @brief  消息的类型。文本、语音、图片、通知等
 */
@property(nonatomic, assign) UCS_IM_MsgType messageType;

/*!
 *  @brief  目标ID，如讨论组ID, 群ID
 */
@property(nonatomic, copy) NSString *receiveId;

/*!
 *  @brief  消息ID
 */
@property(nonatomic, assign) long long messageId;

/*!
 *  @brief  消息方向
 */
@property(nonatomic, assign) UCSMessageDirection messageDirection;

/*!
 *  @brief  发送者ID
 */
@property(nonatomic, copy) NSString *senderUserId;

/*!
 *  @brief  发送者昵称
 */
@property(nonatomic, copy) NSString *senderNickName;

/*!
 *   @brief  接受状态
 */
@property(nonatomic, assign) UCSReceivedStatus receivedStatus;

/*!
 *  @brief  发送状态
 */
@property(nonatomic, assign) UCSSendStatus sentStatus;

/*!
 *  @brief  接收时间
 */
@property(nonatomic, assign) long long receivedTime;

/*!
 *  @brief  发送时间
 */
@property(nonatomic, assign) long long sentTime;

/*!
 *  @brief  消息体名称
 */
@property(nonatomic, copy) NSString *objectName;

/*!
 *  @brief  消息内容
 */
@property(nonatomic, strong) UCSMsgContent *content;

/*!
 *  @brief  附加字段
 */
@property(nonatomic, copy) NSString *extra;



@end
