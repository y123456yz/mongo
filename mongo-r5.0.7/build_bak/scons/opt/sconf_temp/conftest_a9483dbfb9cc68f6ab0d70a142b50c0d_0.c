

#include <assert.h>

#ifdef __cplusplus
extern "C"
#endif
char sync_file_range();

#if _MSC_VER && !__INTEL_COMPILER
    #pragma function(sync_file_range)
#endif

int main(void) {
#if defined (__stub_sync_file_range) || defined (__stub___sync_file_range)
  fail fail fail
#else
  sync_file_range();
#endif

  return 0;
}
