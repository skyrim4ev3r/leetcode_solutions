class Solution {
public:
    static vector<int> countPoints(const vector<vector<int>>& points, const vector<vector<int>>& queries) {
        vector<int> res{};
        res.reserve(queries.size());

        for (const auto& query : queries) {
            const int query_square {query[2] * query[2]};
            int count {0};

            for (const auto& point : points) {
                const int delta_x {query[0] - point[0]};
                const int delta_y {query[1] - point[1]};
                const int dis_square {delta_x * delta_x + delta_y * delta_y};

                if (dis_square <= query_square) {
                    count += 1;
                }
            }

            res.push_back(count);
        }

        return res;
    }
};
