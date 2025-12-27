class Solution {
public:
    static vector<int> findWordsContaining(const vector<string>& words, char x) {
        vector<int> res;

        for (int i {0}; const string& word : words) {
            if (word.find(x) != std::string::npos) {
                res.push_back(i);
            }

            i += 1;
        }

        return res;
    }
};
