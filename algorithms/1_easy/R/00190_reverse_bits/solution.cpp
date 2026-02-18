class Solution {
public:
    static int32_t reverseBits(int32_t n) {
        int32_t res{ 0 };

        for (int32_t i{ 0 }; i < 32; ++i) {
            res = (res << 1) | (n & 1);
            n = n >> 1;
        }

        return res;
    }
};

