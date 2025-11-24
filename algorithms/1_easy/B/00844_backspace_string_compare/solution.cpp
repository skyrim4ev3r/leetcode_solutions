class Solution {
    static inline string custom_parse(const string& s) {
        string final_s{};

        for (const char& ch : s) {
            if (ch == '#') {
                if (!final_s.empty()) {
                    final_s.pop_back();
                }
            } else {
                final_s.push_back(ch);
            }
        }

        return final_s;
    }
public:
    static bool backspaceCompare(const string& s, const string& t) {
        return custom_parse(s) == custom_parse(t);
    }
};
