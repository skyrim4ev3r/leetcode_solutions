struct info {
    size_t index;
    int score;
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        const size_t len{score.size()};
        vector<info> players(score.size());

        for (size_t i{0}; i < len; ++i) {
            players[i].index = i;
            players[i].score = score[i];
        }

        sort(players.begin(), players.end(), [](info &a, info &b){
            return a.score > b.score;
        });

        vector<string> res(score.size(), "");        

        for (size_t i{0}; i < std::min(static_cast<size_t>(3), len); ++i) {
            if (i == 0) res[players[i].index] = "Gold Medal";
            else if (i == 1) res[players[i].index] = "Silver Medal";
            else if (i == 2) res[players[i].index] = "Bronze Medal";
        }

        for (size_t i{3}; i < len; ++i) {
            res[players[i].index] = std::to_string(i + 1);
        }
        
        return res;
    }
};
