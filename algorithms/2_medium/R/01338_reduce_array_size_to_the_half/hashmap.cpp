class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freqs {};

        for (const int& num : arr) {
            freqs[num] += 1;
        }

        const int target {static_cast<int>((arr.size() + 1) / 2)};
        int curr_count {0};
        int res {0};
        const size_t freqs_len {freqs.size()};
        vector<int> freqs_vec;
        freqs_vec.reserve(freqs_len);

        for (const auto& freq : freqs) {
            freqs_vec.push_back(freq.second);
        }

        ranges::sort(freqs_vec);

        for (size_t i {freqs_len - 1}; i < freqs_len; --i) {
            curr_count += freqs_vec[i];
            res += 1;

            if (curr_count >= target) {
                return res;
            }
        }

        return -1;
    }
};
