class Solution {
public:
    string sortSentence(string s) {
        vector<pair<char, string>> arr;
        arr.reserve(9);
        istringstream ss{s};
        string part;

        while (ss>>part) {
            char ch = part.back() - '0';
            part.pop_back();

            arr.push_back({ch, move(part)});
        }

        sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });

        string res{};
        res.reserve(s.size() - arr.size());

        for (const auto& [_, word] : arr) {
            if (!res.empty()) {
                res.push_back(' ');
            }

            res += word;
        }

        return res;
    }
};
