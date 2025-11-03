INT_MAX = sys.maxsize

class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        distance_len = len(distance)
        min_distance = INT_MAX

        curr_distance = 0
        curr_index = start

        while curr_index != destination:
            curr_distance += distance[curr_index]
            curr_index += 1
            if curr_index >= distance_len:
                curr_index = 0

        min_distance = min(min_distance, curr_distance)

        curr_distance = 0
        curr_index = start

        while curr_index != destination:
            curr_index -= 1
            if curr_index < 0:
                curr_index = distance_len - 1

            curr_distance += distance[curr_index]

        min_distance = min(min_distance, curr_distance)

        return min_distance
