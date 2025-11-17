class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        const size_t len{bits.size()};
        size_t index{0};
        bool last_is_zero{false};

        while (index < len) {
            if (bits[index] == 0) {
                last_is_zero = true;
                index += 1;
            } else {
                last_is_zero = false;
                index += 2;
            }
        }

        return last_is_zero;
    }
};
