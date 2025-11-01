class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> words_count{};
        for (auto &response: responses) {
            unordered_set<string> unique_words_in_response;

            for (auto &word: response) {
                if (unique_words_in_response.insert(word).second) {
                    words_count[word] += 1;
                }
            }
        }

        int max_freq{0};
        string max_str{};
        for (const auto &pair: words_count) {
            if (pair.second > max_freq) {
                max_freq = pair.second;
                max_str = pair.first;
            } else if (pair.second == max_freq && pair.first < max_str) {
                max_str = pair.first;
            }
        }

        return max_str;
    }
};
