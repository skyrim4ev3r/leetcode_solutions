class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0) {
            return false;
        }

        long reversed {0L}; //using long: to avoid overfosw of big ints like 2147483647 => 7463847412
        long tmp {static_cast<long>(x)};

        while (tmp > 0L) {
            reversed = reversed * 10L + tmp % 10L;
            tmp /= 10L;
        }

        return reversed == static_cast<long>(x);
    }
};
