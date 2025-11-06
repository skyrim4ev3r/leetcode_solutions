class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        size_t odd_index{1};
        size_t even_index{0};
        const size_t len{nums.size()};

        while (odd_index < len && even_index < len) {
            while (odd_index < len && (nums[odd_index] & 1) == 1) {
                odd_index += 2;
            }
            while (even_index < len && (nums[even_index] & 1) == 0) {
                even_index += 2;
            }

            if (odd_index >= len && even_index >= len) {
                break;
            }

            const int tmp = nums[even_index];
            nums[even_index] = nums[odd_index];
            nums[odd_index] = tmp;
    
            odd_index += 2;
            even_index += 2;
        }

        return nums;
    }
};
