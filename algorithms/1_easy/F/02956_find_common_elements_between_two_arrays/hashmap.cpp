class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1 {};
        unordered_map<int, int> map2 {};
        int count1 {0};
        int count2 {0};

        for (const int& num : nums1) {
            map1[num] += 1;
        }

        for (const int& num : nums2) {
            map2[num] += 1;
        }

        for (const auto& [num1, freq1] : map1) {
            auto it {map2.find(num1)};

            if (it != map2.end()) {
                count1 += freq1;
                count2 += it->second;
            }
        }

        return vector<int>{count1, count2};
    }
};
