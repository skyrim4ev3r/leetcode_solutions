class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> freqs{};
        int count{ 0 };

        for (const auto& num : nums) {
            const auto it1{ freqs.find(num - k) };
            if (it1 != freqs.end()) {
                count += it1->second;
            }

            const auto it2{ freqs.find(num + k) };
            if (it2 != freqs.end()) {
                count += it2->second;
            }

            freqs[num] += 1;
        }

        return count;
    }
};
