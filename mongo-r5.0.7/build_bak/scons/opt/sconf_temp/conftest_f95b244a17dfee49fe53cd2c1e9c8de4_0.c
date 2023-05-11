
                #include <openssl/crypto.h>
                #include <openssl/evp.h>
            
int main(void)
{
#ifndef FIPS_mode_set
    (void) FIPS_mode_set;
#endif
    ;
    return 0;
}
