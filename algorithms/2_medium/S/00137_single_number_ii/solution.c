#define INT_BITS (sizeof(int) * CHAR_BIT)

int singleNumber(int* nums, int numsSize)
{
    const size_t len = numsSize;
    unsigned int res = 0;
    unsigned int freqs_bits[INT_BITS] = { 0 };

    for (size_t i = 0; i < len; i += 1) {
        const unsigned int num = (unsigned int) nums[i];

        for (size_t bit_pos = 0; bit_pos < INT_BITS; bit_pos += 1) {
            const unsigned int mask = 1u << bit_pos;

            if ((num & mask) != 0) {
                freqs_bits[bit_pos] += 1;
            }
        }
    }

    for (size_t bit_pos = 0; bit_pos < INT_BITS; bit_pos += 1) {
        if (freqs_bits[bit_pos] % 3 != 0) {
            const unsigned int mask = 1u << bit_pos;
            res |= mask;
        }
    }

    return (int) res;
}
