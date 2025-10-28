class Solution {
public:
    int countValidSelections(vector<int>& nums) {

        int sum_right{0};
        int sum_left{0};
        int count{0};

        for (const int &num: nums) {
            sum_right += num;
        }

        for (const int &num: nums) {
            sum_left += num;
            sum_right -= num;

            if (num == 0) {
                if (sum_left == sum_right) {
                    count += 2;
                } else if (abs(sum_left - sum_right) == 1) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
