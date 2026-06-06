#define INT_BITS sizeof(int) * CHAR_BIT

int reverseBits(int n) {
    unsigned int res = 0u;
    unsigned int num = (unsigned int) n;

    for (size_t i = 0; i < INT_BITS; i += 1) {
        res = (res << 1) | (num & 1);
        num >>= 1;
    }

    return (int) res;
}
