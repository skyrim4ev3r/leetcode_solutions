/**
 * @param {number[]} nums
 * @return {number}
 */
const finalElement = (nums) => {
    return Math.max(nums[0], nums[nums.length - 1]);
};
