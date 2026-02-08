class Solution {
    static void init_arr(array<array<array<array<bool, 10>, 10>, 10>, 10>& invalids) {
        for (size_t i{ 0 }; i < 10; ++i) {
            for (size_t j{ 0 }; j < 10; ++j) {
                for (size_t k{ 0 }; k < 10; ++k) {
                    for (size_t l{ 0 }; l < 10; ++l) {
                        invalids[i][j][k][l] = false;
                    }
                }
            }
        }
    }

    static inline tuple<size_t, size_t, size_t, size_t> get_indices(const string& s) {
        return {
            static_cast<size_t>(s[0] - '0'),
            static_cast<size_t>(s[1] - '0'),
            static_cast<size_t>(s[2] - '0'),
            static_cast<size_t>(s[3] - '0')
        };
    }
public:
    static int openLock(const vector<string>& deadends, const string& target) {
        array<array<array<array<bool, 10>, 10>, 10>, 10> invalids;
        init_arr(invalids);
        queue<string> q;
        string first_str{ "0000" };

        for (const auto& d : deadends) {
            const auto [i, j, k, l] = get_indices(d);
            invalids[i][j][k][l] = true;
        }

        if (invalids[0][0][0][0]) {
            return -1;
        }

        q.push(first_str);
        int turns{ 0 };

        while (!q.empty()) {
            const size_t len{ q.size() };
            for (size_t c{ 0 }; c < len; ++c) {
                const string curr{ q.front() };
                q.pop();

                if (curr == target) {
                    return turns;
                }

                string temp{ curr };

                for (size_t i{ 0 }; i < curr.size(); ++i) {
                    {
                        temp[i] = curr[i] == '9' ? '0' : curr[i] + 1;
                        const auto [i, j, k, l] = get_indices(temp);

                        if (!invalids[i][j][k][l]) {
                            invalids[i][j][k][l] = true;
                            q.push(temp);
                        }
                    }

                    {
                        temp[i] = curr[i] == '0' ? '9' : curr[i] - 1;
                        const auto [i, j, k, l] = get_indices(temp);

                        if (!invalids[i][j][k][l]) {
                            invalids[i][j][k][l] = true;
                            q.push(temp);
                        }
                    }

                    temp[i] = curr[i];
                }
            }

            turns += 1;
        }

        return -1;
    }
};
