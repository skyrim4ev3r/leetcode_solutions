class Solution:
    def longestWord(self, words: List[str]) -> str:
        words.sort(key= lambda x: len(x))

        valids = set()
        max_seen_len = 0

        for w in words:
            curr_word_len = len(w)

            if curr_word_len > max_seen_len + 1:
                break

            if curr_word_len > 1 and (w[:curr_word_len - 1] not in valids):
                continue

            max_seen_len = curr_word_len
            valids.add(w)

        valid_vec = []

        for v in valids:
            if len(v) == max_seen_len:
                valid_vec.append(v)

        valid_vec.sort()

        return valid_vec[0] if len(valid_vec) > 0 else ""
