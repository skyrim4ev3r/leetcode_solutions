class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:

        is_increasing = True
        arr_len = len(arr)

        if arr_len < 3 or arr[1] <= arr[0] or arr[arr_len - 1] >= arr[arr_len - 2]:
            return False

        for i in range(1, arr_len):
            if is_increasing:
                if arr[i] == arr[i - 1]:
                    return False

                if arr[i] < arr[i - 1]:
                    is_increasing = False
            else:
                if arr[i] >= arr[i - 1]:
                    return False

        return True
