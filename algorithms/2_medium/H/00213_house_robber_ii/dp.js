/**
 * @param {number[]} nums
 * @return {number}
 */
const rob_helper = (dp) => {
    const n = dp.length;

    dp[2] += dp[0];

    for (let i = 3; i < n; i += 1) {
        dp[i] += Math.max(dp[i - 2], dp[i - 3]);
    }

    return Math.max(dp[n - 1], dp[n - 2]);
}

const rob = (nums) => {
    const n = nums.length;

    if (n <= 3) {
        return Math.max(...nums);
    }

    let dp1 = nums.slice(1)
    let dp2 = nums.slice(0, n - 1);

    const max_dp1 = rob_helper(dp1);
    const max_dp2 = rob_helper(dp2);

    return Math.max(max_dp1, max_dp2);
};
