class Solution {
public:
    int maxProductDifference(vector<int>& nums) {

        int min1{INT_MAX};
        int min2{INT_MAX};

        int max1{INT_MIN};
        int max2{INT_MIN};

        for (const int &num: nums) {
            if (num < min2) {
                min1 = min2;
                min2 = num;
            } else if (num < min1) {
                min1 = num;
            }

            if (max2 < num) {
                max1 = max2;
                max2 = num;
            } else if (max1 < num) {
                max1 = num;
            }
        }

        return (max1 * max2) - (min1 * min2);
    }
};
