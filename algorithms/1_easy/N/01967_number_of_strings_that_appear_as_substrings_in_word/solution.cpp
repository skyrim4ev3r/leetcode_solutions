class Solution {
public:
    static int numOfStrings(const vector<string>& patterns, const string& word) {
        int count = 0;

        for (const auto& pattern : patterns) {
            if (word.find(pattern) != -1) {
                count += 1;
            }
        }

        return count;
    }
};
