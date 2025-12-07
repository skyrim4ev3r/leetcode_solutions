class Solution {
    std::pair<int, int> get_real_and_imaginary_part(string& s) {
        istringstream ss{move(s)};
        string part;

        std::getline(ss, part, '+');
        int real_num = std::stoi(part);

        std::getline(ss, part, 'i');
        int imaginary_num = std::stoi(part);

        return {real_num, imaginary_num};
    }
public:
    string complexNumberMultiply(string num1, string num2) {
        auto [num1_real, num1_imaginary] = get_real_and_imaginary_part(num1);
        auto [num2_real, num2_imaginary] = get_real_and_imaginary_part(num2);

        int mul_real = (num1_real * num2_real) - (num1_imaginary * num2_imaginary);
        int mul_imaginary = (num1_real * num2_imaginary) + (num2_real * num1_imaginary);

        return std::to_string(mul_real) + "+" + std::to_string(mul_imaginary) + "i";
    }
};
