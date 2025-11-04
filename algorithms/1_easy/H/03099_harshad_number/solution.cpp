class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {

        int tmp = x;
        int dig_sum = 0;

        while (tmp > 0) {
            dig_sum += tmp % 10;
            tmp /= 10;
        }

        if (x % dig_sum != 0) {
            return -1;
        }

        return dig_sum;
    }
};
