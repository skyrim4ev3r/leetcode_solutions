class Solution:
    def minOperations(self, logs: List[str]) -> int:
        curr = 0

        for log in logs:
            match (log):
                case "../": curr =  0 if curr == 0 else curr - 1
                case "./": pass
                case _: curr += 1

        return curr
