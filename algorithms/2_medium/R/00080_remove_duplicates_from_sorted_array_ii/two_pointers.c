int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize < 3) {
        return numsSize;
    }

    const size_t len = numsSize;
    size_t write_index = 2;

    for (size_t read_index = 2; read_index < len; read_index += 1) {
        if (nums[read_index] != nums[write_index - 2]) {
            nums[write_index] = nums[read_index];
            write_index += 1;
        }
    }

    return (int) write_index;
}