class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        const size_t n {nums1.size()};
        unordered_map<int, int> hashmap;
        int count {0};

        for (size_t i3 {0}; i3 < n; ++i3) {
            for (size_t i4 {0}; i4 < n; ++i4) {
                hashmap[nums3[i3] + nums4[i4]] += 1;
            }
        }

        for (size_t i1 {0}; i1 < n; ++i1) {
            for (size_t i2 {0}; i2 < n; ++i2) {
                const int sum {nums1[i1] + nums2[i2]};
                const int other {-sum};
                const auto& it {hashmap.find(other)};

                if (it != hashmap.end()) {
                    count += it->second;
                }
            }
        }

        return count;
    }
};
