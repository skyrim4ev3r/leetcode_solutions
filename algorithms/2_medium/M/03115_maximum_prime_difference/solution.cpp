const array<int, 25> PRE_CALC_PRIMES {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97
};

class Solution {
    static inline bool is_prime(int& num) {
        const bool found {binary_search(PRE_CALC_PRIMES.begin(), PRE_CALC_PRIMES.end(), num)};

        if (found) {
            return true;
        }

        return false;
    }
public:
    static int maximumPrimeDifference(vector<int>& nums) {
        const size_t len {nums.size()};
        size_t left {0};
        size_t right {len - 1};

        while (left < len && !is_prime(nums[left])) {
            left += 1;
        }

        while (right < len && !is_prime(nums[right])) {
            right -= 1;
        }

        return static_cast<int>(right - left);
    }
};
