constexpr size_t INT_BITS = sizeof(int) * CHAR_BIT;

class Solution {
public:
    int reverseBits(int n) {
        unsigned int res = 0u;
        unsigned int num = static_cast<unsigned int>(n);

        for (size_t i = 0; i < INT_BITS; i += 1) {
            res = (res << 1) | (num & 1);
            num >>= 1;
        }

        return (int) res;
    }
};
