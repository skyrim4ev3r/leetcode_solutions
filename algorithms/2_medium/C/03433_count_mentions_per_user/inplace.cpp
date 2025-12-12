class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](const auto& a, const auto &b) {
            int ts_a{stoi(a[1])};
            int ts_b{stoi(b[1])};

            if (ts_a == ts_b) {
                return *a[0].begin() != 'M';
            }

            return ts_a < ts_b;
        });

        const size_t len{static_cast<size_t>(numberOfUsers)};
        vector<int> res(len , 0);
        vector<int> status(len , numeric_limits<int>::min());
        int count_all{0};

        for (const auto& event : events) {
            const int ts{stoi(event[1])};

            if (*event[0].begin() == 'O') {
                const size_t id{static_cast<size_t>(stoi(event[2]))};
                status[id] = ts + 60;
            } else if (*event[2].begin() == 'H') {
                for (size_t i{0}; i < len; ++i) {
                    if (status[i] <= ts) {
                        res[i] += 1;
                    }
                }
            } else if (*event[2].begin() == 'A') {
                count_all += 1;
            } else {
                istringstream ss{event[2]};
                string part;

                while (ss>>part) {
                    const size_t id{static_cast<size_t>(stoi(part.substr(2)))};
                    res[id] += 1;
                }
            }
        }

        if (count_all > 0) {
            for (size_t i{0}; i < len; ++i) {
                res[i] += count_all;
            }
        }

        return res;
    }
};
