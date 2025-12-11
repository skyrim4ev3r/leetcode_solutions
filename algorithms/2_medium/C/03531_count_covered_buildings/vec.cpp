class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        const size_t len{static_cast<size_t>(n + 1)};
        vector<pair<int, int>> rows_map(len, {-1, -1});
        vector<pair<int, int>> cols_map(len, {-1, -1});
        int count{0};

        for (const auto& building : buildings) {
            const int x{building[0]};
            const int y{building[1]};
            const size_t i{static_cast<size_t>(x)};
            const size_t j{static_cast<size_t>(y)};

            if (rows_map[i].first == -1) {
                rows_map[i].first = y;
                rows_map[i].second = y;
            } else {
                rows_map[i].first = std::min(rows_map[i].first, y);
                rows_map[i].second = std::max(rows_map[i].second,y);
            }

            if (cols_map[j].first == -1) {
                cols_map[j].first = x;
                cols_map[j].second = x;
            } else {
                cols_map[j].first = std::min(cols_map[j].first, x);
                cols_map[j].second = std::max(cols_map[j].second, x);
            }
        }

        for (const auto& building : buildings) {
            const int x{building[0]};
            const int y{building[1]};
            const size_t i{static_cast<size_t>(x)};
            const size_t j{static_cast<size_t>(y)};

            if (rows_map[i].first < y && rows_map[i].second > y && cols_map[j].first < x && cols_map[j].second > x) {
                count += 1;
            }
        }

        return count;
    }
};
