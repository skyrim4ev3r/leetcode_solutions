class NumArray {
    vector<int> prefix;
public:
    NumArray(const vector<int>& nums) {
        const ptrdiff_t len = ssize(nums);
        prefix = vector<int>(len + 1);
        prefix[0] = 0;

        for (ptrdiff_t i = 1; i <= len; i += 1) {
            prefix[i] += nums[i - 1] + prefix[i - 1];
        }
    }

    int sumRange(int left, int right) {
        assert(left >= 0 && left <= right && right + 1 < std::ssize(prefix));
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
