#ifndef SERIAL_HASH_INTERNAL_H
#define SERIAL_HASH_INTERNAL_H

void payload_new(gchar *key, guchar *value, gsize value_len, guchar **payload, gsize *payload_len);
gchar *payload_get_key(guchar *payload);
void payload_get_value(guchar *payload, guchar **value, gsize *value_len);
void payload_free(guchar *payload);

#endif
