class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& new_interval) {
        vector<vector<int>> res{};
        int i = 0;
        int n = intervals.size();

        while (i < n && intervals[i][1] < new_interval[0]) {
            res.push_back(intervals[i]);
            i += 1;
        }

        while (i < n && intervals[i][0] <= new_interval[1]) {
            new_interval[0] = min(new_interval[0], intervals[i][0]);
            new_interval[1] = max(new_interval[1], intervals[i][1]);
            i += 1;
        }

        res.push_back(new_interval);

         while (i < n) {
            res.push_back(intervals[i]);
            i += 1;
         }

         return res;
    }
};
