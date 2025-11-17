class Solution {
public:
    bool checkRecord(string s) {
        int absent_count{0};
        int consecutive_late_count{0};

        for (const char& ch : s) {
            if (ch == 'A') {
                absent_count += 1;
                consecutive_late_count = 0;
            } else if (ch == 'L') {
                consecutive_late_count += 1;
            } else {
                consecutive_late_count = 0;
            }

            if (consecutive_late_count == 3 || absent_count == 2) {
                return false;
            }
        }

        return true;
    }
};
