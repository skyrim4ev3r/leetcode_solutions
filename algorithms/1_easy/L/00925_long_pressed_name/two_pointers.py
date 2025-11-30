class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        len_name = len(name)
        len_typed = len(typed)

        index_typed = 0

        for i in range(len_name):
            if typed[index_typed] != name[i]:
                if index_typed == 0:
                    return False

                while index_typed < len_typed and typed[index_typed] == typed[index_typed - 1]:
                    index_typed += 1

                if index_typed == len_typed or typed[index_typed] != name[i]:
                    return False

            index_typed += 1

            if index_typed == len_typed:
                return i == (len_name - 1)

        while index_typed > 0 and index_typed < len_typed and typed[index_typed] == typed[index_typed - 1]:
            index_typed += 1

        return index_typed == len_typed
