class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        hashmap = {}
        res = []
        min_index_sum = sys.maxsize
        len1 = len(list1)
        len2 = len(list2)

        for i in range(len1):
            hashmap[list1[i]] =  i

        for i in range(len2):
            if i > min_index_sum:
                break

            list1_index = hashmap.get(list2[i])
            if list1_index != None:
                if list1_index + i < min_index_sum:
                    min_index_sum = list1_index + i
                    res.clear()
                    res.append(list2[i])
                elif list1_index + i == min_index_sum:
                    res.append(list2[i])

        return res
