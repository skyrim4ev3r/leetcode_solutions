class Solution {
    struct ComparePair {
        bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };

    static inline unordered_map<string, int> init_freqs(const vector<string>& words) {
        unordered_map<string, int> freqs{};
        for (const auto& w : words) {
            freqs[w] += 1;
        }
        return freqs;
    }

    static inline priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> init_freqs_heap_top_k(
        const unordered_map<string, int>& freqs,
        size_t k
    ) {
        priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> freqs_heap{};

        for (const auto& [w, freq] : freqs) {
            freqs_heap.push(pair<string, int>{w, freq});

            if (freqs_heap.size() > k) {
                freqs_heap.pop();
            }
        }

        return freqs_heap;
    }

public:
    static vector<string> topKFrequent(vector<string>& words, int k) {
        auto freqs{ init_freqs(words) };
        auto freqs_heap{ init_freqs_heap_top_k(freqs, static_cast<size_t>(k)) };
        vector<string> res;
        res.reserve(static_cast<size_t>(k));

        while (!freqs_heap.empty()) {
            res.push_back(freqs_heap.top().first);
            freqs_heap.pop();
        }

        ranges::reverse(res);

        return res;
    }
};
