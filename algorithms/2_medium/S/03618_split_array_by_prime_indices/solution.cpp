class Solution {
    bool is_prime(const size_t n) {
        if (n == 2 || n == 3 || n == 5) {
            return true;
        }

        if (n < 2 || n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
            return false;
        }

        size_t sqrt_n{static_cast<size_t>(sqrt(n))};

        for (size_t i{7}; i <= sqrt_n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }
public:
    long long splitArray(vector<int>& nums) {

        long long sum{0};
        const size_t len{nums.size()};

        for (size_t i{0}; i < len; ++i) {
            if (is_prime(i)) {
                sum += nums[i];
            } else {
                sum -= nums[i];
            }
        }

        return abs(sum);
    }
};
