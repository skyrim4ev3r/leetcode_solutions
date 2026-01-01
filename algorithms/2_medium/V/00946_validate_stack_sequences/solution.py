class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        popped_len = len(popped)
        popped_index = 0
        stack = []

        for val in pushed:
            stack.append(val)

            while stack and stack[-1] == popped[popped_index]:
                stack.pop()
                popped_index += 1

                if popped_index == popped_len:
                    return True

        return False
