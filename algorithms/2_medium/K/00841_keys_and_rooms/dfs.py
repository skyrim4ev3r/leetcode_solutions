class Solution:
    def dfs(self, rooms, visiteds, curr_room):
        if visiteds[curr_room]:
            return

        visiteds[curr_room] = True

        for key in rooms[curr_room]:
            self.dfs(rooms, visiteds, key)

    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visiteds = [False] * len(rooms)

        self.dfs(rooms, visiteds, 0)

        for is_visited in visiteds:
            if not is_visited:
                return False

        return True
