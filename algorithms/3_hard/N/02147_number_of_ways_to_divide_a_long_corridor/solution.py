class Solution:
    def numberOfWays(self, corridor: str) -> int:
        seat_count = corridor.count('S')

        if seat_count == 0 or (seat_count & 1) == 1:
            return 0

        curr_seat_count = 0
        continues_plant_count = 0
        n = len(corridor)
        MOD_TO = 1_000_000_007
        start_index = 0
        end_index =n - 1
        count = 1

        while corridor[start_index] != 'S':
            start_index += 1

        while corridor[end_index] != 'S':
            end_index -= 1

        for i in range(start_index, end_index + 1):
            if corridor[i] == 'S':
                curr_seat_count += 1

                if ((curr_seat_count & 1) == 1):
                    count = (count * (continues_plant_count + 1)) % MOD_TO

                continues_plant_count = 0
            else:
                continues_plant_count += 1

        return count
