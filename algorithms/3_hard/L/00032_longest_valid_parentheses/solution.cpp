class Solution {
    
    /*
        replace valid parentheses with '+' is original sting
        example:
                "}}{}}([]){()" ==> will turn into ==> "}}++}++++{++" 
    */
    void reformat_string(string &s) {
        stack<int> stack;
        for (auto i{0}; i < s.size(); ++i){
            if (stack.size() > 0) {
                auto top_element{stack.top()};
                
                /*
                    if stack top element match our current char 
                    then we replace both of them with '+'
                */
                if ((s[i] == '}' && s[top_element] == '{')
                    || (s[i] == ']' && s[top_element] == '[')
                    || (s[i] == ')' && s[top_element] == '('))
                {
                    s[top_element] = '+';
                    s[i] = '+';
                    stack.pop();
                    continue;
                }
                // We use "continue;" because both of our if conditions require pushing to the stack in their "else" statements.
            }
            // saving index of current char
            stack.push(i); 
        }
    }
    
    /*
          after string get reformatted to:
          
              "}}++}++++{++"
              
          now we need just return longest continuous count of '+' char
    */
    int max_continuous_substr_of_char_plus(string &s){
        int max{0}, curr{0};
        for (auto i{0}; i < s.size(); ++i) {
            if (s[i] == '+') {
                ++curr;
            } else {
                curr = 0;
            }
            if (curr > max) {
                max = curr;
            }
        }
        return max;
    }
    
public:
    int longestValidParentheses(string s) {
    
        // reformatting string to replace all of its valid parentheses chars with '+'
        reformat_string(s);
        
        // counting longest continues of those '+' chars
        return max_continuous_substr_of_char_plus(s);
    }
};
