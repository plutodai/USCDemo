//
//  UCSTcpDefine.h
//  ucsimlib
//
//  Created by FredZhang on 15/5/5.
//  Copyright (c) 2015年 ucpaas. All rights reserved.
//

#ifndef ucsimlib_UCSTcpDefine_h
#define ucsimlib_UCSTcpDefine_h

typedef enum
{
    UCSIM = 1,
    UCSVoip = 2,
}UCSTCPmodelType;



/*!
 @enum
 @brief    登陆的方式
 @constant UCS_ClientLogin      账号登陆，旧的登陆方式
 @constant UCS_TokenLogin       token登陆，新的登陆方式
 */
typedef enum
{
    /** 账号密码登陆 */
    UCS_ClientLogin = 1,
    
    /** token登陆 */
    UCS_TokenLogin = 2,
}UCSTCPLoginType;



/*!
 @enum
 @brief    错误码
 @constant ErrorCode_NoError      没有错误
 @constant ErrorCode_UnKnown      未知错误
 @constant ErrorCode_ConnectToServerFail       连接服务器失败
 @constant ErrorCode_TIMEOUT        连接超时
 @constant ErrorCode_BeClicked      被别人踢下线
 @constant ErrorCode_InvalidToken      无效的token或者与appid不符合
 @constant ErrorCode_InvalidUser       用户不存在
 @constant ErrorCode_IncorrectPassword      密码错误
 @constant ErrorCode_InvalidMessage       无效的消息
 @constant ErrorCode_InvalidGroud      无效的群组
 @constant ErrorCode_InvalidDiscussion       无效的讨论组
 @constant ErrorCode_UpdateDiscussionNameFail      修改讨论组名字失败
 @constant ErrorCode_CreateDiscussionFail       创建讨论组失败
 @constant ErrorCode_MemberIsNotInGroud      用户不在群组中
 @constant ErrorCode_MemberIsNotInDiscussion       用户不在讨论组中
 @constant ErrorCode_DeleteMemberFail      删除成员失败
 @constant ErrorCode_AddMemberFail       邀请成员失败
 @constant ErrorCode_UploadFileFail      文件上传失败
 @constant ErrorCode_downLoadFileFail       文件下载失败
 @constant ErrorCode_RecoderTooShort      录音时间过短
 @constant ErrorCode_FileFormatIsNotSupported       文件格式不支持
 @constant ErrorCode_MessageLengthTooLong      消息内容过长
 @constant ErrorCode_SelectFromDataBaseFail      读取本地数据库失败
 @constant ErrorCode_UpdateDataBaseFail     写入、更新数据库失败
 @constant ErrorCode_SendMessageFail       消息发送失败
 @constant ErrorCode_SendMessageTimeOut    消息发送超时
 @constant ErrorCode_MembersError          成员列表错误
 @constant ErrorCode_ExitDiscussionError    退出讨论组错误
 @constant ErrorCode_MethodParamError       方法参数错误
 @constant ErrorCode_MessageTypeError      消息格式错误
 @constant ErrorCode_NetworkIsNotConnected       网络未连接
 @constant ErrorCode_InitError      初始化加载失败(包括数据库加载)
 */
typedef enum
{
    
    /**    没有错误  */
    ErrorCode_NoError = 400000,
    
    /**   未知错误 */
    ErrorCode_UnKnown = 401000,
    
    /**   连接服务器失败 */
    ErrorCode_ConnectToServerFail = 401100,
    
    /**   超时 */
    ErrorCode_TIMEOUT = 401101,
    
    /**  被别人踢下线 */
    ErrorCode_BeClicked = 4001102,
    
    /**  无效的token或者与appid不符合 */
    ErrorCode_InvalidToken = 4001103,
    
    /**    用户不存在 */
    ErrorCode_InvalidUser = 4001104,
    
    /**   密码错误 */
    ErrorCode_IncorrectPassword = 4001105,
    
    /**   无效的消息，null或者nil  */
    ErrorCode_InvalidMessage = 4023000,
    
    /**    无效的群组,传入的群组不存在 */
    ErrorCode_InvalidGroud = 402301,
    
    /**    无效的讨论组,传入的讨论组不存在 */
    ErrorCode_InvalidDiscussion = 402302,
    
    /**    修改讨论组名字失败*/
    ErrorCode_UpdateDiscussionNameFail = 402303,
    
    /**    创建讨论组失败  */
    ErrorCode_CreateDiscussionFail = 402304,
    
    /**    用户不在群组中  */
    ErrorCode_MemberIsNotInGroud = 402305,
    
    /**    用户不在讨论组中 */
    ErrorCode_MemberIsNotInDiscussion = 402306,
    
    /**    删除成员失败 */
    ErrorCode_DeleteMemberFail = 402307,
    
    /**    邀请成员失败 */
    ErrorCode_AddMemberFail = 402308,
    
    /**    文件上传失败  */
    ErrorCode_UploadFileFail = 402309,
    
    /**    文件下载失败   */
    ErrorCode_downLoadFileFail = 402310,
    
    /**    录音时间过短*/
    ErrorCode_RecoderTooShort = 402311,
    
    /**    文件格式不支持  */
    ErrorCode_FileFormatIsNotSupported = 402312,
    
    /**    消息内容过长 */
    ErrorCode_MessageLengthTooLong = 402313,
    
    /**    读取本地数据库失败 */
    ErrorCode_SelectFromDataBaseFail = 402314,
    
    /**    写入、更新数据库失败   */
    ErrorCode_UpdateDataBaseFail = 402315,
    
    
    /**    发送消息失败 */
    ErrorCode_SendMessageFail = 402316,
    
    /**    消息发送超时 */
    ErrorCode_SendMessageTimeOut = 402317,
    
    /**    成员列表错误  */
    ErrorCode_MembersError = 402318,
    
    /**    退出讨论组错误 */
    ErrorCode_ExitDiscussionError = 402319,    
    
    /**    方法参数错误(参数格式不对,参数不符合方法要求，空值等) */
    ErrorCode_MethodParamError = 403600,
    
    /**    消息格式错误   */
    ErrorCode_MessageTypeError = 403601,
    
    /**    网络未连接  */
    ErrorCode_NetworkIsNotConnected = 403602,
    
    /**    初始化加载失败(包括数据库加载) */
    ErrorCode_InitError = 403603,
    
}UCSErrorCode;





#endif
