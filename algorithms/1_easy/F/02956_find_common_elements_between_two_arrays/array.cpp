const size_t MAX_NUM{101};

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        array<int, MAX_NUM> map1 {};
        array<int, MAX_NUM> map2 {};
        int count1 {0};
        int count2 {0};

        for (const int& num : nums1) {
            map1[static_cast<size_t>(num)] += 1;
        }

        for (const int& num : nums2) {
            map2[static_cast<size_t>(num)] += 1;
        }

        for (size_t i{0}; i < MAX_NUM; ++i) {
            if (map1[i] > 0 && map2[i] > 0) {
                count1 += map1[i];
                count2 += map2[i];
            }
        }

        return vector<int>{count1, count2};
    }
};
