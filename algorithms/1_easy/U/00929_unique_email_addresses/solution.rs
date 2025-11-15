use std::collections::HashSet;

impl Solution {
    pub fn num_unique_emails(emails: Vec<String>) -> i32 {
        let mut hashset: HashSet<Vec<u8>> = HashSet::new();

        for email in emails.iter() {
            let pos = email.find('@').unwrap();
            let mut unique: Vec<u8> = Vec::new();
            let email_bytes = email.as_bytes();

            for byte in email_bytes[0..pos].iter() {
                if *byte == b'+' {
                    break;
                } else if *byte != b'.' {
                    unique.push(*byte);
                }
            }

            unique.extend_from_slice(&email_bytes[pos..]);
            hashset.insert(unique);
        }

        hashset.len() as i32
    }
}
