class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        const size_t len{nums.size()};

        for (int &num: nums) {
            while (!res.empty() && gcd(num, res.back()) > 1) {
                num = lcm(num, res.back());
                res.pop_back();
            }

            res.push_back(num);
        }

        return res;
    }
};
