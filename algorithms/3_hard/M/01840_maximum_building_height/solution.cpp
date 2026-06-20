typedef ptrdiff_t isize;

class Solution {
    static inline int clac_max(const pair<int, int> p1, const pair<int, int> p2) {
        int i1 = p1.first, h1 = p1.second, i2 = p2.first, h2 = p2.second;

        if (h1 < h2) {
            const int diff = h2 - h1;
            h1 += diff;
            i1 += diff;
        } else {
            const int diff = h1 - h2;
            h2 += diff;
            i2 -= diff;
        }

        const int space_in_between = i2 - i1 - 1;

        return ((space_in_between + 1) / 2) + h1;
    }

public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        const isize restrictions_len = std::ssize(restrictions);
        assert(n >= 2 && n > restrictions_len);
        if (restrictions_len == 0) { return n - 1; }
        auto data = vector<pair<int, int>>();
        data.reserve(restrictions_len  + 1);

        data.push_back({1,0});
        for (isize i = 0; i < restrictions_len; i += 1) {
            data.push_back({restrictions[i][0], restrictions[i][1]});
        }

        sort(data.begin(), data.end());

        if (data.back().first != n) {
            data.push_back({ n, n - 1 });
        }

        const isize len = std::ssize(data);

        for (isize i = 1; i < len; i += 1) {
            const int diff_i = data[i].first - data[i - 1].first;
            data[i].second = std::min(data[i].second, data[i - 1].second + diff_i);
        }

        for (isize i = len - 2; i >= 0; i -= 1) {
            const int diff_i = data[i + 1].first - data[i].first;
            data[i].second = std::min(data[i].second, data[i + 1].second + diff_i);
        }

        int max = 0;

        for (isize i = 1; i < len; i += 1) {
            max = std::max(max, clac_max(data[i - 1], data[i]));
        }

        return max;
    }
};
