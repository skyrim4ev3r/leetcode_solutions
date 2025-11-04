/*
    need to check string for smallest character
    which for this problem and in order are:

    b,c,d,..,z,a

    its like 'a' having ascii code of 'z' + 1 and the rest having thier ascii code

    and then return ==> NEW_SYSTEM_MAX_CHAR - founded_min_char
*/

impl Solution {
    pub fn min_operations(s: String) -> i32 {

        // Its equal to binary code 'a' in this new system
        const NEW_SYSTEM_MAX_BYTE: u8 = b'z' + 1;
        let mut min_byte = NEW_SYSTEM_MAX_BYTE;

        for byte in s.into_bytes().into_iter() {

            //ignoring 'a', default min_char is 'z' + 1 
            //              which is equal to 'a' ascii in this new system 
            if byte != b'a' && byte < min_byte {
                min_byte = byte;
                if min_byte == b'b' {
                    break;
                }
            }
        }

        (NEW_SYSTEM_MAX_BYTE - min_byte) as i32
    }
}