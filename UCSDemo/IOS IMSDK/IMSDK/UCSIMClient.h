//
//  UCSIMClient.h
//  ucsimlib
//
//  Created by FredZhang on 15-4-7.
//  Copyright (c) 2015年 ucpaas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UCSIMClientDelegate.h"
#import "UCSConversation.h"
#import "UCSDiscussion.h"
#import "UCSMessage.h"
#import "UCSTextMsg.h"
#import "UCSImageMsg.h"
#import "UCSVoiceMsg.h"
#import "UCSUserInfo.h"
#import "UCSTcpClient.h"

/*!
 *  @brief  UCSIMClient 是IMSDK的核心能力类，提供所有的IM能力。使用im能力必须导入tcp sdk。
 */

@interface UCSIMClient : NSObject<UCSIMDelegate>


/*!
 *  @brief  实例化UCSIMClient单例对象
 
 *  @discussion 必须使用这个方法创建UCSIMClient对象,请不要使用init()等初始化方法，否知会出现错误。
 
 *  @return UCSIMClient的单例对象
 */
+ (instancetype)sharedIM;




/*!
 *  @brief  注册APNS推送 (暂时未开放这个功能,请忽略)
 
 *  @discussion 要开启离线推送,必须上传你的APP对应的推送证书，否知无效。
 
 *  @param deviceToken 运行设备的deviceToken
 */
+ (void)init:(NSString *)deviceToken;




/*!
 *  @brief  设置UCSIMClient的代理对象。
 
 *  @discussion 云之讯IM能力通过 UCSIMClientDelegate 中 didReceiveMessage: withData: 回调收到的消息。如果不设置，则无法接受聊天消息。
 *
 *  @param delegate 遵守UCSIMClientDelegate的对象
 */
- (void)setDelegate:(id <UCSIMClientDelegate>)delegate;



/*!
 *  @brief  发送一条聊天消息
 
 *  @discussion SDK所有的消息发送都使用这个方法，根据不同的参数来区分不同的消息类型。
 
 *  @param conversationType 这条消息对应的会话的类型。这个参数用来区分这条消息是什么场景下产生的。现在暂时有单聊、群聊、讨论组三中会话类型。比如一对一单聊,设为UCS_IM_SOLOCHAT。具体参考UCS_IM_ConversationType
 *  @param receiveId        聊天对象的id。这个参数用来标识这条消息发到哪里,单聊发给某个人,群聊发给某个讨论组或者某个群。单聊设置为对方的id,讨论组设置为讨论组id,群聊设置为群id。
 *  @param msgType          消息的类型。这个参数用来标识这条消息的类型。比如文本消息，设置为UCS_IM_TEXT。具体参考UCS_IM_MsgType
 *  @param content          消息实体。这个参数存储发送的内容。UCSMsgContent是一个消息基类，这里传入一个继承UCSMsgContent的子类的对象。比如发送文本消息时，传入UCSTextMsg类型的对象。注意:这里传的内容对象的类型必须和前一个参数msgType类型对应。比如不允许前一个参数传文本类型，后一个参数传图片，否知会出现错误。
 *  @param progress         这个参数暂时不使用。请传一个空白的block,不要传nil或者null
 *  @param success          发送消息成功的Block回调。回调中会返回发送成功的消息id,拿到这个id可以做一些自定义的处理。比如刷新消息的发送状态。
 *  @param error            发送消息失败的Block回调。回调中会返回发送失败的消息id和发送失败的错误码，自定义处理。
 *
 *  @return 发送的message。此时消息的发送状态为发送中，需要根据success回调和error回调来改变消息的发送状态。
 */
- (UCSMessage *)sendMessage:(UCS_IM_ConversationType)conversationType
                  receiveId:(NSString *)receiveId
                    msgType:(UCS_IM_MsgType)msgType
                    content:(UCSMsgContent *)content
                   progress:(void (^)(int nProgress))progress
                    success:(void (^)(long long messageId))success
                      error:(void (^)(UCSErrorCode nErrorCode, long long messageId))error;


#pragma mark 讨论组相关

/*!
 *  @brief 主动创建一个讨论组
 
 *  @discussion 这个方法用来主动创建一个讨论组。成功block回调返回一个讨论组,失败block回调返回错误码。创建成功后，创建者会自动变成讨论组的所有者，拥有对讨论组操作的最高权限。
 
 *  @param topic       创建后的讨论组主题(讨论组名),如果不传，讨论组名称就为空。
 *  @param memberArray 创建时需要邀请到讨论组的成员数组(不需要把自己加进去),数组中每个元素为UCSUserInfo类的对象。
 *  @param success     创建成功。block回调返回创建成功的讨论组
 *  @param error       创建失败。block回调返回错误码。
 */
- (void)createDiscussionWithTopic:(NSString *)topic
                      memberArray:(NSArray *)memberArray
                          success:(void (^)(UCSDiscussion *discussion))success
                            error:(void (^)(UCSErrorCode status))error;

/*!
 *  @brief 给已经存在的讨论组添加新的用户
 
 *  @discussion  这个方法用来给一个已经存在的讨论组添加新的成员，如果用户无权限进行操作会失败。
 
 *  @param discussionId 讨论组id
 *  @param memberArray  要新加的成员的数组，数组中的每个元素为UCSUserInfo类的对象。
 *  @param success      添加成功.回调中返回修改后的讨论组
 *  @param error        添加失败.回调中返回错误码
 */
- (void)addMemberToDiscussionWithDiscussionId:(NSString *)discussionId
                                  memberArray:(NSArray *)memberArray
                                      success:(void (^)(UCSDiscussion *discussion))success
                                        error:(void (^)(UCSErrorCode status))error;


/*!
 *  @brief 在讨论组中移除已经存在的用户
 
 *  @discussion 这个方法用来删除一个存在的讨论组中存在的成员,如果用户无权限进行操作会失败。
 
 *  @param discussionId 讨论组id
 *  @param memberArray  要移除的用户的数组，数组中的每个元素为UCSUserInfo类的对象。
 *  @param success      移除成功.回调中返回修改后的讨论组
 *  @param error        移除失败.回调中返回错误码
 */
- (void)removeMemberFromDiscussionWithDiscussionId:(NSString *)discussionId
                                       memberArray:(NSArray *)memberArray
                                           success:(void (^)(UCSDiscussion *discussion))success
                                             error:(void (^)(UCSErrorCode status))error;


/*!
 *  @brief 主动退出讨论组
 *
 *  @param discussionId 讨论组id
 *  @param success      退出成功
 *  @param error        退出失败。回调中返回错误码
 */
- (void)quitDiscussionWithDiscussionId:(NSString *)discussionId
                               success:(void (^)(UCSDiscussion *discussion))success
                                 error:(void (^)(UCSErrorCode status))error;


/*!
 *  @brief 修改讨论组的主题(讨论组名称)
 *
 *  @param discussionId 讨论组id
 *  @param newTopic     新的主题
 *  @param success      修改成功。回调中返回修改后的讨论组。
 *  @param errorBlock   修改失败。回调中返回失败的错误码
 */
- (void)setDiscussionTopicWithDiscussionId:(NSString *)discussionId
                                  newTopic:(NSString *)newTopic
                                   success:(void (^)(UCSDiscussion *discussion))success
                                     error:(void (^)(UCSErrorCode status))errorBlock;


/*!
 *  @brief 获取一个存在的讨论组
 
 *  @param targetId 讨论组id
 *
 *  @return 讨论组
 */
- (UCSDiscussion *)getDiscussionInfoWithDiscussionId:(NSString *)targetId;


#pragma mark 数据相关操作

/*!
 *  @brief 获取会话列表
 
 *  @param conversationTypeList 会话类型的数组。如果需要获取单聊的会话,这个参数设置为@[@1];获取群聊的会话，设置为@[@2];获取讨论组的会话，设置为@[@3].如果需要获取所有会话，可设置为@[@1,@2,@3]
 *
 *  @return 会话数组，每个元素是一个UCSConversation对象
 */
- (NSArray *)getConversationList:(NSArray *)conversationTypeList;


/*!
 *  @brief 在会话列表中移除一个会话，但是不会删除该会话在数据库中的消息。
 *
 *  @param conversationType 会话类型。类型值参考UCS_IM_ConversationType
 *  @param targetId         会话id
 *
 *  @return 操作结果的bool值
 */
- (BOOL)removeConversation:(UCS_IM_ConversationType)conversationType
                  targetId:(NSString *)targetId;



/*!
 *  @brief 清空某一个会话所有的聊天记录
 *
 *  @param conversationType  会话类型。类型值参考UCS_IM_ConversationType
 *  @param targetId          会话id
 *
 *  @return 操作结果的bool值
 */
- (BOOL)clearMessages:(UCS_IM_ConversationType)conversationType
             targetId:(NSString *)targetId;


/*!
 *  @brief 清空会话列表
 
 *  @discussion 这个方法是用来清空会话列表，注意和clearMessages:targetId:这个方法区分开来。
 
 *  @return 操作结果的bool值
 */
- (BOOL)clearConversations;

#pragma mark 获取或者删除消息相关

/*!
 *  @brief 获取最新的消息.用于进入聊天界面后第一次加载消息
 
 *  @discussion 这个方法用于进入聊天界面第一次加载消息时候调用,如果下拉加载更多消息的时候请使用下面的 -getLatestMessages:targetId:count: 方法
 
 *  @param conversationType 会话类型。类型值参考UCS_IM_ConversationType
 *  @param targetId         会话id
 *  @param count            需要获取的消息数量。默认获取10条。也可以自己设置,如果该会话的消息总数小于设置的count数，则返回该会话的消息总数。
 *
 *  @return 消息数组。数组中元素的类型是
 */
- (NSArray *)getLatestMessages:(UCS_IM_ConversationType)conversationType
                      targetId:(NSString *)targetId
                         count:(int)count;


/*!
 *  @brief 获取更多的消息。用于聊天界面中加载更多消息。
 
 *  @discussion 这个方法用于聊天界面中下拉加载更多消息时候调用。进入聊天界面第一次加载消息请使用上面的 - getLatestMessages:targetId:count: 方法。
 
 *  @param conversationType 会话类型。类型值参考UCS_IM_ConversationType
 *  @param targetId         会话id
 *  @param oldestMessageId  当前已经请求好的消息中最早的那条消息的消息id。
 *  @param count            需要获取的消息数量
 *
 *  @return 消息数组
 */
- (NSArray *)getHistoryMessages:(UCS_IM_ConversationType)conversationType
                       targetId:(NSString *)targetId
                oldestMessageId:(long long)oldestMessageId
                          count:(int)count;


/*!
 *  @brief 删除一条指定的消息
 
 *  @discussion 这个方法一般用于聊天界面删除一条消息，删除后这条消息在数据库中也会被删除。
 
 *  @param conversationType 会话类型。类型值参考UCS_IM_ConversationType
 *  @param targetId         会话id
 *  @param messageId        消息id
 *
 *  @return 操作结果的bool值
 */
- (BOOL)deleteMessages:(UCS_IM_ConversationType)conversationType
              targetId:(NSString *)targetId
             messageId:(long long)messageId;



#pragma mark 未读消息相关


/*!
 *  @brief 获取某个会话的未读消息数
 
 *  @discussion 这个方法用来获取某个会话的未读消息数，提醒用户有未读的消息
 
 *  @param conversationType 会话类型。类型值参考UCS_IM_ConversationType
 *  @param targetId         会话id
 *
 *  @return 未读消息数量
 */
- (int)getUnreadCount:(UCS_IM_ConversationType)conversationType
             targetId:(NSString *)targetId;


/*!
 *  @brief 获取所有会话的未读消息总数
 *
 *  @return 未读消息总数
 */
- (int)getTotalUnreadCount;


/*!
 *  @brief 清空某个会话的未读消息总数
 *
 *  @param conversationType 会话类型。类型值参考UCS_IM_ConversationType
 *  @param targetId         会话id
 *
 *  @return 操作结果的bool值
 */
- (BOOL)clearConversationsUnreadCount:(UCS_IM_ConversationType)conversationType
                             targetId:(NSString *)targetId;

#pragma mark 查询消息相关

/*!
 *  @brief 根据关键字查询某个会话的聊天记录
 *
 *  @param conversationType 会话类型。类型值参考UCS_IM_ConversationType
 *  @param targetId         会话id
 *  @param keyWord          关键字
 *
 *  @return 查询结果。数组中的每个元素是一个UCSMessage对象
 */
- (NSArray *)checkChatMessages:(UCS_IM_ConversationType)conversationType
                      targetId:(NSString *)targetId
                       keyWord:(NSString *)keyWord;

#pragma mark 草稿相关
/*!
 *  @brief 获取某个会话的文本草稿
 *
 *  @param conversationType 会话类型。类型值参考UCS_IM_ConversationType
 *  @param targetId         会话id
 *
 *  @return 文本草稿。如果没有，为空。
 */
- (NSString *)getTextMessageDraft:(UCS_IM_ConversationType)conversationType
                         targetId:(NSString *)targetId;


/*!
 *  @brief 保存某个会话的文本草稿
 *
 *  @param conversationType 会话类型。类型值参考UCS_IM_ConversationType
 *  @param targetId         会话id
 *  @param content          文本草稿
 *
 *  @return 操作结果的bool值
 */
- (BOOL)saveTextMessageDraft:(UCS_IM_ConversationType)conversationType
                    targetId:(NSString *)targetId
                     content:(NSString *)content;


/*!
 *  @brief 清除某个会话的文本草稿
 *
 *  @param conversationType 会话类型。类型值参考UCS_IM_ConversationType
 *  @param targetId         会话id
 *
 *  @return 操作结果的bool值
 */
- (BOOL)clearTextMessageDraft:(UCS_IM_ConversationType)conversationType
                     targetId:(NSString *)targetId;


#pragma mark 置顶相关
/*!
 *  @brief 会话列表中,设置某条会话的置顶状态
 *
 *  @param conversationType 会话类型。类型值参考UCS_IM_ConversationType
 *  @param targetId          会话id
 *  @param isTop            yes 置顶 , no 取消置顶
 *
 *  @return 操作结果的bool值
 */
- (BOOL)setConversationToTop:(UCS_IM_ConversationType)conversationType
                    targetId:(NSString *)targetId
                       isTop:(BOOL)isTop;


/*!
 *  @brief 设置接收到的某条消息在本地的接收状态。具体参考UCSReceivedStatus
 *
 *  @param conversationType 会话类型。类型值参考UCS_IM_ConversationType
 *  @param targetId          会话id
 *  @param messageId        消息id
 *  @param receivedStatus   要设置的状态
 *
 *  @return 操作结果的bool值
 */
-(BOOL)setMessageReceivedStatus:(UCS_IM_ConversationType)conversationType
                       targetId:(NSString *)targetId
                      messageId:(long long)messageId
                 receivedStatus:(UCSReceivedStatus)receivedStatus;



@end
