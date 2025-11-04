// Time Complexity: O(N) - Ignore the nested loops; the overall complexity is linear
// Follow i and j's changing behavior for clarification.
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int max_energy_absorb = INT_MIN;
        const size_t len{energy.size()};
        const size_t k_usize{static_cast<size_t>(k)};

        for (size_t i{0}; i < k_usize; ++i) {
            int sum{0};

            for (size_t j{i}; j < len; j += k_usize) {
                if (sum < 0) {
                    sum = 0;
                }

                sum += energy[j];
            }

            max_energy_absorb = max(max_energy_absorb, sum);
        }

        return max_energy_absorb;
    }
};
