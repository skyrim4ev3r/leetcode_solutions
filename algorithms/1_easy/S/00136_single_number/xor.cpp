class Solution {
public:
    static int singleNumber(const vector<int>& nums) {
        int res = 0;

        for (const int num: nums) {
            res ^= num;
        }

        return res;
    }
};
