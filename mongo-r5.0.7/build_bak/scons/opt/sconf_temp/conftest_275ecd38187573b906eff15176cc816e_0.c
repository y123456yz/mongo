

#include <assert.h>

#ifdef __cplusplus
extern "C"
#endif
char fallocate();

#if _MSC_VER && !__INTEL_COMPILER
    #pragma function(fallocate)
#endif

int main(void) {
#if defined (__stub_fallocate) || defined (__stub___fallocate)
  fail fail fail
#else
  fallocate();
#endif

  return 0;
}
