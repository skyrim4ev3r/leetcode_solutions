class Solution {
public:
    int countPoints(string rings) {
        const size_t len{rings.size()};
        const array<char, 3> colors{1, 2, 4};

        array<char, 10> rods{};

        for (size_t i{0}; i < len; i += 2) {
            const size_t rod_index{static_cast<size_t>(rings[i + 1] - '0')};
            size_t color_index = 0;

            if (rings[i] == 'R') {
                color_index = 0;
            } else if (rings[i] == 'G') {
                color_index = 1;
            } else {
                color_index = 2;
            }

            rods[rod_index] |= colors[color_index];
        }

        return count(rods.begin(), rods.end(), 7);
    }
};
