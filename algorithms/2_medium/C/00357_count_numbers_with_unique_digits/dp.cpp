class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int count = 1; // for n = 0
        int ways = 9;

        for (int i = 1; i <= n; i += 1) {
            count += ways;
            ways *= max(0, 10 - i);
        }

        return count;
    }
};
