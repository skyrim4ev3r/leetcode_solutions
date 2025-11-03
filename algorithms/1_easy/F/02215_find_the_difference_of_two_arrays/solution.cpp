class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res{};
        unordered_set<int> set1 = unordered_set<int>(nums1.begin(), nums1.end());
        unordered_set<int> set2 = unordered_set<int>(nums2.begin(), nums2.end());

        vector<int> v1{};
        vector<int> v2{};

        for (const int &num: set1) {
            if (!set2.contains(num)) {
                v1.push_back(num);
            }
        }

        for (const int &num: set2) {
            if (!set1.contains(num)) {
                v2.push_back(num);
            }
        }

        res.push_back(v1);
        res.push_back(v2);

        return res;
    }
};
