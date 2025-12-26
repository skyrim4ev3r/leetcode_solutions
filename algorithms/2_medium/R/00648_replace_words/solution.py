class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        dictionary.sort(key=lambda x: len(x))
        res = []

        for word in sentence.split():
            is_inserted = False

            for d in dictionary:
                if word.startswith(d):
                    res.append(d)
                    is_inserted = True
                    break

            if not is_inserted:
                res.append(word)

        return " ".join(res)
