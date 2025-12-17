class Solution {
public:
    vector<int> diStringMatch(string s) {
        int min{0};
        int max{static_cast<int>(s.size())};
        vector<int> res;
        res.reserve(s.size() + 1);

        for (const char& ch : s) {
            if (ch == 'D') {
                res.push_back(max);
                --max;
            } else {
                res.push_back(min);
                ++min;
            }
        }

        res.push_back(min);

        return res;
    }
};
