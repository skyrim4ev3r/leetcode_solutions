class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        const size_t len{colors.size()};
        int count{0};

        for (size_t i{1}; i < len - 1; ++i) {
            if (colors[i] != colors[i + 1] && colors[i] != colors[i - 1]) {
                count += 1;
            }
        }

        if (colors[0] != colors[1] && colors[0] != colors[len - 1]) {
            count += 1;
        }

        if (colors[len - 1] != colors[len - 2] && colors[len - 1] != colors[0]) {
            count += 1;
        }

        return count;
    }
};
