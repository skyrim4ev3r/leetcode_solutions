class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {

        unordered_map<int, char> map{};
        vector<int>  res{};

        for (const int &num: nums1) {
            map[num] |= 1;
        }

        for (const int &num: nums2) {
            map[num] |= 2;
        }

        for (const int &num: nums3) {
            map[num] |= 4;
        }

        for (const auto &it: map) {
            if (__builtin_popcount(it.second) > 1) {
                res.push_back(it.first);
            }
        }

        return res;
    }
};
