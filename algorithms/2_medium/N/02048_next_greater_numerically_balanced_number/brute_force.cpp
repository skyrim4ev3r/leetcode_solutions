class Solution {
    bool is_beautifull(int num) {
        int freqs[10]{};

        while (num > 0) {
            freqs[static_cast<size_t>(num % 10)] += 1;
            num /= 10;
        }

        for (size_t i{0}; i < 10; ++i) {
            if (freqs[i] != 0 && freqs[i] != static_cast<int>(i)) {
                return false;
            }
        }

        return true;
    }

public:
    int nextBeautifulNumber(int n) {
        int next = n + 1;

        while (true) {
            if (is_beautifull(next)) {
                return next;
            }
            next += 1;
        }
    }
};
