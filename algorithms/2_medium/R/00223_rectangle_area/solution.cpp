class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        const int area1{(ax2 - ax1) * (ay2 - ay1)};
        const int area2{(bx2 - bx1) * (by2 - by1)};

        const int max_x1{std::max(ax1, bx1)};
        const int max_y1{std::max(ay1, by1)};

        const int min_x2{std::min(ax2, bx2)};
        const int min_y2{std::min(ay2, by2)};

        if (min_x2 > max_x1 && min_y2 > max_y1) {
            const int shared_area{(min_y2 - max_y1) * (min_x2 - max_x1)};
            return area1 + area2 - shared_area;
        }

        return area1 + area2;
    }
};
