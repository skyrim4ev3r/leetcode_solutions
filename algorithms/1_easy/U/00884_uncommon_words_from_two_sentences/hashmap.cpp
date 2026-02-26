class Solution {
    static inline void calc_freqs(const string &s, unordered_map<string, int>& freqs) {
        istringstream iss{ s };
        string part;

        while (iss >> part) {
            freqs[part] += 1;
        }
    }
public:
    static vector<string> uncommonFromSentences(const string& s1, const string& s2) {
        unordered_map<string, int> freqs;
        calc_freqs(s1, freqs);
        calc_freqs(s2, freqs);
        vector<string> res{};

        for (const auto& [word, freq] : freqs) {
            if (freq == 1) {
                res.push_back(word);
            }
        }

        return res;
    }
};
