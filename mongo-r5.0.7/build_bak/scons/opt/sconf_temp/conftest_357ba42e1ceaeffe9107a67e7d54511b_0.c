#include <execinfo.h>
int main(void)
{
#ifndef backtrace_symbols_fd
    (void) backtrace_symbols_fd;
#endif
    ;
    return 0;
}
