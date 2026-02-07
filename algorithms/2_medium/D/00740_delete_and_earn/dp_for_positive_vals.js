/**
 * @param {number[]} nums
 * @return {number}
 */
const deleteAndEarn = (nums) => {
    const dp_len = 1 + Math.max(...nums);
    const dp = new Array(dp_len).fill(0);

    for (const num of nums) {
        dp[num] += num;
    }

    for (let i = 3; i < dp_len; i += 1) {
        dp[i] += Math.max(dp[i - 2], dp[i - 3]);
    }

    return Math.max(dp[dp_len - 1], dp[dp_len - 2]);
};
