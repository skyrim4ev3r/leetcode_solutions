class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        size_t nums_len{nums.size()};
        size_t write_index{1};

        for (size_t read_index{1}; read_index < nums_len; ++read_index) {
            if(nums[read_index] != nums[read_index - 1]) {
                nums[write_index] = nums[read_index];
                write_index += 1;
            }
        }

        return static_cast<int>(write_index);
    }
};
