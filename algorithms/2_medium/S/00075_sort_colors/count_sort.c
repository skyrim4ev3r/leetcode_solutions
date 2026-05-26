#define COLOR_COUNT 3

void sortColors(int* nums, int numsSize) {
    const size_t len = numsSize;
    int freqs[COLOR_COUNT] = { 0 };

    for (size_t i = 0; i < len; i += 1) {
        freqs[(size_t) nums[i]] += 1;
    }

    size_t nums_index = 0;
    for (size_t i = 0; i < COLOR_COUNT; i += 1) {
        const int freq = freqs[i];
        const int color = (int) i;
        for (int k = 0; k < freq; k += 1) {
            nums[nums_index] = color;
            nums_index += 1;
        }
    }
}
