//
//  UCSDiscussion.h
//  ucsimlib
//
//  Created by FredZhang on 15/5/5.
//  Copyright (c) 2015年 ucpaas. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 *  @brief  讨论组类型
 */

@interface UCSDiscussion : NSObject

/*!
 *  @brief  讨论组ID
 */
@property(nonatomic, copy) NSString *discussionId;

/*!
 *  @brief  讨论组名称
 */
@property(nonatomic, copy) NSString *discussionName;

/*!
 *  @brief  创建讨论组用户ID 
 */
@property(nonatomic, copy) NSString *creatorId;

/*!
 *  @brief  会话类型
 */
@property(nonatomic, assign) UCS_IM_ConversationType conversationType;

/*!
 *  @brief  讨论组成员ID列表
 */
@property(nonatomic, strong) NSArray *memberIdList;

/*!
 *  @brief  是否开放成员邀请 0表示开放，1表示关闭
 */
@property(nonatomic, assign) int inviteStatus;

/*!
 *  @brief  是否推送消息通知 0表示开放，1表示关闭
 */
@property(nonatomic, assign) int pushMessageNotificationStatus;

/*!
 *  @brief  附加字段
 */
@property(nonatomic, copy) NSString *extra;

@end
