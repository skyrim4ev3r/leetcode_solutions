class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        }

        if (n == 3) {
            return 2;
        }

        int count_two{0};
        int count_three{n / 3};
        int reminder{n % 3};

        if (reminder == 1) {
            count_two = 2;
            count_three -= 1;
        } else if (reminder == 2) {
            count_two = 1;
        }

        return pow(3, count_three) * pow(2, count_two) ;
    }
};
