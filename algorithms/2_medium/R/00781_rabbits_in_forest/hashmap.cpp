class Solution {
public:
    static int numRabbits(const vector<int>& answers) {
        unordered_map<int, int> freqs{};
        int count{ 0 };

        for (const auto& a : answers) {
            freqs[a] += 1;
        }

        for (const auto& [val, freq] : freqs) {
            const int group_count{ (freq + val) / (val + 1) };
            count += group_count * (val + 1);
        }

        return count;
    }
};
