class Solution {
public:
    static int prefixCount(const vector<string>& words, const string& pref) {
        int count {0};

        for (const string& word : words) {
            if (word.starts_with(pref)) {
                count += 1;
            }
        }

        return count;
    }
};
