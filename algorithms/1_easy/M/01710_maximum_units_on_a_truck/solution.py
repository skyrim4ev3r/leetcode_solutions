class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        n = len(boxTypes)
        count = 0
        boxTypes.sort(key=lambda x: x[1], reverse=True)

        box_index = 0
        while truckSize > 0 and box_index < n:
            curr = min(boxTypes[box_index][0], truckSize)
            truckSize -= curr
            count += curr * boxTypes[box_index][1]
            box_index += 1

        return count
