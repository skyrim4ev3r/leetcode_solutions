class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> hashset{};
        int count{0};

        for (string& word : words) {
            string rev_word{word};
            reverse(rev_word.begin(), rev_word.end());

            if (hashset.erase(rev_word)) {
                count += 1;
            } else {
                hashset.emplace(word);
            }
        }

        return count;
    }
};
