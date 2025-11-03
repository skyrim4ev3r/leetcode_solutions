class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        jewels_map = [False] * 128
        for jewel in jewels:
            jewels_map[ord(jewel)] = True

        count = 0

        for stone in stones:
            if jewels_map[ord(stone)]:
                count += 1

        return count
