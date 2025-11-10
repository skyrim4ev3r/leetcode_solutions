class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, tuple<int, size_t, size_t>> freqs{};

        for (size_t index{0}; const int &num: nums) {
            auto it{freqs.find(num)};

            if (it == freqs.end()) {
                freqs[num] = {1, index, index};
            } else {
                auto &[freq, left, right]{it->second};
                freq += 1;
                right = index;
            }

            index += 1;
        }

        int max_freq{0};
        size_t min_width{std::numeric_limits<size_t>::max()};

        for (auto &[_, data]: freqs) {
            auto &[freq, left, right] = data;

            if (freq > max_freq) {
                max_freq = freq;
                min_width = right - left + 1;
            } else if (freq == max_freq) {
                min_width = min(min_width, right - left + 1);
            }
        }

        return static_cast<int>(min_width);
    }
};
