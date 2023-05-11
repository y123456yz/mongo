#include <execinfo.h>
int main(void)
{
#ifndef backtrace_symbols
    (void) backtrace_symbols;
#endif
    ;
    return 0;
}
