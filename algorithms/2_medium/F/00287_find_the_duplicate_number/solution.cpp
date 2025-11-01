class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        const size_t len{nums.size()};
        int res{-1};
        size_t index{0};

        for (; index < len ; ++index) {
            const size_t num_as_index{static_cast<size_t>(abs(nums[index])) - 1};
            if (nums[num_as_index] > 0) {
                nums[num_as_index] *= -1;
            } else {
                res = abs(nums[index]);
                break;
            }
        }
                
        for (size_t i{0}; i < index; ++i) {
            const size_t num_as_index{static_cast<size_t>(abs(nums[i])) - 1};
            nums[num_as_index] *= -1;
        }

        return res;
    }
};
