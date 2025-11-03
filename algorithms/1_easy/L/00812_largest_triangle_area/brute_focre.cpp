class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double max{0.0};
        const size_t len{points.size()};

        for (size_t i{0}; i < len; ++i) {
            for (size_t j{i + 1}; j < len; ++j) {
                for (size_t k{j + 1}; k < len; ++k) {
                    // Calculate the area of the triangle using the determinant method
                    // Area = 0.5 * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|
                    double area = abs(points[i][0] * ( points[j][1] - points[k][1])
                                + points[j][0] * ( points[k][1] - points[i][1])
                                + points[k][0] * ( points[i][1] - points[j][1])
                                )/(double) 2.0;

                    max = std::max(max, area);
                }
            }
        }

        return max;
    }
};
