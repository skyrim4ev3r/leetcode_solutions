class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> seen {};
        vector<string> res {};
        string part {};

        for (const char& ch : s) {
            part.push_back(ch);

            if (seen.insert(part).second) {
                res.emplace_back(move(part));
            }
        }

        return res;
    }
};
