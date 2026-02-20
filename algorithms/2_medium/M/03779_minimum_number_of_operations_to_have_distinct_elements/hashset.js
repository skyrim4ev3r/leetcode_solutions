/**
 * @param {number[]} nums
 * @return {number}
 */
const minOperations = (nums) => {
    const len = nums.length;
    const seen = new Set();

    for (let i = len - 1; i >= 0; --i) {
        if (seen.has(nums[i])) {
            return Math.floor(i / 3) + 1;
        }
        seen.add(nums[i]);
    }

    return 0;
};
