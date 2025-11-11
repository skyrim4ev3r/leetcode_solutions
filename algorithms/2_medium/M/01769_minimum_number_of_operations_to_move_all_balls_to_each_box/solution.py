class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        res = [0] * len(boxes)
    
        move_sum = 0
        balls = 0
        for i in range(len(boxes)):
            move_sum += balls
            res[i] += move_sum

            if boxes[i] == '1':
                balls += 1

        move_sum = 0
        balls = 0
        for i in range(len(boxes) - 1, -1, -1):
            move_sum += balls
            res[i] += move_sum

            if boxes[i] == '1':
                balls += 1

        return res
