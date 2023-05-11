
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <pthread.h>

int main() {
    pthread_setname_np(pthread_self(), "test");
    return 0;
}
