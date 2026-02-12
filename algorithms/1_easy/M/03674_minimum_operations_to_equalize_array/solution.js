/**
 * @param {number[]} nums
 * @return {number}
 */
const minOperations = (nums) => {
    return (nums.filter(x => x != nums[0]).length != 0) ? 1 : 0;
};
