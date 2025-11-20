class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int max1{numeric_limits<int>::min()};
        int max2{numeric_limits<int>::min()};
        int min1{numeric_limits<int>::max()};

        for (const int& num : nums) {
            if (num > max1) {
                max2 = max1;
                max1 = num;
            } else {
                max2 = std::max(max2, num);
            }

            min1 = std::min(min1, num);
        }

        return max1 + max2 - min1;
    }
};
