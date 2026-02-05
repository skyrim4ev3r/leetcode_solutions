class Solution {
public:
    static int minimumSize(const vector<int>& nums, int max_operations) {
        int high{ *max_element(nums.cbegin(), nums.cend()) };
        int low{ 1 };

        while (low <= high) {
            const int mid{ low + (high - low) / 2 };
            int op_left{ max_operations };

            for (const int& num : nums) {
                if (num > mid) {
                    op_left = op_left - ((num + mid - 1) / mid) + 1;
                }

                if (op_left < 0) {
                    break;
                }
            }

            if (op_left < 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};
