/**
 * @param {number} n
 * @return {number}
 */
const numTrees = (n) => {
    let dp = new Array(n + 1).fill(0);
    dp[0] = 1;
    dp[1] = 1;

    for (let i = 2; i <= n; i += 1) {
        for (let j = 1; j <= i; j += 1) {
            dp[i] += dp[i - j] * dp[j - 1];
        }
    }

    return dp[n];
};
