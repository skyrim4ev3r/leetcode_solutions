impl Solution {
    pub fn is_long_pressed_name(name: String, typed: String) -> bool {
        let name_bytes = name.as_bytes();
        let typed_bytes = typed.as_bytes();
        let len_name = name_bytes.len();
        let len_typed = typed_bytes.len();

        let mut index_typed = 0_usize;

        for i in 0..len_name {
            if typed_bytes[index_typed] != name_bytes[i] {
                if index_typed == 0 {
                    return false;
                }

                while index_typed < len_typed && typed_bytes[index_typed] == typed_bytes[index_typed - 1] {
                    index_typed += 1;
                }

                if index_typed == len_typed || typed_bytes[index_typed] != name_bytes[i] {
                    return false;
                }
            }

            index_typed += 1;

            if index_typed == len_typed {
                return i == (len_name - 1);
            }
        }

        while index_typed > 0 && index_typed < len_typed && typed_bytes[index_typed] == typed_bytes[index_typed - 1] {
            index_typed += 1;
        }

        index_typed == len_typed
    }
}
