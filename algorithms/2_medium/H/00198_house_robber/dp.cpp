class Solution {
public:
    static int rob(const vector<int>& nums) {
        int curr = 0;
        int prev = 0;
        int prev_prev = 0;

        for (const auto num : nums) {
            const int next = num + std::max(prev, prev_prev);
            prev_prev = prev;
            prev = curr;
            curr = next;
        }

        return std::max(curr, prev);
    }
};
