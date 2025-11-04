class SmallestInfiniteSet:

    def __init__(self):
        self.candidates_in_removed_range = SortedSet()
        self.inf_set_min = 1

    def popSmallest(self) -> int:
        if self.candidates_in_removed_range:
            smallest = self.candidates_in_removed_range[0]
            self.candidates_in_removed_range.remove(smallest)
            return smallest

        smallest = self.inf_set_min
        self.inf_set_min += 1
        return smallest

    def addBack(self, num: int) -> None:
        if num < self.inf_set_min:
            self.candidates_in_removed_range.add(num)
            while True:
                try:
                    self.candidates_in_removed_range.remove(self.inf_set_min - 1)
                    self.inf_set_min -= 1
                except KeyError:
                    break

# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)
