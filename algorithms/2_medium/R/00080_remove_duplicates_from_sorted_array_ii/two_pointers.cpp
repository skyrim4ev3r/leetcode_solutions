class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t nums_len{nums.size()};

        if (nums_len < 3) {
            return static_cast<int>(nums_len);
        }

        size_t write_index = 2;

        for (size_t read_index{2}; read_index < nums_len; ++read_index) {
            if (nums[read_index] == nums[write_index - 2]) {
                continue;
            }

            nums[write_index] = nums[read_index];
            write_index += 1;
        }

        return static_cast<int>(write_index);
    }
};
