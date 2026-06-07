class Solution {
public:
    static int rangeBitwiseAnd(const int signed_left, const int signed_right) {
        unsigned int shift = 0;
        unsigned int left = static_cast<unsigned int>(signed_left);
        unsigned int right = static_cast<unsigned int>(signed_right);

        while (right != left) {
            shift += 1;
            right = right >> 1u;
            left = left >> 1u;
        }

        return static_cast<int>(right << shift);
    }
};
