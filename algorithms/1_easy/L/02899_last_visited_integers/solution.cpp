class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> seen{};
        size_t consecutive_negative_ones{0};
        vector<int> res{};

        for (const int& num : nums) {
            if (num == -1) {
                consecutive_negative_ones += 1;

                if (consecutive_negative_ones > seen.size()) {
                    res.push_back(-1);
                } else {
                    res.push_back(seen[seen.size() - consecutive_negative_ones]);
                }
            } else {
                seen.push_back(num);
                consecutive_negative_ones = 0;
            }
        }

        return res;
    }
};
