class Solution {
    struct VectorHasher {
        size_t operator()(const vector<int>& vec) const {
            size_t hash{0};
            for (const int &num: vec) {
                hash ^= static_cast<size_t>(std::hash<int>()(num)) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };
public:
    int equalPairs(vector<vector<int>>& grid) {
        const size_t n{grid.size()};
        unordered_map<vector<int>, int, VectorHasher> hashmap;
        vector<int> temp(n, 0);
        int count{0};

        for (size_t j{0}; j < n; ++j) {
            for (size_t i{0}; i < n; ++i) {
                temp[i] = grid[i][j];
            }

            hashmap[temp] += 1;
        }

        for (const auto &row: grid) {
            const auto it = hashmap.find(row);
            if (it != hashmap.end()) {
                count += it->second;
            }
        }

        return count;
    }
};
