/**
 * @param {number[]} nums
 * @return {number}
 */
const numberOfArithmeticSlices = (nums) => {
    const len = nums.length;
    let prev_diff = 0;
    let curr_len = 0;
    let count = 0;

    for (let i = 1; i < len; ++i) {
        if (nums[i] - nums[i - 1] === prev_diff) {
            curr_len += 1;
        } else {
            curr_len = 1;
        }

        count += curr_len - 1;
        prev_diff = nums[i] - nums[i - 1];
    }

    return count;
};
