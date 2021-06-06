#include <iostream>
using namespace std;

class Complex {
public:
	Complex() {
		real = 0.0;
		imag = 0.0;
	}
	Complex(double real_, double imag_) {
		real = real_;
		imag = imag_;
	}
    double Getreal() {
        return real;
    }
    void    setReal(double real_) {
        real = real_;
    }
    double Getimag() {
        return imag;
    }
    void	setImag(double imag_) {
		imag = imag_;
	}
private:
    double real;
    double imag;
};

int         main(void)
{
	Complex	C1;
	Complex C2 = Complex(2, 5);
	Complex C3(10, 20);

	cout << "C1 = " << C1.Getreal() << "," << C1.Getimag() << endl;
	cout << "C2 = " << C2.Getreal() << "," << C2.Getimag() << endl;
	cout << "C3 = " << C3.Getreal() << "," << C3.Getimag() << endl;


    return (1);
}