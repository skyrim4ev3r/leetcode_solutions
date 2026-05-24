int maxArea(const int* height, const int heightSize)
{
    if (height == NULL || heightSize < 2) {
        return 0;
    }

    int max_water = 0;
    size_t left = 0;
    size_t right = heightSize - 1;

    while (left < right) {
        const int hl = height[left];
        const int hr = height[right];
        const int min_height = hl < hr ? hl : hr;
        const int curr_water = (int)(right - left) * min_height;

        if (curr_water > max_water) {
            max_water = curr_water;
        }

        if (hl < hr) {
            left += 1;
        } else {
            right -= 1;
        }
    }

    return max_water;
}
