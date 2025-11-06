class Solution {
    inline bool is_prime(int num) {
        if (num == 2) {
            return true;
        }

        if (num <= 1 || num % 2 == 0) {
            return false;
        }

        int sq{static_cast<int>(sqrt(num))};
        for (int i{3}; i <= sq; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

public:
    int diagonalPrime(vector<vector<int>>& nums) {
        size_t len{nums.size()};
        int max{0};

        for (size_t i{0}; i < len; ++i) {
            if (max < nums[i][i] && is_prime(nums[i][i])) {
                max = nums[i][i];
            }

            if (max < nums[i][len - 1 - i] && is_prime(nums[i][len - 1 - i])) {
                max = nums[i][len - 1 - i];
            }
        }

        return max;
    }
};
