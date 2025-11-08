class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int max1{0};
        int max2{0};

        for (const int &num: nums) {
            const int abs_num{abs(num)};

            if (abs_num > max1) {
                max2 = max1;
                max1 = abs_num;
            } else if (abs_num > max2) {
                max2 = abs_num;
            }
        }

        return static_cast<long long>(max1) * static_cast<long long>(max2) * 100'000LL;
    }
};
