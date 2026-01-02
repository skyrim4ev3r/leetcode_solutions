class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int curr_height {0};
        int odd_count {0};
        int even_count {0};
        int curr_level {1};

        while (true) {
            if ((curr_level & 1) == 1) {
                odd_count += curr_level;
            } else {
                even_count += curr_level;
            }

            if (!((odd_count <= red && even_count <= blue) || (odd_count <= blue && even_count <= red))) {
                return curr_level - 1;
            }

            curr_level += 1;
        }
    }
};
