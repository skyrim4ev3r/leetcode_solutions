class Solution {
public:
    static int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        const size_t len = nums.size();
        int max_freq = 0;
        int max_freq_num = 0;
        int curr_freq = 0;
        int curr_num = 0;

        for (const auto num : nums) {
            if (curr_num == num) {
                curr_freq += 1;
            } else {
                curr_num = num;
                curr_freq = 1;
            }

            if (curr_freq > max_freq) {
                max_freq = curr_freq;
                max_freq_num = curr_num;
            }
        }

        return max_freq_num;
    }
};
