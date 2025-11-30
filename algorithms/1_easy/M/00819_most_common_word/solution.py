class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        curr_word = []
        banned_set = set(banned)
        freqs = {}

        for ch in paragraph:
            if ord(ch) >= ord('a') and ord(ch) <= ord('z'):
                curr_word.append(ch);
            elif ord(ch) >= ord('A') and ord(ch) <= ord('Z'):
                curr_word.append(chr(ord(ch) + 32))
            else:
                word = "".join(curr_word)
                if len(word) > 0 and word not in banned_set:
                    if word in freqs:
                        freqs[word] += 1
                    else:
                        freqs[word] = 1
                curr_word = []

        word = "".join(curr_word)
        if len(word) > 0 and word not in banned_set:
            if word in freqs:
                freqs[word] += 1
            else:
                freqs[word] = 1

        res = ""
        max_freq = 0

        for word, freq in freqs.items():
            if freq > max_freq:
                res = word
                max_freq = freq

        return res
