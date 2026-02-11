class Solution {
    struct Compare {
        bool operator()(const auto&a, const auto& b) {
            return a.second < b.second;
        }
    };
public:
    static string reorganizeString(const string& s) {
        if (s.empty()) { return ""; }
        array<int, 26> freqs{};

        for (const auto& ch : s) {
            freqs[static_cast<size_t>(ch - 'a')] += 1;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> heap;

        for (size_t index{ 0 }; const auto& freq : freqs) {
            if (freq > 0) {
                heap.push({ static_cast<char>(index) + 'a', freq });
            }
            index += 1;
        }

        const size_t len{ s.size() };
        const size_t max_freq{ static_cast<size_t>(heap.top().second) };

        if (len - max_freq + 1 < max_freq) {
            return "";
        }

        string res;
        res.reserve(len);

        while (!heap.empty()) {
            auto [ch1, freq1] = heap.top();
            heap.pop();

            if (!res.empty() && res.back() == ch1) {
                const auto [ch2, freq2] = heap.top();
                heap.pop();
                res.push_back(ch2);
                if (freq2 > 1) {
                    heap.push({ch2, freq2 - 1});
                }
            }

            res.push_back(ch1);
            if (freq1 > 1) {
                heap.push({ch1, freq1 - 1});
            }
        }

        return res;
    }
};
