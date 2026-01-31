class Solution:
    def bestTower(self, towers: List[List[int]], center: List[int], radius: int) -> List[int]:
        selected_x = -1
        selected_y = -1
        selected_quality = -1

        for t in towers:
            dist = abs(t[0] - center[0]) + abs(t[1] - center[1])

            if dist > radius:
                continue

            if selected_quality < t[2]:
                selected_quality = t[2]
                selected_x = t[0]
                selected_y = t[1]
            elif selected_quality == t[2]:
                if t[0] < selected_x or (t[0] == selected_x and t[1] < selected_y):
                    selected_x = t[0]
                    selected_y = t[1]

        return [selected_x, selected_y]
