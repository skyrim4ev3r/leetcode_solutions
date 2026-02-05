use std::collections::HashMap;

impl Solution {
    pub fn evaluate(s: String, knowledge: Vec<Vec<String>>) -> String {
        let mut hashmap: HashMap<&[u8], &[u8]> = HashMap::new();
        for k in knowledge.iter() {
            hashmap.insert(k[0].as_bytes(), k[1].as_bytes());
        }

        let mut res: Vec<u8> = Vec::new();
        let mut i = 0_usize;
        let bytes = s.as_bytes();
        let len = bytes.len();

        while i < len {
            if bytes[i] == b'(' {
                let mut temp: Vec<u8> = Vec::new();
                i += 1;

                while i < len && bytes[i] != b')' {
                    temp.push(bytes[i]);
                    i += 1;
                }

                if let Some(val) = hashmap.get(temp.as_slice()) {
                    res.extend_from_slice(val);
                } else {
                    res.push(b'?');
                }
            } else {
                res.push(bytes[i]);
            }

            i += 1;
        }

        String::from_utf8(res).unwrap()
    }
}
