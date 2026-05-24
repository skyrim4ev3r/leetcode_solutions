int removeDuplicates(int* nums, int numsSize) {
    const size_t len = numsSize;
    size_t write_index = 1;

    for (size_t read_index = 1; read_index < len; read_index += 1) {
        if (nums[read_index] != nums[read_index - 1]) {
            nums[write_index] = nums[read_index];
            write_index += 1;
        }
    }

    return (int) write_index;
}
