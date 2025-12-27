class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort(key=lambda x: x[0])

        in_use_rooms = []
        free_rooms = []
        counts = [0] * n

        for i in range(n):
            heappush(free_rooms, i)

        for start, end in meetings:
            while in_use_rooms and in_use_rooms[0][0] <= start:
                heappush(free_rooms, in_use_rooms[0][1])
                heappop(in_use_rooms)

            if free_rooms:
                room_id = free_rooms[0]
                counts[room_id] += 1
                heappush(in_use_rooms, [end, room_id])
                heappop(free_rooms)
            else:
                room = heappop(in_use_rooms)
                room[0] += end - start
                counts[room[1]] += 1
                heappush(in_use_rooms, room)

        max_count = -1
        max_id = -1

        for (i, count) in enumerate(counts):
            if count > max_count:
                max_count = count
                max_id = i

        return max_id
