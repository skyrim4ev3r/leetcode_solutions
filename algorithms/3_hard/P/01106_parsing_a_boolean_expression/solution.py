class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        stack_exprs = []
        stack_logic = []

        for ch in expression:
            if ch in '&|!':
                stack_logic.append(ch)
            if ch in '(ft':
                stack_exprs.append(ch)

            if ch == ')':
                # using top(), because input is valid, and there is at least one 'f' or 't' at top of stack
                exp1 = stack_exprs.pop() == 't'

                # using top(), because input is valid, and there is at least one '&' or '|' or '!'
                logic = stack_logic.pop()

                if logic == '!':
                    exp1 = not exp1 # for valid inputs there should be only 1 exp in between parentheses when the logic is '!'
                    stack_exprs.pop() # to pop '('
                else:
                    while True:

                        exp2_ch = stack_exprs.pop()

                        if exp2_ch == '(':
                            break

                        exp2 = exp2_ch == 't'

                        if logic == '&':
                            exp1 = exp1 and exp2
                        elif logic == '|': # using 'elif' just for clearity, otherwise, its only valid logic which is left
                            exp1 = exp1 or exp2

                stack_exprs.append('t' if exp1 else 'f')

        # at the end, it should be only 1 expr in stack and it can be 't' or 'f'
        return stack_exprs.pop() == 't'
