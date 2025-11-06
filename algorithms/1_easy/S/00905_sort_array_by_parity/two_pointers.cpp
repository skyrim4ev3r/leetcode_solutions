class Solution {
    inline bool is_odd(const int &num) const {
        return (num & 1) == 1;
    }

    inline bool is_even(const int &num) const {
        return (num & 1) == 0;
    }

public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        const size_t len{nums.size()};
        size_t even_index{0};
        size_t odd_index{len - 1};

        while (true) {
            while (even_index < len && is_even(nums[even_index])) {
                even_index += 1;
            }

            while (odd_index < len && is_odd(nums[odd_index])) {
                odd_index -= 1;
            }

            if (even_index >= len || odd_index >= len || even_index >= odd_index) {
                break;
            }

            const int tmp = nums[even_index];
            nums[even_index] = nums[odd_index];
            nums[odd_index] = tmp;

            odd_index -= 1;
            even_index += 1;
        }

        return nums;
    }
};
