//
//  UCSConversation.h
//  ucsimlib
//
//  Created by FredZhang on 15/5/5.
//  Copyright (c) 2015年 ucpaas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UCSMsgContent.h"
#import "UCSConversation.h"
#import "UCSIMDefine.h"

/*!
 *  @brief  会话类，每一个会话对应一个聊天
 */

@interface UCSConversation : NSObject


/*!
*  @brief  会话类型。单聊会话、讨论组会话、群会话
*/
@property(nonatomic, assign) UCS_IM_ConversationType conversationType;


/*!
 *  @brief  会话 Id
 */
@property(nonatomic, copy) NSString *targetId;


/*!
 *  @brief  会话名称
 */
@property(nonatomic, copy) NSString *conversationTitle;


/*!
 *  @brief  会话中未读消息数
 */
@property(nonatomic, assign) NSInteger unreadMessageCount;


/*!
 *  @brief  当前会话是否置顶
 */
@property(nonatomic, assign) BOOL isTop;


/*!
 *  @brief  消息接收状态
 */
@property(nonatomic, assign) UCSReceivedStatus receivedStatus;


/*!
 *  @brief  消息发送状态
 */
@property(nonatomic, assign) UCSSendStatus sentStatus;


/*!
 *  @brief  消息接收时间
 */
@property(nonatomic, assign) long long receivedTime;


/*!
 *  @brief  消息发送时间
 */
@property(nonatomic, assign) long long sentTime;


/*!
 *  @brief  消息草稿，尚未发送的消息内容
 */
@property(nonatomic, copy) NSString *draft;

/*!
 *  @brief  会话实体名
 */
@property(nonatomic, copy) NSString *objectName;


 /*!
 *  @brief  发送消息用户Id
 */
@property(nonatomic, copy) NSString *senderUserId;


/*!
 *  @brief   发送消息用户名
 */
@property(nonatomic, copy) NSString *senderUserName;


/*!
 *  @brief  当前会话最近一条消息Id
 */
@property(nonatomic, assign) long long lastestMessageId;


/*!
 *  @brief  当前会话最近一条消息实体
 */
@property(nonatomic, strong) UCSMsgContent *lastestMessage;


@end
