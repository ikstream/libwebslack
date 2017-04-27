/*
 * libwebslack is library to use Slacks incoming webhooks in a C programm
 *
 * Copyright (C) 2017  Stefan Venz
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _LIBWEBSLACK_H_
#define _LIBWEBSLACK_H_

#define MAX_HOOK_LENGTH 512
#define MAX_CHANNEL_LENGTH 24
#define MAX_USER_LENGTH 21
#define MAX_TEXT_LENGTH 1024

struct team_info {
	char webhook_url[MAX_HOOK_LENGTH];
	char channel[MAX_CHANNEL_LENGTH];
	char username[21];
	char text[1024];
};

/*
 * set webhook to use
 * @teaminfo: team struct
 * @webhook_url: webhook url of your team to use
 * return 0 on success, else 1
 */
int set_webhook_url(struct team_info team_info, char *webhook_url);

/*
 * set channel to post to
 * channel names may only be 22 letters in length
 * @team_info: team struct
 * @channel: channel to post to
 * return 0 on success, else 1
 */
int set_channel(struct team_info team_info, char *channel);

/*
 * set the user name for a team struct
 * The username may only contain lowercase letters, numbers, hyphens,
 * periods and underscores
 * @team_info: team struct
 * @username: username to set
 * return 0 on success, else 1
 */
int set_username(struct team_info team_info, char *username);

/*
 * send message to team
 * @team_info: team to send to
 * @text: send this text
 * return ???? TODO
 */
int send_message(struct team_info team_info, char *text);

#endif

