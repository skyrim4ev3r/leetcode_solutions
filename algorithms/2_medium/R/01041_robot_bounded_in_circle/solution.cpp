array<array<int, 2>, 4> DIRECTIONS{ array<int, 2>{0, 1}, {1, 0}, {0, -1}, {-1, 0} };

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x{ 0 };
        int y{ 0 };
        size_t curr_dir_index{ 0 };

        for (const auto& ch: instructions) {
            if (ch == 'G') {
                const auto& [dx, dy] = DIRECTIONS[curr_dir_index];
                y += dy;
                x += dx;
            } else if (ch == 'L') {
                curr_dir_index = curr_dir_index == 0 ? 3 : curr_dir_index - 1;
            } else {
                curr_dir_index = curr_dir_index == 3 ? 0 : curr_dir_index + 1;
            }
        }

        return (x == 0 && y == 0) || curr_dir_index != 0;
    }
};
