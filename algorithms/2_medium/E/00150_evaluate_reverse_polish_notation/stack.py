class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for token in tokens:
            if token.isdigit() or (len(token) > 1 and token.startswith('-') and token[1:].isdigit()):
                stack.append(int(token))
            else:
                num2 = stack.pop()
                num1 = stack.pop()

                match token:
                    case '+':
                        stack.append(num1 + num2)
                    case '-':
                        stack.append(num1 - num2)
                    case '*':
                        stack.append(num1 * num2)
                    case '/':
                        stack.append(int(num1 / num2))

        return stack.pop()
