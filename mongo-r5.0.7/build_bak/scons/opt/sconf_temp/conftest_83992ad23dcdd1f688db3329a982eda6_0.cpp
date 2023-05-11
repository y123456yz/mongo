
#define __STDC_WANT_LIB_EXT1__ 1
#include <cstring>
int main(int argc, char* argv[]) {
    void* data = nullptr;
    return memset_s(data, 0, 0, 0);
}
