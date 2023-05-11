
#include <openssl/ssl.h>

int main() {
    SSL_CTX_set_ecdh_auto(0, 0);
    SSL_set_ecdh_auto(0, 0);
    return 0;
}
