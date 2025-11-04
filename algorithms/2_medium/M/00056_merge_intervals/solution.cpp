class Solution {    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res{};

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });

        for (const auto &interval: intervals) {
            if (!res.empty() && res.back()[1] >= interval[0]) {
                res.back()[1] = std::max(res.back()[1], interval[1]);
            } else {
                res.push_back(interval);
            }
        }

        return res;
    }
};
