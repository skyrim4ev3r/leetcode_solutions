class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, size_t> map{};
        vector<vector<string>> res{};

        for (string &word: strs) {
            string temp{};
            temp.reserve(word.size());
            array<int, 26> freqs{};

            for (const char &ch: word) {
                freqs[static_cast<size_t>(ch - 'a')] += 1;
            }

            for (size_t i{0}; i < 26; ++i) {
                char ch = static_cast<char>(i) + 'a';
                for (int freq{0}; freq < freqs[i]; ++freq) {
                    temp.push_back(ch);
                }
            }

            auto it = map.find(temp);
            if (it != map.end()) {
                res[it->second].push_back(move(word));
            } else {
                map[temp] = res.size();
                res.push_back(vector<string>{move(word)});
            }
        }

        return res;
    }
};
