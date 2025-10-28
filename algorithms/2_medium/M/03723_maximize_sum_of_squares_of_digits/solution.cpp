class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        if (num * 9 < sum) {
            return "";
        }

        size_t num_usize{static_cast<size_t>(num)};
        string res(num_usize, '0');

        for (size_t i{0}; i < num_usize; ++i) {
            if (sum == 0) {
                return res;
            }

            int curr_dig = std::min(sum, 9);
            sum -= curr_dig;
            res[i] = '0' + static_cast<char>(curr_dig);
        }

        return res;
    }
};
