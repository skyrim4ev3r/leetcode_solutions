class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1{};
        unordered_map<int, int> map2{};
        vector<int> res{};

        for (const int& num : nums1) {
            map1[num] += 1;
        }

        for (const int& num : nums2) {
            map2[num] += 1;
        }

        for (const auto& it1 : map1) {
            const auto it2 = map2.find(it1.first);

            if (it2 != map2.end()) {
                size_t count{static_cast<size_t>(std::min(it1.second, it2->second))};
                res.resize(res.size() + count, it1.first);
            }
        }

        return res;
    }
};
