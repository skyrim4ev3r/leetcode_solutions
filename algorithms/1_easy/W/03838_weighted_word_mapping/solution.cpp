class Solution {
public:
    static string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        res.reserve(words.size());

        for (const auto& word : words) {
            int curr_sum = 0;

            for (const auto ch : word) {
                assert(ch >= 'a' && ch <= 'z');
                curr_sum += weights[ch - 'a'];
            }

            const int reversed_offset = 25 - (curr_sum % 26);
            res.push_back(reversed_offset + 'a');
        }

        return res;
    }
};
