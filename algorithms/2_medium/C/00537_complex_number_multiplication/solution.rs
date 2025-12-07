impl Solution {
    fn get_real_and_imaginary_part(s: String) -> (i32, i32) {
        let parts: Vec<&str> = s.split(|ch| ch == '+' || ch == 'i').collect();
        let real_num = parts[0].parse::<i32>().unwrap();
        let imaginary_num = parts[1].parse::<i32>().unwrap();

        (real_num, imaginary_num)
    }
    pub fn complex_number_multiply(num1: String, num2: String) -> String {
        let (num1_real, num1_imaginary) = Self::get_real_and_imaginary_part(num1);
        let (num2_real, num2_imaginary) = Self::get_real_and_imaginary_part(num2);

        let mul_real = (num1_real * num2_real) - (num1_imaginary * num2_imaginary);
        let mul_imaginary = (num1_real * num2_imaginary) + (num2_real * num1_imaginary);

        format!("{}+{}i", mul_real, mul_imaginary)
    }
}
