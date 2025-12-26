class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> players_map{};

        for (const auto& game : matches) {
            players_map[game[0]];
            players_map[game[1]] += 1;
        }

        vector<int> zero_lose_players{};
        vector<int> one_lose_players{};

        for (const auto& [player, lose_count] : players_map) {
            if (lose_count == 1) {
                one_lose_players.push_back(player);
            } else if (lose_count == 0) {
                zero_lose_players.push_back(player);
            }
        }

        ranges::sort(zero_lose_players);
        ranges::sort(one_lose_players);

        return vector<vector<int>>{move(zero_lose_players), move(one_lose_players)};
    }
};
