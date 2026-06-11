void moveZeroes(int* nums, int nums_size)
{
    assert(nums != NULL);
    const ptrdiff_t len = nums_size;
    ptrdiff_t write_index = 0;

    for (ptrdiff_t read_index = 0; read_index < len; read_index += 1) {
        if (nums[read_index] != 0) {
            nums[write_index] = nums[read_index];
            write_index += 1;
        }
    }

    while (write_index < len) {
        nums[write_index] = 0;
        write_index += 1;
    }
}
