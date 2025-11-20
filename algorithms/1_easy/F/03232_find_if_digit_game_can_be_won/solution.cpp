class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int balance{0};

        for (const int& num : nums) {
            if (num < 10) {
                balance += num;
            } else {
                balance -= num;
            }
        }

        return balance != 0;
    }
};
