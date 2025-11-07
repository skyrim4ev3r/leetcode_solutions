class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res {};
        const size_t len{static_cast<size_t>(n)};
        const int half{n / 2};
        res.reserve(len);

        for (int i{1}; i <= half; ++i) {
            res.push_back(i);
            res.push_back(-1 * i);
        }

        if ((n & 1) == 1) {
            res.push_back(0);
        }

        return res;
    }
};
