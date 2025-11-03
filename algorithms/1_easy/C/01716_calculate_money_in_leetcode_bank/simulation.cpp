class Solution {
public:
    int totalMoney(int n) {

        int curr_investment{1};
        int total_investment{0};

        for (int day{1}; day <= n; ++day) {
            total_investment += curr_investment;
            curr_investment += 1;
            if (day % 7 == 0) {
                curr_investment -=  6;
            }
        }

        return total_investment;
    }
};
