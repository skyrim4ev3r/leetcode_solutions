class Solution:
    def calculateScore(self, instructions: List[str], values: List[int]) -> int:
        n = len(instructions)
        curr_index = 0
        curr_score = 0
        seen = [False] * n

        while curr_index >= 0 and curr_index < n and not seen[curr_index]:
            seen[curr_index] = True

            if instructions[curr_index] == "jump":
                    curr_index = curr_index + values[curr_index]
            else:
                curr_score += values[curr_index]
                curr_index += 1

        return curr_score
