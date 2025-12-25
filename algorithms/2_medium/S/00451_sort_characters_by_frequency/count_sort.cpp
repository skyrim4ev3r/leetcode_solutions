const size_t MAX_SIZE{128};

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> freqs(MAX_SIZE);
        string res;
        res.reserve(s.size());

        for (size_t i{0}; i < MAX_SIZE; ++i) {
            freqs[i].first = 0;
            freqs[i].second = static_cast<char>(i);
        }

        for (const char& ch : s) {
            freqs[static_cast<size_t>(ch)].first += 1;
        }

        freqs.erase(std::remove_if(freqs.begin(), freqs.end(), [](const auto& val) {
            return val.first == 0;
        }), freqs.end());

        sort(freqs.begin(), freqs.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        for (const auto& [count, ch] : freqs) {
            for (int i{0}; i < count; ++i) {
                res.push_back(ch);
            }
        }

        return res;
    }
};
