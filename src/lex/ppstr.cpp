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

# include "lex.h"
# include "ppstr.h"

/*
 * A string utility for the preprocessor.
 */

# define SCHUNKSZ	8

static Chunk<str, SCHUNKSZ> schunk;

/*
 * NAME:	str->init()
 * DESCRIPTION:	initialize string handling
 */
void pps_init()
{
}

/*
 * NAME:	str->clear()
 * DESCRIPTION:	finish string handling
 */
void pps_clear()
{
    schunk.clean();
}

/*
 * NAME:	str->new()
 * DESCRIPTION:	make a new string with length 0.
 */
str *pps_new(char *buf, int sz)
{
    str *sb;

    sb = chunknew (schunk) str;
    sb->buffer = buf;
    sb->buffer[0] = '\0';
    sb->size = sz;
    sb->len = 0;

    return sb;
}

/*
 * NAME:	str->scat()
 * DESCRIPTION:	append a string. The length becomes -1 if the result is too long
 */
int pps_scat(str *sb, const char *s)
{
    int l;

    if (sb->len < 0 || sb->len + (l = strlen(s)) >= sb->size) {
	return sb->len = -1;
    }
    strcpy(sb->buffer + sb->len, s);
    return sb->len += l;
}

/*
 * NAME:	str->ccat()
 * DESCRIPTION:	append a char. The length becomes -1 if the result is too long
 */
int pps_ccat(str *sb, int c)
{
    if (sb->len < 0 || c == '\0' || sb->len + 1 >= sb->size) {
	return sb->len = -1;
    }
    sb->buffer[sb->len++] = c;
    sb->buffer[sb->len] = '\0';
    return sb->len;
}
