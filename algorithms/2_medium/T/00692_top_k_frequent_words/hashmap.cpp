class Solution {
    static inline unordered_map<string, int> init_freqs(const vector<string>& words) {
        unordered_map<string, int> freqs{};
        for (const auto& w : words) {
            freqs[w] += 1;
        }
        return freqs;
    }
public:
    static vector<string> topKFrequent(vector<string>& words, int k) {
        const size_t k_usize{ static_cast<size_t>(k) };
        auto freqs = init_freqs(words);
        vector<pair<string, int>> freqs_vec(freqs.begin(), freqs.end());

        ranges::sort(freqs_vec, [](const auto& a, const auto& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            } else {
                return b.second < a.second;
            }
        });

        vector<string> res;

        for (const auto& [w, _] : freqs_vec) {
            res.push_back(w);

            if (res.size() == k_usize) {
                break;
            }
        }

        return res;
    }
};
