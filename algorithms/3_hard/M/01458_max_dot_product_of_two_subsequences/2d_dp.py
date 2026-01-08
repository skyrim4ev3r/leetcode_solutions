class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        rows = len(nums1)
        cols = len(nums2)
        dp = [[0] * cols for _ in range(rows)]

        for i  in range(rows - 1, -1, -1):
            for j in range(cols -1, -1, -1):
                temp = nums1[i] * nums2[j]

                if i + 1 < rows and j + 1 < cols:
                    d = dp[i + 1][j]
                    r = dp[i][j + 1]
                    rd = dp[i + 1][j + 1]

                    dp[i][j] = max(temp, temp + rd, r, d)
                elif i + 1 < rows:
                    dp[i][j] = max(temp, dp[i + 1][j])
                elif j + 1 < cols:
                    dp[i][j] = max(temp, dp[i][j + 1])
                else:
                    dp[i][j] = temp

        return dp[0][0]
