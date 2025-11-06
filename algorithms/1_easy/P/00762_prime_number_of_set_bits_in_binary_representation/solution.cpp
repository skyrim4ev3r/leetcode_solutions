class Solution {
    inline bool is_prime(const unsigned int &num) {
        switch (num) {
            case 2:
            case 3:
            case 5:
            case 7:
            case 11:
            case 13:
            case 17:
            case 19:
            case 23:
            case 29:
            case 31:
                return true;
            default:
                return false;
        }
    }

public:
    int countPrimeSetBits(int left, int right) {
        int count{0};

        for (int num{left}; num <=right; ++num) {
            if (is_prime(__builtin_popcount(num))) {
                count += 1;
            }
        }

        return count;
    }
};
