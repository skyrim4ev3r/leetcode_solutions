class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res{std::numeric_limits<int>::max()};

        for (const int &num: nums) {
            if (abs(num) < abs(res)) {
                res = num;
            } else if (abs(num) == abs(res)) {
                res = max(res, num);
            }
        }

        return res;
    }
};
