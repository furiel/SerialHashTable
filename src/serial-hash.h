#ifndef SERIAL_HASH_H
#define SERIAL_HASH_H

#include <glib.h>

typedef struct _SerialHash SerialHash;

SerialHash *serial_hash_new(guchar *base, gsize max_size);
void serial_hash_free(SerialHash *self);
gboolean serial_hash_insert(SerialHash *self, gchar *key, guchar *value, gsize value_len);
void serial_hash_lookup(SerialHash *self, gchar *key, const guchar **value, gsize *value_len);
void serial_hash_remove(SerialHash *self, gchar *key);
SerialHash *serial_hash_load(guchar *base, gsize max_size);
void serial_hash_rebase(SerialHash *self, guchar *base, gsize max_size);
GHashTable *serial_hash_get_index(SerialHash *self);

#endif
