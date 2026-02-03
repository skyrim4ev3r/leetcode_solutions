class Solution {
    static inline bool check_mid(
        const vector<int>& position,
        const int mid,
        const int m,
        const size_t len
    ) {
        size_t pos{ 0 };

        for (int _i{ 0 }; _i < m - 1; _i += 1) {
            const int next_val{ position[pos] + mid };

            while (pos < len && position[pos] < next_val) {
                pos += 1;
            }

            if (pos == len) {
                return false;
            }
        }

        return true;
    }

public:
    int maxDistance(vector<int>& position, int m) {
        ranges::sort(position);
        const size_t len{ position.size() };
        int left{ 1 };
        int right{ (position[len - 1] - position[0]) / (m - 1) };

        while (left <= right) {
            const int mid{ left + (right - left) / 2 };

            if (check_mid(position, mid, m, len)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left - 1;
    }
};
