class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        arr_len = len(arr)
        count_zeros = 0

        for num in arr:
            if num == 0:
                count_zeros += 1

        new_index = arr_len - 1 + count_zeros
        for i in range(arr_len - 1, -1, -1):
            if new_index < arr_len:
                arr[new_index] = arr[i]

            if arr[i] == 0:
                new_index -= 1
                if new_index < arr_len:
                    arr[new_index] = 0

            new_index -= 1
