/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
const countElements = (nums, k) => {
    const len = nums.length;

    if (k == 0) {
        return len;
    }

    nums.sort((a, b) => a - b);
    let possible_res = len - 1 - k;

    while (possible_res >= 0 && nums[possible_res] === nums[possible_res + 1]) {
        possible_res -= 1;
    }

    return possible_res + 1;
};
