class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        if n == 0:
            return True

        flowerbed_len = len(flowerbed)
        curr_index = 0

        while curr_index < flowerbed_len:

            if flowerbed[curr_index] == 1 \
                or (curr_index > 0 and flowerbed[curr_index - 1] == 1) \
                or (curr_index < (flowerbed_len - 1) and flowerbed[curr_index + 1] == 1):

                curr_index += 1
            else:
                n -= 1

                if n == 0:
                    return True

                curr_index += 2

        return False
