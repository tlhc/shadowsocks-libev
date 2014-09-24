/*
 * server.c - Define the config data structure
 *
 * Copyright (C) 2013 - 2014, Max Lv <max.c.lv@gmail.com>
 *
 * This file is part of the shadowsocks-libev.
 * shadowsocks-libev is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * shadowsocks-libev is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with pdnsd; see the file COPYING. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef _JCONF_H
#define _JCONF_H

#define MAX_REMOTE_NUM 10
#define MAX_CONF_SIZE 16 * 1024
#define DNS_THREAD_NUM 32
#define MAX_UDP_CONN_NUM 4096

typedef struct
{
    char *host;
    char *port;
} ss_addr_t;

typedef struct
{
    int  remote_num;
    ss_addr_t remote_addr[MAX_REMOTE_NUM];
    char *remote_port;
    char *local_addr;
    char *local_port;
    char *password;
    char *method;
    char *timeout;
    int  fast_open;
    int  nofile;
} jconf_t;

jconf_t *read_jconf(const char* file);
jconf_t *read_server_jconf(const char* file, int *num);
void parse_addr(const char *str, ss_addr_t *addr);
void free_addr(ss_addr_t *addr);

#endif // _JCONF_H
