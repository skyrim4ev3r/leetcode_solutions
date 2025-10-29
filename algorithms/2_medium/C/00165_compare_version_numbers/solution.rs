impl Solution {
    pub fn compare_version(version1: String, version2: String) -> i32 {
        let parts1: Vec<&str> = version1.split('.').collect();
        let parts2: Vec<&str> = version2.split('.').collect();

        let max_length = parts1.len().max(parts2.len());

        for i in 0..max_length {
            let num1 = parts1.get(i).unwrap_or(&"0").parse::<i32>().unwrap();
            let num2 = parts2.get(i).unwrap_or(&"0").parse::<i32>().unwrap();

            if num1 > num2 {
                return 1;
            } else if num1 < num2 {
                return -1;
            } 
        }
        
        0
    }
}
