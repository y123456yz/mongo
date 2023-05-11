
#include <atomic>

int main(int argc, char* argv[]) {
    std::atomic<int32_t> x;

    x.store(0);
    // Use argc to ensure we can't optimize everything away.
    int32_t y = argc;
    x.fetch_add(y);
    x.fetch_sub(y);
    x.exchange(y);
    if (x.compare_exchange_strong(y, x) && x.is_lock_free())
        return 0;
    return x.load();
}
