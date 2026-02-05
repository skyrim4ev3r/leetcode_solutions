const double VALID_DIFF{ 0.00001 };

class Solution {
    static inline double calc_area_under_line(const vector<array<int, 2>>& squares, const double& y_line) {
        double area{ 0.0 };

        for (const auto& s : squares) {
            const double y{ static_cast<double>(s[0]) };
            const double h{ static_cast<double>(s[1]) };

            if (y < y_line) {
                const double upper_y{ std::min(y_line, y + h) };
                area += (upper_y - y) * h;
            }
        }

        return area;
    }

public:
    static double separateSquares(const vector<vector<int>>& squares) {
        vector<array<int, 2>> new_squares;
        new_squares.reserve(squares.size());
        double low{ 0 };
        double high{ 0 };
        double total_area{ 0 };

        for (const auto& s : squares) {
            new_squares.push_back({ s[1], s[2] });
            high = std::max(high, static_cast<double>(s[1] + s[2]));
            total_area += std::pow(static_cast<double>(s[2]), 2) ;
        }

        while (high - low > VALID_DIFF) {
            const double mid{ low + (high - low) / 2.0 };
            const double area_under_line{ calc_area_under_line(new_squares, mid) };

            if (area_under_line < total_area / 2.0) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return low;
    }
};
