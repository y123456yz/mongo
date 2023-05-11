
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <stdlib.h>

int main() {
    SSL_library_init();
    SSL_load_error_strings();
    ERR_load_crypto_strings();

    OpenSSL_add_all_algorithms();
    ERR_free_strings();

    return EXIT_SUCCESS;
}
