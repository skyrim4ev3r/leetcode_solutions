class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
       if (a == e) {
            if (c == a && d > min(b, f) && d < max(b, f)) {
                return 2;
            }

            return 1;
        }

        if (b == f) {
            if (b == d && c > min(a, e) && c < max(a, e)) {
                return 2;
            }

            return 1;
        }

        if (abs(e - c) == abs(f - d)) {
            if (abs(a - c) == abs(b - d)) {
                if (a > min(c, e) && a < max(c, e) && b > min(d, f) && b < max(d, f)) {
                    return 2;
                }
            }

            return 1;
        }

        return 2;
    }
};
