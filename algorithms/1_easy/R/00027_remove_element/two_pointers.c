int removeElement(int* nums, int numsSize, int val)
{
    const size_t len = numsSize;
    size_t write_index = 0;

    for (size_t read_index = 0; read_index < len; read_index += 1) {
        if (nums[read_index] != val) {
            nums[write_index] = nums[read_index];
            write_index += 1;
        }
    }

    return (int) write_index;
}
