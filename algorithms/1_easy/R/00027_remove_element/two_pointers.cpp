class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        const size_t len{nums.size()};
        size_t write_index{0};

        for (size_t read_index{0}; read_index < len; ++read_index) {
            if (nums[read_index] != val) {
                nums[write_index] = nums[read_index];
                write_index += 1;
            }
        }

        return static_cast<int>(write_index);
    }
};

