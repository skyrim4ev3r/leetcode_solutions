/**
 * @param {number[]} nums
 * @return {number}
 */
const longestBalanced = (nums) => {
    const len = nums.length;
    let longest = 0;

    for (let i = 0; i < len; ++i) {
        const evens = new Set();
        const odds = new Set();

        for (let j = i; j < len; ++j) {
            if ((nums[j] & 1) === 0) {
                odds.add(nums[j]);
            } else {
                evens.add(nums[j]);
            }

            if (odds.size === evens.size) {
                longest = Math.max(longest, j - i + 1);
            }
        }
    }

    return longest;
};
