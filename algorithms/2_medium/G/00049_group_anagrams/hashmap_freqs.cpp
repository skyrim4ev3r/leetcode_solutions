class Solution {
    struct VectorHasher {
        size_t operator()(const vector<int>& vec) const {
            size_t hash{0};
            for (const int &num: vec) {
                hash ^= static_cast<size_t>(std::hash<int>()(num)) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<vector<int>, size_t, VectorHasher> hashmap{};
        vector<vector<string>> res{};

        for (string &word: strs) {
            vector<int> freqs(26, 0);

            for (const char &ch: word) {
                freqs[static_cast<size_t>(ch - 'a')] += 1;
            }

            string freqs_pattern{};

            auto it = hashmap.find(freqs);
            if (it == hashmap.end()) {
                hashmap[freqs] = res.size();
                res.push_back(vector<string>{move(word)});
            } else {
                res[it->second].push_back(move(word));
            }
        }

        return res;
    }
};
