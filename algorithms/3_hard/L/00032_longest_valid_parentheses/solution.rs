impl Solution {

    /*
        replace valid parentheses with '+' is original sting
        example:
                "}}{}}([]){()" ==> will turn into ==> "}}++}++++{++" 
    */
    fn reformat_string(s: &mut Vec<u8>) {
        let mut stack: Vec<usize> = Vec::new();
        for i in 0..s.len() {
            if let Some(&top_element) = stack.last() {
                 /*
                    if the stack top element match our current char 
                    then we replace both of them with '+'
                */
                if (s[i] == b'}' && s[top_element] == b'{')
                    || (s[i] == b']' && s[top_element] == b'[')
                    || (s[i] == b')' && s[top_element] == b'(')
                {
                    s[top_element] = b'+'; 
                    s[i] = b'+';
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
    fn max_continuous_substr_of_plus(s: Vec<u8>) -> i32 {
        let (mut max, mut curr) = (0, 0);
        for ch in s {
            if (ch == b'+') {
                curr += 1;
            } else {
                curr = 0;
            } 
            if (curr > max) {
                max = curr;
            }
        }
        max
    }
    pub fn longest_valid_parentheses(mut s: String) -> i32 { 

        //converting string into Vec<u8> 
        let mut vec_s = s.into_bytes();

        // reformatting string to replace all of its valid parentheses chars with '+'      
        Self::reformat_string(&mut vec_s);

        // returning longest continues of those '+' chars     
        Self::max_continuous_substr_of_plus(vec_s)
    }
}
