class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int res{0};

        for (const int &num: nums) {
            if ((num & 1) != 1) {
                res |= num;
            }
        }

        return res;
    }
};
