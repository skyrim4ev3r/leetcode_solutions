class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int dx1{points[1][0] - points[0][0]};
        int dy1{points[1][1] - points[0][1]};

        int dx2{points[2][0] - points[0][0]};
        int dy2{points[2][1] - points[0][1]};

        if ((dx1 == 0 && dx2 == 0) || (dx1 == 0 && dy1 == 0) || (dx2 == 0 && dy2 == 0)) {
            return false;
        }

        return dx1 == 0 || dx2 == 0 ||
              (static_cast<double>(dy1) / static_cast<double>(dx1) !=
               static_cast<double>(dy2) / static_cast<double>(dx2));
    }
};
