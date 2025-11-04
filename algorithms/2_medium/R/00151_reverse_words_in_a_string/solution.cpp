class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(string(s.rbegin(), s.rend())); // reverse input "ab cd ef" to "fe dc ba"
        string word;
        string s_rev{};

        while (ss >> word) {
            if (!s_rev.empty()) {
                s_rev.push_back(' ');
            }

            s_rev.append(word.rbegin(), word.rend()); // Now reverse each word in "fe dc ba" to "ef cd ab"
        }

        return s_rev;
    }
};
