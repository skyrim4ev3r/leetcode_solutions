class Solution {
    inline int calculate_x_sum(const unordered_map<int, int> &freqs, const size_t &x) {
        vector<pair<int, int>> freqs_vec{freqs.begin(), freqs.end()};
        sort(freqs_vec.begin(), freqs_vec.end(), [](auto a, auto b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }

            return a.second > b.second;
        });

        const size_t max_size{min(x, freqs_vec.size())};

        int sum{0};

        for (size_t i{0}; i < max_size; ++i) {
            sum += freqs_vec[i].first * freqs_vec[i].second;
        }

        return sum;
    }

public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        const size_t k_usize{static_cast<size_t>(k)};
        const size_t x_usize{static_cast<size_t>(x)};
        const size_t len{nums.size()};
        unordered_map<int, int> freqs{};
        vector<int> res;
        res.reserve(len - k_usize + 1);
        size_t left{0};

        for (size_t i{0}; i < k_usize; ++i) {
            freqs[nums[i]] += 1;
        }

        res.push_back(calculate_x_sum(freqs, x_usize));

        for (size_t right{k_usize}; right < len; ++right) {
            freqs[nums[right]] += 1;

            auto it = freqs.find(nums[left]);
            left += 1;
            it->second -= 1;
            if (it->second == 0) {
                freqs.erase(it);
            }

            res.push_back(calculate_x_sum(freqs, x_usize));
        }

        return res;
    }
};
