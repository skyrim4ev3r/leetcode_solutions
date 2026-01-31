class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        q = deque()
        deck.sort(reverse=True)

        for d in deck:
            if q:
                val = q.pop()
                q.appendleft(val)

            q.appendleft(d)

        return list(q)
