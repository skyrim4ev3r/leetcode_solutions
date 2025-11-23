class NumArray {
    vector<int>  nums;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        const size_t len{this->nums.size()};

        for (size_t i{1}; i < len; ++i) {
            this->nums[i] += this->nums[i - 1];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) {
            return nums[static_cast<size_t>(right)];
        }

        return nums[static_cast<size_t>(right)] - nums[static_cast<size_t>(left - 1)];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
