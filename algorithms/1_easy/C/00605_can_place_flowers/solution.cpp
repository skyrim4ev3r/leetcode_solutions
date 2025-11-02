class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }

        const size_t len{flowerbed.size()};
        size_t curr_index{0};

        while (curr_index < len) {

            if (flowerbed[curr_index] == 1 
                || (curr_index > 0 && flowerbed[curr_index - 1] == 1)
                || (curr_index < (len - 1) && flowerbed[curr_index + 1] == 1))
            {
                curr_index += 1;
            } else {
                n -= 1;

                if (n == 0) {
                    return true;
                }

                curr_index += 2;
            }
        }

        return false;
    }
};
