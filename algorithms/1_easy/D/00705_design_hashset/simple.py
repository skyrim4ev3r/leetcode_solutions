class MyHashSet:

    def __init__(self):
        self.seen = [False] * 1_000_001

    def add(self, key: int) -> None:
        self.seen[key] = True

    def remove(self, key: int) -> None:
        self.seen[key] = False

    def contains(self, key: int) -> bool:
        return self.seen[key]


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
