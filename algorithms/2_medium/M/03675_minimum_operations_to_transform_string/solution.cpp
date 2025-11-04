/*
    need to check string for smallest character
    which for this problem and in order are:

    b,c,d,..,z,a

    its like 'a' having ascii code of 'z' + 1 and the rest having thier ascii code

    and then return ==> NEW_SYSTEM_MAX_CHAR - founded_min_char
*/

class Solution {
public:
    int minOperations(string s) {

        // Its equal to binary code 'a' in this new system
        const char NEW_SYSTEM_MAX_CHAR{'z' + 1};
        char min_char = NEW_SYSTEM_MAX_CHAR;

        for (const char &ch: s) {

            //ignoring 'a', default min_char is 'z' + 1 
            //              which is equal to 'a' ascii in this new system 
            if (ch != 'a' && ch < min_char) {
                min_char = ch;
                if (min_char == 'b') {
                    break;
                }
            }
        }

        return NEW_SYSTEM_MAX_CHAR - min_char;
    }
};
