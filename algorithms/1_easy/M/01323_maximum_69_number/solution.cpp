class Solution {
public:
    int maximum69Number (int num) {
        int p{1};

        while (p <= num) {
            p *= 10;
        }

        p /= 10;// Now: (num / p) % 10 will give us top digit of num on the left side

        while (p > 0) {
            int curr_digit{(num / p) % 10};

            if (curr_digit == 6) {
                return num + (3 * p); // This number 3 comes from here: 9 - 6 = 3;
            }                         // + (3 * p) will add 3 to highest 6

            p /= 10;
        }

        return num;
    }
};
