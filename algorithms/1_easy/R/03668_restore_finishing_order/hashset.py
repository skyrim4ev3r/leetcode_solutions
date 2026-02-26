class Solution:
    def recoverOrder(self, order: List[int], friends: List[int]) -> List[int]:
        res = []
        exact = set(friends)

        for f in friends:
            exact.add(f)

        for o in order:
            if o in exact:
                res.append(o)

        return res
