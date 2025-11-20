class Solution {
public:
    static bool threeConsecutiveOdds(const vector<int>& arr) {
        int  consecutive_odd_count{0};

        for (const int& num : arr) {
            if (num % 2 == 1) {
                consecutive_odd_count += 1;
            } else {
                consecutive_odd_count = 0;
            }

            if (consecutive_odd_count == 3) {
                    return true;
            }
        }

        return false;
    }
};
