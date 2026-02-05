class Solution {
public:
    long long countPairs(const vector<string>& words) {
        unordered_map<string, int> freqs{};

        for (const auto& word : words) {
            const size_t word_len{ word.size() };
            string adj_diff(word_len, '0');

            adj_diff[0] = ((word[0] - 'a') - (word[word_len - 1] - 'a') + 26) % 26;

            for (size_t i{ 1 }; i < word_len; ++i) {
                adj_diff[i] = ((word[i] - 'a') - (word[i - 1] - 'a') + 26) % 26;
            }

            freqs[adj_diff] += 1;
        }

        long long count{ 0 };

        for (const auto& [_, freq] : freqs) {
            count += (static_cast<long long>(freq) * (static_cast<long long>(freq) - 1)) / 2;
        }

        return count;
    }
};
