int trap(int* height, int heightSize)
{
    size_t left = 0;
    size_t right = heightSize - 1;
    int curr_max_left = 0;
    int curr_max_right = 0;
    int total = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (curr_max_left > height[left]) {
                total += curr_max_left - height[left];
            } else {
                curr_max_left = height[left];
            }
            left += 1;
        } else {
            if (curr_max_right > height[right]) {
                total += curr_max_right - height[right];
            } else {
                curr_max_right = height[right];
            }
            right -= 1;
        }
    }

    return total;
}
