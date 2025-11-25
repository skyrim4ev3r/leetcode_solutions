impl Solution {
    pub fn simplify_path(path: String) -> String {
        let parts = path.split('/').filter(|x| !x.is_empty()).collect::<Vec<&str>>();
        let mut stack: Vec<&str> = Vec::with_capacity(parts.len());

        for part in parts.into_iter() {
            match part {
                "." => continue,
                ".." => { stack.pop(); },
                _ => stack.push(part),
            }
        }

        format!("/{}", stack.join("/"))
    }
}
