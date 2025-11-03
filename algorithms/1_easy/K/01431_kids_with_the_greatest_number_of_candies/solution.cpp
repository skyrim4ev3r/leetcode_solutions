class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max{0};
        for (const int &num: candies) {
            max = std::max(max, num);
        }

        vector<bool> res;
        for (const int &num: candies) {
            if (num + extraCandies >= max) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }

        return res;
    }
};
