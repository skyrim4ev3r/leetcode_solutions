class Solution {
public:
    vector<int> countBits(int n) {
        assert(n >= 0 && n != numeric_limits<int>::max());
        auto res = vector<int>(n + 1, 0);

        for (int i = 1; i <= n; i += 1) {
            res[i] = res[i >> 1] + (i & 1);
        }

        return res;
    }
};
