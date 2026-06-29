typedef ptrdiff_t isize;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        const isize len = std::ssize(piles);
        assert(len % 3 == 0);
        ranges::sort(piles);

        isize j = len - 2;
        isize i = 0;
        int amount = 0;

        while (i < j) {
            amount += piles[j];
            j -= 2;
            i += 1;
        }

        return amount;
    }
};
