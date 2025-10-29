class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        total_drunk = 0

        while numBottles >= numExchange:
            total_drunk += numExchange
            numBottles =  numBottles - numExchange + 1
            numExchange += 1

        return total_drunk + numBottles
