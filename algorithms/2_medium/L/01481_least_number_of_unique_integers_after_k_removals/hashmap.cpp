class Solution {
public:
    static int findLeastNumOfUniqueInts(const vector<int>& arr, int k) {
        const size_t len{ arr.size() };

        if (static_cast<size_t>(k) >= len) {
            return 0;
        }

        unordered_map<int, int> freqs{};

        for (const auto& a : arr) {
            freqs[a] += 1;
        }

        vector<int> freqs_val;
        freqs_val.reserve(freqs.size());

        for (const auto& f : freqs) {
            freqs_val.push_back(f.second);
        }

        ranges::sort(freqs_val, std::greater<>());

        while (k >= freqs_val.back()) {
            k -= freqs_val.back();
            freqs_val.pop_back();
        }

        return static_cast<int>(freqs_val.size());
    }
};
