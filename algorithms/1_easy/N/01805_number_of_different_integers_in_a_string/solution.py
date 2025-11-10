class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        num_chars = []
        is_seen_new_num = False
        is_seen_zero = False

        ord_0 = ord('0')
        ord_9 = ord('9')

        nums_chars = set()

        for ch in word:
            ord_ch = ord(ch)
            if (ord_ch > ord_0 and ord_ch <= ord_9) or (ord_ch == ord_0 and is_seen_new_num):
                num_chars.append(ch)
                is_seen_new_num = True
                is_seen_zero = False
            elif ord_ch == ord_0 and not is_seen_new_num:
                is_seen_zero = True
            else:
                if is_seen_new_num:
                    is_seen_new_num = False
                    nums_chars.add("".join(num_chars))
                    num_chars = []
                elif is_seen_zero:
                    nums_chars.add("0")

        if is_seen_new_num:
            nums_chars.add("".join(num_chars))
        elif is_seen_zero:
            nums_chars.add("0")

        return len(nums_chars)
