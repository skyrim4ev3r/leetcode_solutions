class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> hashmap{};
        vector<vector<string>> res{};

        for (string &word: strs) {
            vector<int> freqs(26, 0);

            for (const char &ch: word) {
                freqs[static_cast<size_t>(ch - 'a')] += 1;
            }

            string freqs_pattern{};

            for (size_t i{0}; i < 26; ++i) {
                if (freqs[i] > 0) {
                    freqs_pattern.push_back(static_cast<char>(i) + 'a');

                    if (freqs[i] > 1) {
                        freqs_pattern += to_string(freqs[i]);
                    }
                }
            }

            hashmap[freqs_pattern].push_back(move(word));
        }

        for (auto &[key, vec]: hashmap) {
            res.push_back(move(vec));
        }

        return res;
    }
};
