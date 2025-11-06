class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res{};

        for (auto it{nums.cbegin() + 1}; it != nums.cend(); ++it) {
            for (int k{*(it - 1) + 1}; k < *it; ++k) {
                res.push_back(k);
            }
        }

        return res;
    }
};
