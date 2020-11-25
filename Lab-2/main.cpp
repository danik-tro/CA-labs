#include<iostream>

#include"calculator.h"


using namespace std;

int main () {
	Calculator calc = Calculator();
	cout << calc.Add(2, 3);
	return 0;
}
