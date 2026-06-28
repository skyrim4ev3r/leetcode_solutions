class Solution {
public:
    static int countDigitOccurrences(const vector<int>& nums, const int digit) {
        int freq  = 0;

        for (int num : nums) {
            while (num > 0) {
                if (num % 10 == digit) {
                    freq += 1;
                }
                num /= 10;
            }
        }

        return freq;
    }
};
