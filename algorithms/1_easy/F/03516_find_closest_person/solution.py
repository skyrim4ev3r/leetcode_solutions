class Solution(object):
    def findClosest(self, x, y, z):
        return (abs(z-x) < abs(y-z)) + 2 *((abs(z-x) > abs(y-z)))
