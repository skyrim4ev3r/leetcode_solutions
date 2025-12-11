class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int, int>> rows_map{};
        unordered_map<int, pair<int, int>> cols_map{};
        int count{0};

        for (const auto& building : buildings) {
            auto& row_map = rows_map[building[0]];
            if (row_map.first == 0) {
                row_map.first = building[1];
                row_map.second = building[1];
            } else {
                row_map.first = std::min(row_map.first, building[1]);
                row_map.second = std::max(row_map.second, building[1]);
            }

            auto& col_map = cols_map[building[1]];
            if (col_map.first == 0) {
                col_map.first = building[0];
                col_map.second = building[0];
            } else {
                col_map.first = std::min(col_map.first, building[0]);
                col_map.second = std::max(col_map.second, building[0]);
            }
        }

        for (const auto& building : buildings) {
            int i{building[0]};
            int j{building[1]};

            if (rows_map[i].first < j && rows_map[i].second > j && cols_map[j].first < i && cols_map[j].second > i) {
                count += 1;
            }
        }

        return count;
    }
};
