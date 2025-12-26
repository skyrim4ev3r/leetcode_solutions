const size_t MAX_PLAYERS {100'001};

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        array<int, MAX_PLAYERS> lose_counts;
        std::fill(lose_counts.begin(), lose_counts.end(), -1);

        for (const auto& game : matches) {
            const size_t p1 {static_cast<size_t>(game[0])};
            const size_t p2 {static_cast<size_t>(game[1])};

            if (lose_counts[p1] == -1) {
                lose_counts[p1] = 0;
            }

            if (lose_counts[p2] == -1) {
                lose_counts[p2] = 1;
            } else {
                lose_counts[p2] += 1;
            }
        }

        vector<int> zero_lose_players{};
        vector<int> one_lose_players{};

        for (int i{0}; const int& lose_count : lose_counts) {
            if (lose_count == 1) {
                one_lose_players.push_back(i);
            } else if (lose_count == 0) {
                zero_lose_players.push_back(i);
            }

            i += 1;
        }

        return vector<vector<int>>{move(zero_lose_players), move(one_lose_players)};
    }
};
