class Solution:
    def wateringPlants(self, plants: List[int], capacity: int) -> int:
        can = capacity
        count = 0
        plants_len = len(plants)

        for i in range(plants_len):
            can -= plants[i]
            count += 1
            if i < plants_len - 1 and can < plants[i + 1]:
                count += 2 * (i + 1)
                can = capacity

        return count
