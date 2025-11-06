class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count{0};

        for (const int &h: hours) {
            if (h >= target) {
                count += 1;
            }
        }

        return count;
    }
};
