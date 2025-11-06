class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        const int min{*std::min_element(nums.begin(), nums.end())};
        const int max{*std::max_element(nums.begin(), nums.end())};
        vector<int> res{};

        for (int val{min}; val != max; ++val) {
            if (set.find(val) == set.end()) {
                res.push_back(val);
            }
        }

        return res;
    }
};
