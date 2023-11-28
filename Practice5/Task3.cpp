#include <math.h>

class Complex {
    public:
        // СВОЙСТВА ОБЪЕКТОВ КЛАССА //
        double re = 0;
        double im = 0;

        std::string full_complex = getFull_Complex();
        //////////////////////////////

        // Может, можно и без этого обойтись
        std::string getFull_Complex() {
            std::string complex_num;
            if (im >= 0) {
                complex_num = std::to_string(re) + "+" + std::to_string(im) + "j";
            }
            else {
               complex_num = std::to_string(re) + std::to_string(im) + "j";
            }

            return complex_num;
        }
            // КОНСТРУКТОРЫ //
        explicit Complex(std::string num) {
            int pos = 0;
            while (num[pos] == ' ') {
                pos++;
            }

            int i = pos;
            while (num[i] != '+' && num[i] != ' ' && num[i] != '-') {
                i++;
            }

            re = std::stod(num.substr(0, i));

            pos++;
            std::string sign = "";
            while (num[pos] == ' ' || num[pos] == '+' || num[pos] == '-') {
                if (num[pos] == '-') {
                    sign += '-';
                }
                pos++;
            }
            
            im = std::stod(sign + num.substr(pos));

            full_complex = getFull_Complex();
        }

        Complex() = default;
            ///////////////

            // ОПЕРАТОРЫ //
        Complex operator+(const Complex summand) {
            Complex num;
            num.re = re + summand.re;
            num.im = im + summand.im;

            return num;
        }

        Complex operator-(const Complex deductible) {
            Complex num;
            num.re = re - deductible.re;
            num.im = im - deductible.im;

            num.full_complex = getFull_Complex();

            return num;
        }

        Complex operator*(const Complex multiplier) {
            Complex num;
            num.re = re * multiplier.re - im * multiplier.im;
            num.im = re * multiplier.im + im * multiplier.re;

            num.full_complex = getFull_Complex();

            return num;
        }

        Complex operator/(const Complex divider) {
            Complex num;
            num.re = (re * divider.re + im * divider.im) / (pow(divider.re, 2) + pow(divider.im, 2));
            num.im = (im * divider.re - re * divider.im) / (pow(divider.re, 2) + pow(divider.im, 2));

            num.full_complex = getFull_Complex();

            return num;
        }

        friend std::ostream& operator<<(std::ostream& out, const Complex& num) {
            out << (num.re == 0.0 ? 0.0 : num.re)
                << (num.im < 0 ? "" : "+")
                << (num.im == 0.0 ? 0.0 : num.im) << 'j';
            return out;
        }
            ///////////////
};
