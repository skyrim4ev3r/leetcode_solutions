class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        key_map = [0] * 26

        curr_char = ord('a')
        for ch in key:

            index = ord(ch) - ord('a')

            if ch != ' ' and key_map[index] == 0:
                key_map[index] = chr(curr_char)
                curr_char += 1

        res = []

        for ch in message:
            if ch == ' ':
                res.append(ch)
            else:
                res.append(key_map[ord(ch) - ord('a')])

        return "".join(res)
