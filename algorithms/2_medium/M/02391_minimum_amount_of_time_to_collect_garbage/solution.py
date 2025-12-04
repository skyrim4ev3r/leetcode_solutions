class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        last_p = 0
        last_g = 0
        last_m = 0

        curr_possible_p = 0
        curr_possible_g = 0
        curr_possible_m = 0

        for i, s in enumerate(garbage):
            count_p = 0
            count_g = 0
            count_m = 0

            if i > 0:
                curr_possible_p += travel[i - 1]
                curr_possible_g += travel[i - 1]
                curr_possible_m += travel[i - 1]

            for ch in s:
                match ch:
                    case 'P': count_p += 1
                    case 'G': count_g += 1
                    case 'M': count_m += 1

            if count_p > 0:
                curr_possible_p += count_p
                last_p = curr_possible_p

            if count_g > 0:
                curr_possible_g += count_g
                last_g = curr_possible_g

            if count_m > 0:
                curr_possible_m += count_m
                last_m = curr_possible_m

        return last_p + last_g + last_m
