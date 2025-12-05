class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> freqs1{};
        unordered_map<string, int> freqs2{};
        int count{0};

        for (const string& word : words1) {
            freqs1[word] += 1;
        }

        for (const string& word : words2) {
            freqs2[word] += 1;
        }

        for (const auto& [word, freq] : freqs1) {
            if (freq == 1) {
                const auto& it = freqs2.find(word);

                if (it != freqs2.end() && it->second == 1) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
