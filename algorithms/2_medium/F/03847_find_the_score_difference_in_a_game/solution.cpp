class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        const size_t len{ nums.size() };
        array<int, 2> points{};
        size_t curr_player{ 0 };

        for (size_t i{ 0 }; i < len; ++i) {
            if (i % 6 == 5) {
                curr_player = (curr_player + 1) % 2;
            }

            if ((nums[i] & 1) == 1) {
                curr_player = (curr_player + 1) % 2;
            }

            points[curr_player] += nums[i];
        }

        return points[0] - points[1];
    }
};
