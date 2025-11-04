class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int &num: nums) {
            num *= num;
        }

        const size_t len{nums.size()};
        size_t left{0};
        size_t right{len - 1};
        vector<int> res(len);
        size_t res_index{len - 1};

        while (left <= right) {
            if (nums[left] <= nums[right]) {
                res[res_index] = nums[right];
                right -= 1;
            } else {
                res[res_index] = nums[left];
                left += 1;
            }

            res_index -= 1;
        }

        return  res;
    }
};
