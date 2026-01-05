class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        const int dx {abs(fx - sx)};
        const int dy {abs(fy - sy)};

        if (dx == 0 && dy == 0 && t == 1) {
            return false;
        }

        return std::max(dx, dy) <= t;
    }
};
