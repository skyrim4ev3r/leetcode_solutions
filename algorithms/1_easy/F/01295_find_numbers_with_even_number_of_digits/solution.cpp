class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count{0};

        for (int num: nums) {
            int digit_count{0};

            while (num > 0) {
                digit_count += 1;
                num /= 10;
            }

            if ((digit_count & 1) != 1) {
                count += 1;
            }
        }

        return count;
    }
};
