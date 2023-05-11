

#include <assert.h>

#ifdef __cplusplus
extern "C"
#endif
char explicit_bzero();

#if _MSC_VER && !__INTEL_COMPILER
    #pragma function(explicit_bzero)
#endif

int main(void) {
#if defined (__stub_explicit_bzero) || defined (__stub___explicit_bzero)
  fail fail fail
#else
  explicit_bzero();
#endif

  return 0;
}
