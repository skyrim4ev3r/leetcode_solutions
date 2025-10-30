class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res{0};

        for (const int &num: nums) {
            res |= num;
        }

        return res;
    }
};
