//
//  UCSDiscussionNotification.h
//  ucsimlib
//
//  Created by FredZhang on 15/5/23.
//  Copyright (c) 2015年 ucpaas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UCSMsgContent.h"

/*!
 @enum
 @brief 讨论组通知事件类型
 @constant UCSInviteDiscussionNotification        加入讨论组
 @constant UCSQuitDiscussionNotification          退出讨论组
 @constant UCSRenameDiscussionTitleNotification   修改讨论组名称
 @constant UCSRemoveDiscussionMemberNotification  移除讨论组成员
 @constant UCSbeRemoveFromDiscussionNotification  被移除
 @constant UCSSwichInvitationAccessNotification   开关成员邀请
 */
typedef enum{
    UCSInviteDiscussionNotification = 1,
    UCSQuitDiscussionNotification = 2,
    UCSRenameDiscussionTitleNotification = 3,
    UCSRemoveDiscussionMemberNotification = 4,
    UCSbeRemoveFromDiscussionNotification = 5,
    UCSSwichInvitationAccessNotification = 6
} UCSDiscussionNotificationType;




/*!
 *  @brief  讨论组通知类
 */
@interface UCSDiscussionNotification : UCSMsgContent

/*!
 *  @brief 讨论组通知事件类型
 */
@property(nonatomic, assign) UCSDiscussionNotificationType type;

/*!
 *  @brief  操作者id
 */
@property(nonatomic, copy) NSString *operatorId;

/*!
 *  @brief  扩展字段，用于存储服务器下发扩展信息
 */
@property(nonatomic, copy) NSString *extension;


@end
