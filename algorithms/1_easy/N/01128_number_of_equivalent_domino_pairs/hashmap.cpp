struct pair_hash {
    size_t operator()(const pair<char,char>& hs) const {
        return hs.first * 10 + hs.second;
    }
};
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<std::pair<char,char>, int, pair_hash> map{};

        for (const auto &d: dominoes) {
            const int min{std::min(d[0], d[1])};
            const int max{std::max(d[0], d[1])};

            map[make_pair(static_cast<char>(min), static_cast<char>(max))] += 1;
        }

        int sum{0};

        for (auto &it: map) {
            sum += (it.second * (it.second - 1)) / 2;
        }

        return sum;
    }
};
