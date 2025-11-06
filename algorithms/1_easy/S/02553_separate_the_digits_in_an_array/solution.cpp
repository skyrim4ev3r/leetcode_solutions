class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res{};

        for (const int &num: nums) {
            int p{1};
            while (p <= num) {
                p *= 10;
            }
            p /= 10;

            while (p > 0) {
                res.push_back((num / p) % 10);
                p /= 10;
            }
        }

        return res;
    }
};
