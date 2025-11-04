    # need to check string for smallest character
    # which for this problem and in order are:
    #
    # b,c,d,..,z,a
    #
    # its like 'a' having ascii code of 'z' + 1 and the rest having thier ascii code
    #
    # and then return ==> NEW_SYSTEM_MAX_CHAR - founded_min_char

class Solution:
    def minOperations(self, s: str) -> int:
        NEW_SYSTEM_MAX_BYTE = ord('z') + 1
        min_byte = NEW_SYSTEM_MAX_BYTE;
        for ch in s:

            if ch != 'a' and ord(ch) < min_byte: # ignoring 'a', default min_char is NEW_SYSTEM_MAX_CHAR
                                                      #             which is equal to 'a' ascii in new system
                min_byte = ord(ch)
                if min_byte == ord('b'):
                    break

        return NEW_SYSTEM_MAX_BYTE - min_byte
