class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        count = 0
        left = 0
        right = len(people) - 1

        while left <= right:
            curr = people[right]

            if left < right and people[left] + curr <= limit:
                curr += people[left]
                left += 1

            count += 1
            right -= 1

        return count
