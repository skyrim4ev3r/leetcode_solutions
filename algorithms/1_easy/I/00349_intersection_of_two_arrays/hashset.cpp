class Solution {
public:
    static vector<int> intersection(const vector<int>& nums1, const vector<int>& nums2) {
        auto set1 = unordered_set<int>(nums1.cbegin(), nums1.cend());
        auto set2 = unordered_set<int>(nums2.cbegin(), nums2.cend());
        auto res = vector<int>();

        for (const auto num : set1) {
            if (set2.contains(num)) {
                res.push_back(num);
            }
        }

        return res;
    }
};
