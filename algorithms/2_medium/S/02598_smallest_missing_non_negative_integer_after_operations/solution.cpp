class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        size_t value_usize = static_cast<size_t>(value);
        vector<int> remainders(value_usize, 0);

        for (int &num: nums) {
            size_t index = static_cast<size_t>(abs(num)) % value_usize;

            // Adjust index for negative numbers
            if (index != 0 && num < 0) {
                index = value_usize - index;
            }

            remainders[index] += 1;
        }

        int res{0};
        size_t curr_reminder_index{0};

        while (remainders[curr_reminder_index] != 0) {
            remainders[curr_reminder_index] -= 1;
            res += 1;
            curr_reminder_index += 1;

            if (curr_reminder_index == value_usize) {
                curr_reminder_index = 0;
            }
        }
 
        return res;
    }
};
