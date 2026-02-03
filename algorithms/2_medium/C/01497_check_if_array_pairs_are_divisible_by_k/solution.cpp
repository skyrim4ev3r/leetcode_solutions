class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if (k == 1) {
            return true;
        }

        const size_t k_usize{ static_cast<size_t>(k) };
        vector<int> reminders_freqs(k_usize, 0);

        for (const auto& a : arr) {
            const int rem{ a % k };
            const int index{ rem < 0 ? rem + k : rem };
            reminders_freqs[static_cast<size_t>(index)] += 1;
        }

        // if first freq be even
        // then for even values of k
        // freq[(k / 2)] have to be even too
        // so both edge cases are checked!
        if ((reminders_freqs[0] & 1) == 1) {
            return false;
        }

        const size_t half{ k_usize / 2 };
        for (size_t i{ 1 }; i <= half; ++i) {
            const size_t other{ k_usize - i };

            if (reminders_freqs[i] != reminders_freqs[other]) {
                return false;
            }
        }

        return true;
    }
};
