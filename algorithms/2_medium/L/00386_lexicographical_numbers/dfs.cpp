class Solution {
    static void dfs(vector<int>& res, int curr, const int n) {
        if (curr > n) {
            return;
        }

        res.push_back(curr);
        curr *= 10;

        for (int i = 0; i < 10; ++i) {
            dfs(res, curr + i, n);
        }
    }
public:
    static vector<int> lexicalOrder(int n) {
        assert(n > 0);
        auto res = vector<int>();
        res.reserve(n);

        for (int i = 1; i < 10; ++i) {
            dfs(res, i, n);
        }

        return res;
    }
};
