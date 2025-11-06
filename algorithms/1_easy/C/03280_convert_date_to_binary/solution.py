class Solution:
    def add_i16_binary_to_list(self, res, num):
        is_leading_zero = True

        for i in range(15, -1, -1):
            ch = chr(((num >> i) & 1) + ord('0'))

            if is_leading_zero and ch == '0':
                continue

            is_leading_zero = False
            res.append(ch)

    def convertDateToBinary(self, date: str) -> str:
        res = []
        for part in date.split('-'):
            if res:
                res.append('-')
            self.add_i16_binary_to_list(res, int(part))

        return "".join(res)
