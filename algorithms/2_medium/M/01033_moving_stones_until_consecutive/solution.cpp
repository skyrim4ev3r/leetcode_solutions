class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        array<int, 3> nums{ a, b, c };
        ranges::sort(nums);

        const int diff1{ nums[1] - nums[0] - 1 };
        const int diff2{ nums[2] - nums[1] - 1 };

        const int min_move{ (diff1 == 0 && diff2 == 0) ? 0 : ((diff1 > 1 && diff2 > 1) ? 2 : 1) };
        const int max_move{ diff1 + diff2 };

        return vector<int>{min_move, max_move};
    }
};
