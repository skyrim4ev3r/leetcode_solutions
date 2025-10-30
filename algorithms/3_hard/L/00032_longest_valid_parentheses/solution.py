class Solution:

    #   for c++ and rust:
    #   replace valid parentheses with '+' is original sting
    #   example:
    #           "}}{}}([]){()" ==> will turn into ==> "}}++}++++{++" 
    
    #   python
    #           since python doesnt allow for changing string so its more like:
    #               ["}", "(", ")"] ==> ["}", "+", "+"]
    #
    #           idea is same, but instead of string, we change the "list"
    #       
    def reformat_list(self, s):
        stack = []
        for i in range(len(s)):
            if len(stack) > 0:
                top_element = stack[-1]
                #
                #   if the stack top element match our current char 
                #   then we replace both of them with '+'
                #
                if (s[i] == '}' and s[top_element[1]] == '{') \
                        or (s[i] == ']' and s[top_element] == '[') \
                        or (s[i] == ')' and s[top_element] == '('):            
                    s[top_element] = '+'
                    s[i] = '+'
                    stack.pop()
                    continue
                # We use "continue" because both of our if conditions require pushing to the stack in their "else" statements.
            # saving index of current char
            stack.append(i)


    # for c++ and rust:
    #    after string get reformatted to:
    #    
    #        "}}++}++++{++"
    #       
    #    now we need just return longest continuous count of '+' char
    
    # for python: its just "list" instead of "string", and we need count continous "+" in this list
    def max_continuous_of_plus(self, s):
        max_continuous_plus, curr = 0, 0
        for c in s:
            if c == '+':
                curr += 1
            else:
                curr = 0
            if curr > max_continuous_plus:
                max_continuous_plus = curr
        return max_continuous_plus
    
    def longestValidParentheses(self, s: str) -> int:
        list_s = list(s) # converting s for mutability

        # reformatting list to replace all of its valid parentheses chars with '+'   
        self.reformat_list(list_s) 

        # returning longest continues of those '+' chars   
        return self.max_continuous_of_plus(list_s)