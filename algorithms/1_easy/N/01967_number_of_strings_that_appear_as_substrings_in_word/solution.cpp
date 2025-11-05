class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count{0};

        for (const string &pattern: patterns) {
            if (word.find(pattern) != -1) {
                count += 1;
            }
        }

        return count;
    }
};
