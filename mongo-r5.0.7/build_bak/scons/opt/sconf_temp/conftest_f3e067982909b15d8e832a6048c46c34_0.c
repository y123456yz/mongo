#include <sys/types.h>
typedef off_t scons_check_type;

int main(void)
{
    static int test_array[1 - 2 * !(((long int) (sizeof(scons_check_type))) == 8)];
    test_array[0] = 0;

    return 0;
}
