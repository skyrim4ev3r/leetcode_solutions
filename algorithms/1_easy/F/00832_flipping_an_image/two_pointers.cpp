class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image) {
            size_t right {row.size() - 1};
            size_t left {0};

            while (left < right) {
                const int temp {row[left]};
                row[left] = row[right];
                row[right] = temp;

                row[right] = row[right] == 1 ? 0 : 1;
                row[left] = row[left] == 1 ? 0 : 1;

                left += 1;
                right -= 1;
            }

            if (left == right) {
                row[left] = row[left] == 1 ? 0 : 1;
            }
        }

        return image;
    }
};
