class Solution {
public:
    string evaluate(string s, const vector<vector<string>>& knowledge) {
        unordered_map<string, string> hashmap{};
        for (const auto& k : knowledge) {
            hashmap[k[0]] = k[1];
        }

        string res{};
        size_t i{ 0 };
        const size_t len{ s.size() };

        while (i < len) {
            if (s[i] == '(') {
                string temp{};
                i += 1;

                while (i < len && s[i] != ')') {
                    temp.push_back(s[i]);
                    i += 1;
                }

                const auto it{ hashmap.find(temp) };

                if (it != hashmap.end()) {
                    res += it->second;
                } else {
                    res.push_back('?');
                }
            } else {
                res.push_back(s[i]);
            }

            i += 1;
        }

        return res;
    }
};
