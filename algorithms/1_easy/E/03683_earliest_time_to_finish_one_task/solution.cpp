class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int min{INT_MAX};

        for (const auto &task: tasks) {
            min = std::min(min, task[0] + task[1]);
        }

        return min;
    }
};
