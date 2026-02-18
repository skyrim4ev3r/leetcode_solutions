const count_subarrays = (nums, start, end, max_lower_bound) => {
    if (start === end) {
        return 0;
    }

    const width = end - start;
    const total_possible_subarrays = width * (width + 1) / 2;
    let invalid_counts = 0;
    let left = start;

    for (let right = start; right < end; ++right) {
        if (nums[right] >= max_lower_bound) {
            const invalid_width = right - left;
            invalid_counts += Math.floor((invalid_width * (invalid_width + 1)) / 2);
            left = right + 1;
        }
    }

    let invalid_width = end - left;
    invalid_counts += Math.floor((invalid_width * (invalid_width + 1)) / 2);

    return total_possible_subarrays - invalid_counts;
};

/**
 * @param {number[]} nums
 * @param {number} max_lower_bound
 * @param {number} max_upper_bound
 * @return {number}
 */
const numSubarrayBoundedMax = (nums, max_lower_bound, max_upper_bound) => {
    const len = nums.length;
    let start = 0;
    let count = 0;

    for (let end = 0; end < len; ++end) {
        if (nums[end] > max_upper_bound) {
            count += count_subarrays(nums, start, end, max_lower_bound);
            start = end + 1;
        }
    }

    count += count_subarrays(nums, start, len, max_lower_bound);

    return count;
};
