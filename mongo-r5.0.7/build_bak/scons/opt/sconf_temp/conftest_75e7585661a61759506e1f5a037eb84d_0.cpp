
#include <openssl/ssl.h>
#include <openssl/ec.h>

int main() {
    SSL_CTX_set_tmp_ecdh(0, 0);
    EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);
    EC_KEY_free(0);
    return 0;
}
