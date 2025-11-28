class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        sort(rectangles.begin(), rectangles.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int count{1};
        int prev_end{rectangles[0][3]};

        for (const auto& rectangle : rectangles) {
            if (rectangle[1] < prev_end) {
                prev_end = max(prev_end, rectangle[3]);
            } else {
                count += 1;

                if (count == 3) {
                    return true;
                }

                prev_end = rectangle[3];
            }
        }

        sort(rectangles.begin(), rectangles.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        count = 1;
        prev_end = rectangles[0][2];

        for (const auto& rectangle : rectangles) {
            if (rectangle[0] < prev_end) {
                prev_end = max(prev_end, rectangle[2]);
            } else {
                count += 1;

                if (count == 3) {
                    return true;
                }

                prev_end = rectangle[2];
            }
        }

        return false;
    }
};
