class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        if not tokens:
            return 0

        curr_score = 0
        max_score = 0
        tokens.sort()
        left = 0
        right = len(tokens) - 1

        while left <= right:
            if power >= tokens[left]:
                power -= tokens[left]
                curr_score += 1
                max_score = max(max_score, curr_score)
                left += 1
            elif left < right and curr_score > 0:
                power += tokens[right]
                curr_score -= 1
                right -= 1
            else:
                break

        return max_score
