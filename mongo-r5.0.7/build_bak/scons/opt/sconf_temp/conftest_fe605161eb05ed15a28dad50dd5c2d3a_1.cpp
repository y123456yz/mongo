
#if !defined(__GNUC__) || defined(__clang__)
#error
#endif

#if (__GNUC__ < 8) || (__GNUC__ == 8 && __GNUC_MINOR__ < 2)
#error GCC 8.2 or newer is required to build MongoDB
#endif

int main(int argc, char* argv[]) {
    return 0;
}
