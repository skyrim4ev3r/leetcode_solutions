class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        invalids = set(deadends)
        q = deque()
        first_str = "0000"

        if first_str in invalids:
            return -1

        q.append(first_str)
        invalids.add(first_str)
        turns = 0

        while q:
            q_len = len(q)
            for _ in range(q_len):
                curr = q.popleft()

                if curr == target:
                    return turns

                curr_list = list(curr)
                temp_list = curr_list.copy()

                for i in range(len(curr_list)):
                    if curr_list[i] == '9':
                        temp_list[i] = '0'
                    else:
                        temp_list[i] = chr(ord(curr_list[i]) + 1)

                    temp = "".join(temp_list)

                    if not temp in invalids:
                        invalids.add(temp)
                        q.append(temp)

                    if curr_list[i] == '0':
                        temp_list[i] = '9'
                    else:
                        temp_list[i] = chr(ord(curr_list[i]) - 1)

                    temp = "".join(temp_list)

                    if not temp in invalids:
                        invalids.add(temp)
                        q.append(temp)

                    temp_list[i] = curr_list[i]
            turns += 1

        return -1
