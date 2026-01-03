class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> freqs {};

        for (const int& num : nums) {
            auto& freq {freqs[num]};
            freq += 1;

            if (freq > 2) {
                return false;
            }
        }

        return true;
    }
};
