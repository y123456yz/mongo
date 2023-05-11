
#include <unistd.h>
#if !(defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0)
#error POSIX clock_gettime not supported
#elif !(defined(_POSIX_MONOTONIC_CLOCK) && _POSIX_MONOTONIC_CLOCK >= 0)
#error POSIX monotonic clock not supported
#endif
