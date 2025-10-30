class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stack_exprs{};
        stack<char> stack_logic{};

        for (auto ch: expression) {
            switch (ch) {
                case '&':
                case '|':
                case '!':
                    stack_logic.push(ch);
                    break;

                case '(':
                case 'f':
                case 't':
                    stack_exprs.push(ch);
                    break;

                case ')': {

                        // using top(), because input is valid, and there is at least one 'f' or 't' at top of stack
                        bool exp1{stack_exprs.top() == 't'};
                        stack_exprs.pop();

                        // using top(), because input is valid, and there is at least one '&' or '|' or '!'
                        char logic{stack_logic.top()};
                        stack_logic.pop();

                        if (logic == '!') {
                            exp1 = !exp1; //for valid inputs there should be only 1 exp in between parentheses when the logic is '!'
                            stack_exprs.pop(); // to pop '(' 
                        } else {
                            while (true) {

                                char exp2_ch = stack_exprs.top();
                                stack_exprs.pop();

                                if (exp2_ch == '('){
                                    break;
                                }

                                bool exp2{exp2_ch == 't'};

                                if (logic == '&') {
                                    exp1 = exp1 && exp2;
                                } else if (logic == '|') { // using 'else if' just for clearity, otherwise, its only valid logic which is left
                                    exp1 = exp1 || exp2;
                                }

                            }
                        }

                        stack_exprs.push(exp1 ? 't' : 'f');
                    }
                    break;

                default: //ignore ','
                    break;
            }
        }

        // at the end, it should be only 1 expr in stack and it can be 't' or 'f'
        return stack_exprs.top() == 't';
    }
};
