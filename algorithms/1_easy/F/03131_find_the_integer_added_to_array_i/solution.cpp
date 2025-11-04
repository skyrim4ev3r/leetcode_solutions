class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int min1{INT_MAX};
        int min2{INT_MAX};

        for (const int &num: nums1) {
            min1 = min(min1, num);
        }

        for (const int &num: nums2) {
            min2 = min(min2, num);
        }

        return min2 - min1;
    }
};
