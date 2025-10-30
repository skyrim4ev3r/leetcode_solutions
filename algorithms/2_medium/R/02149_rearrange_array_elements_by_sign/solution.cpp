class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        size_t index_neg{1};
        size_t index_pos{0};

        vector<int> res(nums.size(), 0);

        for (const int &num: nums) {
            if (num < 0) {
                res[index_neg] = num;
                index_neg += 2;
            } else {
                res[index_pos] = num;
                index_pos += 2;
            }
        }

        return res;
    }
};
