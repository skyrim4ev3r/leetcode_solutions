class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        player_dist = abs(target[0]) + abs(target[1])

        for ghost in ghosts:
            ghost_dist = abs(target[0] - ghost[0]) + abs(target[1] - ghost[1])

            if ghost_dist <= player_dist:
                return False

        return True
