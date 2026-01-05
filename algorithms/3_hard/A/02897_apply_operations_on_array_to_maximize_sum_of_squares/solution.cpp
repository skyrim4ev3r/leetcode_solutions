class Solution {
public:
    int maxSum(const vector<int>& nums, int k) {
        array<int, 32> freqs_bits;
        const long long MOD_TO {1'000'000'007};
        long long res {0};
        ranges::fill(freqs_bits, 0);

        for (int num : nums) {
            size_t freqs_index {0};

            while (num > 0) {
                if ((num & 1) == 1) {
                    freqs_bits[freqs_index] += 1;
                }

                num = num >> 1;
                freqs_index += 1;
            }
        }

        const int max_freq {*std::max_element(freqs_bits.cbegin(), freqs_bits.cend())};
        const int number_of_iter {std::min(max_freq, k)};

        for (int x {0}; x < number_of_iter; ++x) {
            long long curr {0};

            for (auto it {freqs_bits.rbegin()}; it != freqs_bits.rend(); ++it) {
                curr = curr << 1;

                if (*it > 0) {
                    *it -= 1;
                    curr |= 1;
                }
            }

            res = (res + curr * curr) % MOD_TO;
        }

        return static_cast<int>(res);
    }
};
