#include <iostream>

class Calculator
{

public:
	Calculator() {}

	double add(double a, double b) { return a + b; }
	double sub(double a, double b) { return a - b; }
	double mult(double a, double b) { return a * b; }
	double div(double a, double b) { 
		if (b == 0.0)
			std::cout << "Деление на 0 - нельзя";
		return a / b; }

	double calcc(double a, double b, double (Calculator::* action)(double, double))
	{
		return (this->*action)(a, b);
	}

	//
};

int main()
{
	setlocale(LC_ALL, "RUS.UTF-8");
	Calculator calc;

    double a = 10;
    double b = 8;

	std::cout << "10 + 8 = " << calc.calcc(a, b, &Calculator::add) << "\n";

	double a1 = 7;
	double b1 = 0;

	std::cout << "7 / 0 = " << calc.calcc(a1, b1, &Calculator::div) << "\n";

}

