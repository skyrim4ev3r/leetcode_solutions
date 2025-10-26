class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int res{0};

        for (int &num: nums) {

            int sq{static_cast<int>(sqrt(num))};
            int count{0};
            int sum{0};

            for (int i{1}; i <= sq; ++i) {
                if (num % i == 0) {
                    int other{num / i};

                    if (i == other) {
                        count += 1;
                        sum += i;
                    } else {
                        count += 2;
                        sum += i  + other;
                    }

                    if (count > 4) {
                        break;
                    }
                }
            }

            if (count == 4) {
                res += sum;
            }
        }

        return res;
    }
};
