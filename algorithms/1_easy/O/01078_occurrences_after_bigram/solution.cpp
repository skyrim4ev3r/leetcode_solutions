class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream ss{move(text)};
        vector<string> res;
        string prev{}, prev_prev{}, current{};

        while (ss>>current) {
            if (prev_prev == first && prev == second) {
                res.push_back(current);
            }

            prev_prev = move(prev);
            prev = move(current);
        }

        return res;
    }
};
