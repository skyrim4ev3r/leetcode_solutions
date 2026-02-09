class Solution {
public:
    int maximumScore(int a, int b, int c) {
        array<int, 3> stones{ a, b, c };
        ranges::sort(stones);

        const auto [min, mid, max] = stones;

        return std::min((max + min + mid) / 2, min + mid);
    }
};
