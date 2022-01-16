#pragma once
/* public domain md5 implementation based on rfc1321 and libtomcrypt */

struct md5 {
        uint64_t len;    /* processed message length */
        uint32_t h[4];   /* hash state */
        uint8_t buf[64]; /* message block buffer */
};

enum { MD5_DIGEST_LENGTH = 16 };

/* reset state */
void md5_init(struct md5 *s);
/* process message */
void md5_update(struct md5 *s, const uint8_t *p, unsigned long len);
/* get message digest */
/* state is ruined after sum, keep a copy if multiple sum is needed */
/* part of the message might be left in s, zero it if secrecy is needed */
void md5_sum(struct md5 *s, uint8_t md[MD5_DIGEST_LENGTH]);
