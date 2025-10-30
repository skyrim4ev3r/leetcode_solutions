class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, size_t> map{};
        vector<vector<string>> res{};

        for (string &word: strs) {
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());

            auto it = map.find(sorted_word);
            if (it != map.end()) {
                res[it->second].push_back(move(word));
            } else {
                map[sorted_word] = res.size();
                res.push_back(vector<string>{move(word)});
            }
        }

        return res;
    }
};
