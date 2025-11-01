class Solution:
    def compress(self, chars: List[str]) -> int:

        write_index = 0
        read_index = 0
        chars_len = len(chars)

        while read_index < chars_len:

            curr_count = 1
            curr_char = chars[read_index]

            while read_index < chars_len - 1 and chars[read_index + 1] == chars[read_index]:
                curr_count += 1
                read_index += 1

            chars[write_index] = curr_char
            write_index += 1

            if curr_count > 1:
                p = 1
                while p <= curr_count:
                    p *= 10

                p //= 10
                while p > 0:
                    chars[write_index] = chr(((curr_count // p) % 10) +  ord('0'))
                    write_index += 1
                    p //= 10

            read_index += 1

        return write_index
