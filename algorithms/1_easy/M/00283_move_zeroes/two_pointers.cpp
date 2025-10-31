class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const size_t len{nums.size()};
        size_t write_index{0};

        for (size_t read_index{0}; read_index < len; ++read_index) {
            if (nums[read_index] != 0) {
                nums[write_index] = nums[read_index];
                write_index += 1;
            }
        }

        for (size_t i{write_index}; i < len; ++i) {
            nums[i] = 0;
        }
    }
};
