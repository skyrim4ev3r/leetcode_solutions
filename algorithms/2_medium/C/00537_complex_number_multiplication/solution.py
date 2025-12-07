class Solution:
    def get_real_and_imaginary_part(self, s):
        parts = s.split('+')
        real_num = int(parts[0])
        parts2 = parts[1].split('i')
        imaginary_num = int(parts2[0])

        return (real_num, imaginary_num)

    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        num1_real, num1_imaginary = self.get_real_and_imaginary_part(num1)
        num2_real, num2_imaginary = self.get_real_and_imaginary_part(num2)

        mul_real = (num1_real * num2_real) - (num1_imaginary * num2_imaginary)
        mul_imaginary = (num1_real * num2_imaginary) + (num2_real * num1_imaginary)

        return "{}+{}i".format(mul_real, mul_imaginary)
