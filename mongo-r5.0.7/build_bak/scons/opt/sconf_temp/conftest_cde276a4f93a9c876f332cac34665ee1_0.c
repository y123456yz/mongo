
// POSIX requires the existence of unistd.h, so if we can't include unistd.h, we
// are definitely not a POSIX system.
#include <unistd.h>
#if !defined(_POSIX_VERSION)
#error not a POSIX system
#endif
