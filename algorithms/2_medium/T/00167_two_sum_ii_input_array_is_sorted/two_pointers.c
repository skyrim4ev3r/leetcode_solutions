/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbers_size, int target, int* return_size)
{
    *return_size = 2;
    size_t left = 0;
    size_t right = (size_t) numbers_size - 1;
    int* res = (int*) malloc(2 * sizeof(*res));

    while (left < right) {
        const int sum = numbers[left] + numbers[right];

        if (sum == target) {
            res[0] = (int) left + 1;
            res[1] = (int) right + 1;
            return res;
        }

        if (sum < target) {
            left += 1;
        } else {
            right -= 1;
        }
    }

    res[0] = -1;
    res[1] = -1;
    return res;
}
