class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {

        const size_t n{a.size()};
        vector<int> res{};
        res.reserve(n);
        int common{0};

        for (size_t i{0}; i < n; ++i) {
            size_t index_num_a = static_cast<size_t>(abs(a[i])) - 1;
            size_t index_num_b = static_cast<size_t>(b[i]) - 1;

            if (a[index_num_a] < 0) {
                common += 1;
            } else {
                a[index_num_a] *= -1;
            }

            if (a[index_num_b] < 0) {
                common += 1;
            } else {
                a[index_num_b] *= -1;
            }

            res.push_back(common);
        }

        return res;
    }
};
