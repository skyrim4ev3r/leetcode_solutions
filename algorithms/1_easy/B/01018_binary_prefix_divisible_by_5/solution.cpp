class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int curr_num{0};
        vector<bool> res;
        res.reserve(nums.size());

        for (const int& num : nums) {
            curr_num = (curr_num * 2 + num) % 5;
            res.push_back(curr_num == 0);
        }

        return res;
    }
};
