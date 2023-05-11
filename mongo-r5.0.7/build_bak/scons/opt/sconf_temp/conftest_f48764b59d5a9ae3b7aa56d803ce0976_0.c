

#include <assert.h>

#ifdef __cplusplus
extern "C"
#endif
char strnlen();

#if _MSC_VER && !__INTEL_COMPILER
    #pragma function(strnlen)
#endif

int main(void) {
#if defined (__stub_strnlen) || defined (__stub___strnlen)
  fail fail fail
#else
  strnlen();
#endif

  return 0;
}
