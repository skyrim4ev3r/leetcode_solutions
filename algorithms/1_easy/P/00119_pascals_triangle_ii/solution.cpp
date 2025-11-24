class Solution {
public:
    vector<int> getRow(int numIndex) {
        vector<int> res;
        res.push_back(1);
        const size_t len{static_cast<size_t>(numIndex) + 1};

        while (res.size() != len) {
            const size_t curr_len{res.size()};
            vector<int> tmp;
            tmp.reserve(curr_len + 1);

            for (size_t i{0}; i < curr_len + 1; ++i) {
                if (i == 0) {
                    tmp.push_back(res[0]);
                } else if (i == curr_len) {
                    tmp.push_back(res[i - 1]);
                } else {
                    tmp.push_back(res[i] + res[i - 1]);
                }
            }

            res = std::move(tmp);
        }

        return res;
    }
};
