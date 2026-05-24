class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const size_t len = nums.size();
        size_t write_index = 1;

        for (size_t read_index = 1; read_index < len; read_index += 1) {
            if(nums[read_index] != nums[read_index - 1]) {
                nums[write_index] = nums[read_index];
                write_index += 1;
            }
        }

        return static_cast<int>(write_index);
    }
};
