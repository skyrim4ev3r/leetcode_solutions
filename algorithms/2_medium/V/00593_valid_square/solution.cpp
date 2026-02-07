class Solution {
    static inline int manhattan_dist(const vector<int>& p1,const vector<int>&  p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    static inline bool is_square(const array<int, 4>& sides,const array<int, 2>& diags) {
        return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3] && diags[0] == diags[1];
    }
public:
    static bool validSquare(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3, const vector<int>& p4) {
        const int d12{ manhattan_dist(p1, p2) };
        const int d13{ manhattan_dist(p1, p3) };
        const int d14{ manhattan_dist(p1, p4) };
        const int d23{ manhattan_dist(p2, p3) };
        const int d24{ manhattan_dist(p2, p4) };
        const int d34{ manhattan_dist(p3, p4) };

        if (d12 == 0 || d13 == 0 || d14 == 0 || d23 == 0 || d24 == 0 || d34 == 0) {
            return false;
        }

        array<int, 4> sides1{ d12, d13, d24, d34 };
        array<int, 2> diags1{ d14, d23 };

        array<int, 4> sides2{ d12, d14, d23, d34 };
        array<int, 2> diags2{ d13, d24 };

        array<int, 4> sides3{ d13, d14, d23, d24 };
        array<int, 2> diags3{ d13, d24 };

        return is_square(sides1, diags1) ||
               is_square(sides2, diags2) ||
               is_square(sides3, diags3);
    }
};
