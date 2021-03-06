/*
 * This file is part of DGD, https://github.com/dworkin/dgd
 * Copyright (C) 1993-2010 Dworkin B.V.
 * Copyright (C) 2010-2018 DGD Authors (see the commit log for details)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

# define  P_TCP      6
# define  P_UDP      17
# define  P_TELNET   1

struct connection;

extern bool	   conn_init	 (int, char**, char**, char**, unsigned short*,
				    unsigned short*, unsigned short*, int, int,
				    int);
extern void	   conn_clear	 ();
extern void	   conn_finish	 ();
extern void	   conn_listen	 ();
extern connection *conn_tnew6	 (int);
extern connection *conn_tnew	 (int);
extern connection *conn_bnew6	 (int);
extern connection *conn_bnew	 (int);
extern connection *conn_dnew6	 (int);
extern connection *conn_dnew	 (int);
extern bool	   conn_attach	 (connection*);
extern bool	   conn_udp	 (connection*, char*, unsigned int);
extern void	   conn_del	 (connection*);
extern void	   conn_block	 (connection*, int);
extern int	   conn_select	 (Uint, unsigned int);
extern bool	   conn_udpcheck (connection*);
extern int	   conn_read	 (connection*, char*, unsigned int);
extern int	   conn_udpread	 (connection*, char*, unsigned int);
extern int	   conn_write	 (connection*, char*, unsigned int);
extern int	   conn_udpwrite (connection*, char*, unsigned int);
extern bool	   conn_wrdone	 (connection*);
extern void	   conn_ipnum	 (connection*, char*);
extern void	   conn_ipname	 (connection*, char*);
extern void	  *conn_host	 (char*, unsigned short, int*);
extern connection *conn_connect	 (void*, int);
extern connection *conn_dconnect (int, void*, int);
extern int	   conn_check_connected (connection*, int*);
extern bool	   conn_export	 (connection*, int*, char*, unsigned short*,
				  short*, int*, int*, char**, char*);
extern connection *conn_import	 (int, char*, unsigned short, short, int, int,
				  char*, char, bool);
extern int	   conn_fdcount	 ();
extern void	   conn_fdlist	 (int*);
extern void	   conn_fdclose	 (int*, int);

extern bool	comm_init	(int, int, char**, char**, char**,
				   unsigned short*, unsigned short*,
				   unsigned short*, int, int, int);

extern void	comm_clear	();
extern void	comm_finish	();
extern void	comm_listen	();
extern int	comm_send	(Object*, String*);
extern int	comm_udpsend	(Object*, String*);
extern bool	comm_echo	(Object*, int);
extern void	comm_challenge	(Object*, String*);
extern void	comm_flush	();
extern void	comm_block	(Object*, int);
extern void	comm_receive	(Frame*, Uint, unsigned int);
extern String  *comm_ip_number	(Object*);
extern String  *comm_ip_name	(Object*);
extern void	comm_close	(Frame*, Object*);
extern Object  *comm_user	();
extern void	comm_connect	(Frame *f, Object *obj, char *addr,
				 unsigned short port);
extern void	comm_connect_dgram (Frame *f, Object *obj, int uport,
				    char *addr, unsigned short port);
extern Array   *comm_users	(Dataspace*);
extern bool     comm_is_connection (Object*);
extern bool	comm_dump	(int);
extern bool	comm_restore	(int);
