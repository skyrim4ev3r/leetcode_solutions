class Solution:
    def countCollisions(self, directions: str) -> int:
        stack = []
        count = 0

        for ch in directions:
            match ch:
                case 'L':
                    if stack:
                        if stack[-1] == 'S':
                            count += 1
                        else:
                            count += 2
                            stack.pop()

                            while stack and stack[-1] == 'R':
                                count += 1
                                stack.pop()

                            stack = ['S']
                case 'R':
                    stack.append('R')
                case 'S':
                    while stack and stack[-1] == 'R':
                        count += 1
                        stack.pop()

                    stack = ['S']

        return count
