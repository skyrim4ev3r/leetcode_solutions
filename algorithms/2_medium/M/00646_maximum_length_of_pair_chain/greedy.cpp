class Solution {
public:
    static int findLongestChain(vector<vector<int>>& pairs) {
        ranges::sort(pairs, [](const auto& a, const auto& b) { return a[1] < b[1]; });

        int curr_end{ pairs[0][1] };
        int count{ 1 };

        for (const auto& p : pairs) {
            if (p[0] > curr_end) {
                curr_end = p[1];
                count += 1;
            }
        }

        return count;
    }
};
