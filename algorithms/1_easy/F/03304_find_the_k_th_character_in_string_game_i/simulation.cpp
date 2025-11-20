class Solution {
public:
    char kthCharacter(int k) {
        const size_t k_usize{static_cast<size_t>(k)};
        string res{"a"};

        while (res.size() < k_usize) {
            const size_t len{res.size()};
            res.resize(2 * len);

            for (size_t i{0}; i < len; ++i) {
                res[i + len] = res[i] + 1;
            }
        }

        return res[k_usize - 1];
    }
};
