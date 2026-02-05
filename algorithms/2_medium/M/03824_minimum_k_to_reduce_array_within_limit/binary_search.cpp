class Solution {
    static bool check_guess(const vector<int>& nums, const int guess) {
        int op_needed{ 0 };

        for (const int& num : nums) {
            op_needed += (num + guess - 1) / guess;
        }

        return op_needed <= std::pow(guess, 2);
    }
public:
    static int minimumK(const vector<int>& nums) {
        int low{ 1 };
        int high{ 10'000 };

        while (low <= high) {
            const int mid{ low + (high - low) / 2 };

            if (check_guess(nums, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
