class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_5s {0};
        int count_10s {0};

        for (const int& bill : bills) {
            if (bill == 5) {
                count_5s += 1;
            } else if (bill == 10) {
                if (count_5s > 0) {
                    count_5s -= 1;
                    count_10s += 1;
                } else {
                    return false;
                }
            } else if (bill == 20) {
                if (count_10s > 0 && count_5s > 0) {
                    count_10s -= 1;
                    count_5s -= 1;
                } else if (count_5s >= 3) {
                    count_5s -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
