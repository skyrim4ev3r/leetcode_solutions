class Solution {
public:
    int countTriples(int n) {
        int count{0};

        for (int a{1}; a <= n; ++a) {
            for (int b{a}; b <= n; ++b) {
                const int c_square{a * a + b * b};
                const int possible_c = sqrt(c_square); 

                if (possible_c > n) {
                    break;
                }

                if (possible_c * possible_c == c_square) {
                    count += 2;
                }
            }
        }

        return count;
    }
};
