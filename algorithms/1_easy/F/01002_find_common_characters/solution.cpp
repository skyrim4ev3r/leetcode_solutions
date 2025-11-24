class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        array<int, 26> max_freqs;
        for (int& freq : max_freqs) {
            freq = numeric_limits<int>::max();
        }

        for (const string& word : words) {
            array<int, 26> freqs{};

            for (const char& ch : word) {
                freqs[static_cast<size_t>(ch -'a')] += 1;
            }

            for (size_t i{0}; i < 26; ++i) {
                max_freqs[i]= std::min(max_freqs[i], freqs[i]);
            }
        }

        vector<string> res;
         for (size_t i{0}; i < 26; ++i) {
            const string temp(1, 'a' + static_cast<char>(i));

            for (int _{0}; _ < max_freqs[i]; _ += 1) {
                res.push_back(temp);
            }
         }

         return res;
    }
};
