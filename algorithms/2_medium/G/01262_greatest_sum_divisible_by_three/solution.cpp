class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int sum = reduce(nums.begin(), nums.end(), 0);

        if (sum % 3 == 0) {
            return sum;
        }

        int mod1_min1{-1}, mod1_min2{-1}, mod2_min1{-1}, mod2_min2{-1};

        for (const int& num : nums) {
            switch (num % 3) {
                case 1:
                    if (mod1_min1 == -1 || mod1_min1 > num) {
                        mod1_min2 = mod1_min1;
                        mod1_min1 = num;
                    } else if (mod1_min2 == -1 || mod1_min2 > num) {
                        mod1_min2 = num;
                    }

                    break;

                case 2:
                    if (mod2_min1 == -1 || mod2_min1 > num) {
                        mod2_min2 = mod2_min1;
                        mod2_min1 = num;
                    } else if (mod2_min2 == -1 || mod2_min2 > num) {
                        mod2_min2 = num;
                    }

                    break;

                default:
                    break;
            }
        }

        int sum1{0}, sum2{0};
        switch (sum % 3) {
            case 1:
                sum1 = mod1_min1 != -1 ? sum - mod1_min1 : 0;
                sum2 = mod2_min1 != -1 && mod2_min2 != -1 ? sum - mod2_min1 - mod2_min2 : 0;

                return std::max(sum1, sum2);

            case 2:
                sum1 = mod1_min1 != -1 && mod1_min2 != -1 ? sum - mod1_min1 - mod1_min2 : 0;
                sum2 = mod2_min1 != -1 ? sum - mod2_min1 : 0;

                return std::max(sum1, sum2);

            default:
                return -1;
        }
    }
};
