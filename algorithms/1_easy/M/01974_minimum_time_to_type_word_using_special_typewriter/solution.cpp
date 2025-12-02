class Solution {
public:
    int minTimeToType(string word) {
        int circle_pos{0};
        int cost{0};

        for (const char& ch : word) {
            int new_pos{static_cast<int>(ch - 'a')};
            int curr_diff{abs(new_pos - circle_pos)};

            int min_cost = std::min(curr_diff, 26 - curr_diff);

            cost += min_cost + 1;
            circle_pos = new_pos;
        }

        return cost;
    }
};
