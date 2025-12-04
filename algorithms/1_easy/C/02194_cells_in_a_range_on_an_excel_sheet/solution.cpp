class Solution {
public:
    vector<string> cellsInRange(string s) {
        string curr = s.substr(0, 2);
        string target = s.substr(3, 2);
        vector<string> res{curr};
        char start_row = s[1];
        char end_row = s[4];

        while (curr != target) {
            curr[1] += 1;
            
            if (curr[1] > end_row) {
                curr[1] = start_row;
                curr[0] += 1;
            }

            res.push_back(curr);
        }

        return res;
    }
};
