class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res{0};
        int curr_index{0};

        while (n > 0) {
            if (n % 2 == 1) {
                res = pow(2, curr_index + 1) - 1 - res;
            }

            n /= 2;
            curr_index += 1;
        }

        return res;
    }
};
