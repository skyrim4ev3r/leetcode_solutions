class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        for row in image:
            right = len(row) - 1
            left = 0

            while left < right:
                temp = row[left]
                row[left] = row[right]
                row[right] = temp

                row[right] = 0 if row[right] == 1 else 1
                row[left] = 0 if row[left] == 1 else 1

                left += 1
                right -= 1

            if left == right:
                row[left] = 0 if row[left] == 1 else 1

        return image
