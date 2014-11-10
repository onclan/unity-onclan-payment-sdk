//
//  APIConfig.h
//  AppotaMessager
//
//  Created by ToanDK on 3/17/14.
//  Copyright (c) 2014 ToanDK. All rights reserved.
//

#ifndef AppotaMessager_APIConfig_h
#define AppotaMessager_APIConfig_h

// -------------------------------//
#pragma mark APP_SETTING
#define APP_NAME                    @"AppotaMessager"
#define APP_VERSION                 @"1.0.0"
#define APP_BUILD_INDEX             @"1"
#define API_VERSION @"1.1"

#define CONTENT_CLIENT              @"appstorevn_app"
#define CLIENT_ID                   @"f0621002b887b08594affaea18a046db052a2d445"
#define CLIENT_SECRET               @"b7d5af990e868f5bcc30ed33d793c666052a2d445"
#define CLIENT_API_KEY              @"28f6f078da0626594b5e439fe0ed6688052a2d445"
#define REDIRECT_URI                @"https://app.appota.com/account/redirect"

#define OC_API_SECRET_KEY           @"onCLaN@51yy8g81Vn4hmzhcpCwSlt3N@AppOTA"

#define DEBUG_ACCESS_TOKEN          [OCSDKSettingController sharedInstance].ocAccessToken
//87014646e1c16fe6c73ef60cea8d1a11053ba3d03 //token test sdk
//e08b98a5f1d4fc54a47f85143df13b4705327b2ac //token test onclan
//-------------------------------------//
#define SOCIAL_SUBSCRIPTION_GET_LIST @"https://app.appota.com/users/me/subscriptions?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_USER_FEED2 @"https://app.appota.com/users/%@/wall?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_NOTIFICATION_GET_LIST2 @"https://app.appota.com/users/%@/notifications?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_NOTIFICATION_MARK_SEEN2 @"https://app.appota.com/notifications/%@?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_NOTIFICATION_MARK_SEEN_ALL @"https://app.appota.com/users/me/notifications?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_CHAT_INIT2 @"https://app.appota.com/users/%@/chat?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_CHAT_INFO @"https://app.appota.com/chat/%@?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_CHAT_GAME_INFO @"https://app.appota.com/games/%@/chat?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define CHAT_WITH_ALIAS @"https://app.appota.com/alias/%@/chat?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define CHAT_RECENT @"https://app.appota.com/chat/recents?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"

#define CHAT_ON_OFF_NOTIFICATION @"https://app.appota.com/chat/%@/notifications?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"

#define USER_BASIC_INFO2 @"https://app.appota.com/users/%@?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"

#define SOCIAL_CHAT_LIST_FRIEND @"https://app.appota.com/chat/buddies?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_CHAT_LIST_RECENT @"https://app.appota.com/chat/recents?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_CHAT_LIST_GROUPS @"https://app.appota.com/chat/groups?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_CHAT_TOPIC_USERS @"https://app.appota.com/chat/%@/users?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_CLAN_MEMBERS @"https://app.appota.com/clans/%@/members?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_CHAT_TOPIC_HISTORY @"https://app.appota.com/chat/%@/history?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_CHAT_CLAN_HISTORY @"https://app.appota.com/clans/%@/chat_history?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_CHAT_PUBLIC_GROUPS @"https://app.appota.com/chat/public_groups?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_CHAT_ROOM_CATEGORY @"https://app.appota.com/chat/rooms?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_CHAT_ROOM_LIST @"https://app.appota.com/chat/rooms/%@/groups?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_CHAT_UNREAD_TOPICS @"https://app.appota.com/chat/unread?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_CHAT_MY_STICKERS @"https://app.appota.com/users/me/stickers?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_STICKER_LIST_FROM_STICKER @"https://app.appota.com/chat/stickers/%@?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_STICKER_LIST_FROM_EMOJI @"https://app.appota.com/chat/stickers?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"

#define SOCIAL_LIST_USER_PHOTO @"https://app.appota.com/users/%@/photos?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_GAME_CLAN @"https://app.appota.com/games/%@/clans?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_PHOTO_UPLOAD @"https://app.appota.com/photo/upload?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_CHAT_UPLOAD @"https://app.appota.com/chat/%@/attachments?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
#define SOCIAL_GAME_PLAYER @"https://app.appota.com/v1.1/games/%@/players?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define SOCIAL_GAME_FOLLOWER @"https://app.appota.com/games/%@/followers?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"

#define SOCIAL_LIST_LEADERBOARD_OF_GAME @"https://app.appota.com/v1.1/games/%@/leaderboards?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define SOCIAL_LIST_LEADERBOARD_OVERALL @"https://app.appota.com/v1.1/games/%@/leaderboards/%@/players?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define SOCIAL_LIST_LEADERBOARD_FRIENDS @"https://app.appota.com/v1.1/games/%@/leaderboards/%@/friends?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define SOCIAL_LEADERBOARD_POST_SCORE @"https://app.appota.com/v1.1/games/%@/leaderboards/%@?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"

#define USER_LOGOUT @"https://app.appota.com/account/logout?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>&v=<VERSION>"
//search
#define SOCIAL_SEARCH_PLAYER_OF_GAME @"https://app.appota.com/v1.1/games/%@/search_players?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define SOCIAL_SEARCH_CLAN_OF_GAME @"https://app.appota.com/search/clans?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"

#define SOCIAL_PHOTO_IMAGE_UPLOAD @"https://app.appota.com/v1.1/games/%@/photos?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define SOCIAL_LIST_CLAN_OF_USER @"https://app.appota.com/users/%@/clans?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"

#endif
