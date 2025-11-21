class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        const size_t len{startTime.size()};
        int count{0};

        for (size_t i{0}; i < len; ++i) {
            if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
                count += 1;
            }
        }

        return count;
    }
};
