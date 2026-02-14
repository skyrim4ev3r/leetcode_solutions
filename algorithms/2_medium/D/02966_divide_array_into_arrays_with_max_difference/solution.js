/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[][]}
 */
const divideArray = (nums, k) => {
    const len = nums.length;

    if (len < 3 || len % 3 != 0) {
        return [];
    }

    nums.sort((a, b) => a - b);

    for (let i = 0; i < len; i += 3) {
        if (nums[i + 2] - nums[i] > k) {
            return [];
        }
    }

    const res = [];

    for (let i = 0; i < len; i += 3) {
        res.push(nums.slice(i, i + 3));
    }

    return res;
};
