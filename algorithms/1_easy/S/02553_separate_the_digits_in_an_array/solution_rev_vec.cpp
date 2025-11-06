class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res{};

        for (int num: nums) {
            vector<int> tmp_vec{};
            while (num > 0) {
                tmp_vec.push_back(num % 10);
                num /= 10;
            }
            res.insert(res.end(), tmp_vec.rbegin(), tmp_vec.rend());
        }

        return res;
    }
};
