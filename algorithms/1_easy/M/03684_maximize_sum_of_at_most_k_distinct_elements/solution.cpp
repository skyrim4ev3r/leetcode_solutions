class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        std::set<int> exact_set(nums.begin(), nums.end());
        vector<int> res{};

        for (auto it{exact_set.rbegin()}; it != exact_set.rend() && k > 0; ++it, --k) {
            res.push_back(*it);
        }

        return res;
    }
};
