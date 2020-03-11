/*
 * Copyright (c) 2019 Balabit
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As an additional exemption you are allowed to compile & link against the
 * OpenSSL libraries as published by the OpenSSL project. See the file
 * COPYING for details.
 *
 */

#ifndef SERIAL_LIST_H
#define SERIAL_LIST_H

#include <glib.h>

typedef struct
{
  guchar *base;
  gsize max_size;
} SerialList;

typedef gsize Offset;
typedef gsize SerialListHandle;

typedef gboolean (SerialListFindFunc)(guchar *data, gsize data_len, gpointer user_data);
typedef void (SerialListFunc)(guchar *data, gsize data_len, gpointer user_data);
typedef void (SerialListHandleFunc)(SerialList *self, SerialListHandle hande, gpointer user_data);

SerialList *serial_list_new(guchar *base, gsize size);
void serial_list_free(SerialList *self);
SerialListHandle serial_list_insert(SerialList *self, guchar *data, gsize data_len);
SerialListHandle serial_list_find(SerialList *self, SerialListFindFunc func, gpointer user_data);
const guchar *serial_list_get_data(SerialList *self, SerialListHandle handle, const guchar **data, gsize *data_len);
void serial_list_remove(SerialList *self, SerialListHandle handle);
SerialListHandle serial_list_update(SerialList *self, SerialListHandle handle, guchar *data, gsize data_len);
void serial_list_foreach(SerialList *self, SerialListFunc func, gpointer user_data);
void serial_list_print(SerialList *self);
void serial_list_rebase(SerialList *self, guchar *new_base, gsize orig_new_size);
SerialList *serial_list_load(guchar *base, gsize size);
void serial_list_handle_foreach(SerialList *self, SerialListHandleFunc func, gpointer user_data);

#endif
