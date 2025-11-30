class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string curr_word{};
        unordered_set<string> banned_set{banned.begin(), banned.end()};
        unordered_map<string, int> freqs{};

        for (const char& ch : paragraph) {
            if (ch >= 'a' && ch <= 'z') {
                curr_word.push_back(ch);
            } else if (ch >= 'A' && ch <= 'Z') {
                curr_word.push_back(ch + 32);
            } else {
                if (curr_word.size() > 0 && !banned_set.contains(curr_word)) {
                    freqs[curr_word] += 1;
                }

                curr_word.clear();
            }
        }

        if (curr_word.size() > 0 && !banned_set.contains(curr_word)) {
            freqs[curr_word] += 1;
        }

        string res{};
        int max_freq{0};

        for (auto& [word, freq] : freqs) {
            if (freq > max_freq) {
                res = move(word);
                max_freq = freq;
            }
        }

        return res;
    }
};
