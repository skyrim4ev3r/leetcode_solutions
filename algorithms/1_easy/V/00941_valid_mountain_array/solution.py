class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        n = len(arr)

        if n < 3 or arr[1] <= arr[0] or arr[n - 1] >= arr[n - 2]:
            return False

        index = 1

        while index < n and arr[index] > arr[index - 1]:
            index += 1

        if index == 1 or index == n or arr[index] == arr[index - 1]:
            return False

        while index < n and arr[index] < arr[index - 1]:
            index += 1

        return index == n
