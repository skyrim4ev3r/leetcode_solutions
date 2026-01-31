class Solution {
public:
    static vector<int> bestTower(const vector<vector<int>>& towers, vector<int>& center, int radius) {
        int selected_x{ -1 };
        int selected_y{ -1 };
        int selected_quality{ -1 };

        for (const auto& t : towers) {
            const int dist{ abs(t[0] - center[0]) + abs(t[1] - center[1]) };

            if (dist > radius) {
                continue;
            }

            if (selected_quality < t[2]) {
                selected_quality = t[2];
                selected_x = t[0];
                selected_y = t[1];
            } else if (selected_quality == t[2]) {
                if (t[0] < selected_x || (t[0] == selected_x && t[1] < selected_y)) {
                    selected_x = t[0];
                    selected_y = t[1];
                }
            }
        }

        return vector<int>{selected_x, selected_y};
    }
};
