class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        players = [[i, s] for i, s in enumerate(score)]
        res = ["" for _ in score]
        players.sort(key=lambda x: x[1], reverse=True)

        medals = ["Gold Medal", "Silver Medal", "Bronze Medal"]
        for i in range(min(3, len(score))):
            res[players[i][0]] = medals[i]

        for i in range(3, len(score)):
            res[players[i][0]] = str(i + 1)

        return res
