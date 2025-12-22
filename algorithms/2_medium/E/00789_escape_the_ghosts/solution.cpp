class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int player_dist{abs(target[0]) + abs(target[1])};

        for (const auto& ghost : ghosts) {
            int ghost_dist{abs(target[0] - ghost[0]) + abs(target[1] - ghost[1])};

            if (ghost_dist <= player_dist) {
                return false;
            }
        }

        return true;
    }
};
