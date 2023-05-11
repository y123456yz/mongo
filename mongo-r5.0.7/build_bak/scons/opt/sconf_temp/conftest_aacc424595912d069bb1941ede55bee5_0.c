#include <execinfo.h>
int main(void)
{
#ifndef backtrace
    (void) backtrace;
#endif
    ;
    return 0;
}
