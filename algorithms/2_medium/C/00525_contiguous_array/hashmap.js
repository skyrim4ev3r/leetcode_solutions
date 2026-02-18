/**
 * @param {number[]} nums
 * @return {number}
 */
const findMaxLength = (nums) => {
    const len = nums.length;
    const diff_to_len_map = {};
    let count_zeros = 0;
    let count_ones = 0;
    let longest = 0;

    diff_to_len_map[0] = 0;

    for (let i = 0; i < len; ++i) {
        if (nums[i] === 0) {
            count_ones += 1;
        } else {
            count_zeros += 1;
        }

        const curr_diff = count_ones - count_zeros;

        if (curr_diff in diff_to_len_map) {
            longest = Math.max(longest, i + 1 - diff_to_len_map[curr_diff]);
        } else {
            diff_to_len_map[count_ones - count_zeros] = i + 1;
        }
    }

    return longest;
};
