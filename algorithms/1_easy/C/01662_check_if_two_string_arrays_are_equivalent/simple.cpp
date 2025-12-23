class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word1_sum{};
        string word2_sum{};

        for (auto &word: word1) {
            word1_sum += word;
        }
        for (auto &word: word2) {
            word2_sum += word;
        }

        return word1_sum == word2_sum;
    }
};
