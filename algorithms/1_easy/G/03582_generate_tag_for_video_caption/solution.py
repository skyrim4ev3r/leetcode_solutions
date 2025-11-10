class Solution:
    MAX_SIZE = 99

    def generateTag(self, caption: str) -> str:
        res = ['#']
        for word in caption.split():
            # convert all ascii chars in the word to lower_case()
            # and .take(MAX_SIZE)
            bytes_word = [c.lower() for c in word[:Solution.MAX_SIZE]]

            # capitalize the first char
            bytes_word[0] = bytes_word[0].upper()

            res.extend(bytes_word)

            if len(res) >= Solution.MAX_SIZE:
                break

        # convert the first char of the first word to lower_case() if it exists
        if len(res) > 1:
            res[1] = res[1].lower()

        return ''.join(res)
