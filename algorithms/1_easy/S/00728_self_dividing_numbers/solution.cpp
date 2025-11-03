class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> res{};

        for (int i{left}; i <= right; ++i) {

            int tmp{i};
            bool is_divisible{true};

            while (tmp > 0) {
                int digit{tmp % 10};

                if (digit == 0 || i % digit !=0) {
                    is_divisible = false;
                    break;
                }

                tmp /= 10;
            }

            if (is_divisible) {
                res.push_back(i);
            }
        }

        return res;
    }
};
