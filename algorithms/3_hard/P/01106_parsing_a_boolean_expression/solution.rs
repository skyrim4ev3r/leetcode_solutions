impl Solution {
    pub fn parse_bool_expr(expression: String) -> bool {
        let mut stack_exprs: Vec<u8> = Vec::new();
        let mut stack_logic: Vec<u8> = Vec::new();

        for ch in expression.into_bytes().into_iter() {
            match ch {
                b'&' | b'|' | b'!' => {
                    stack_logic.push(ch);

                },
                b'(' | b'f' | b't' => {
                    stack_exprs.push(ch);
                },
                b')' => {
                    // using unwrap, because input is valid, and there is at least one 'f' or 't' at top of stack
                    let mut exp1 = stack_exprs.pop().unwrap() == b't';
                    // using unwrap, because input is valid, and there is at least one '&' or '|' or '!'
                    let logic = stack_logic.pop().unwrap();

                    if logic == b'!' {
                        exp1 = !exp1; //for valid inputs there should be only 1 exp in between parentheses when the logic is '!'
                        stack_exprs.pop(); // to pop '(' 
                    } else {
                        while let Some(exp2_ch) = stack_exprs.pop() && exp2_ch != b'(' {
                            let exp2 = exp2_ch == b't';
                            if logic == b'&' {
                                exp1 = exp1 && exp2;
                            } else if logic == b'|' { // using 'else if' just for clearity, otherwise, its only valid logic which is left
                                exp1 = exp1 || exp2;
                            }
                        }
                    }

                    stack_exprs.push(if exp1 {b't'} else {b'f'});
                },
                _ => {} //ignore ','
            }
        }

        // at the end, it should be only 1 expr in stack and it can be 't' or 'f'
        stack_exprs.pop().unwrap() == b't'
    }
}
