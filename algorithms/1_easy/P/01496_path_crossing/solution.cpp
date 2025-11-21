class Solution {
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& pair) const {
            auto hash1 = std::hash<T1>{}(pair.first);
            auto hash2 = std::hash<T2>{}(pair.second);
            return hash1 ^ hash2;
        }
    };
public:
    bool isPathCrossing(string path) {
        unordered_set<pair<int, int>, pair_hash> visited;
        visited.insert({0, 0});
        int i{0};
        int j{0};

        for (const char& ch : path) {
            switch (ch) {
                case 'N':
                    i -= 1;
                    break;
                case 'S':
                    i += 1;
                    break;
                case 'E':
                    j += 1;
                    break;
                case 'W':
                    j -= 1;
                    break;
                default:
                    break;
            }

            if (!visited.insert({i, j}).second) {
                return true;
            }
        }

        return false;
    }
};
