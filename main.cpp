#include <iostream>
#include "Real.h"

int main()
{
Real a;
Real b;
Real c;
Real d;
Real x1;
Real x2;

std::cout << "Enter a, b, c: ";
std::cin >> a >> b >> c;

if (a == Real(0))
{
if (b == Real(0))
{
if (c == Real(0))
std::cout << "Any x\n";
else
std::cout << "No roots\n";
}
else
{
x1 = -c / b;
std::cout << "x = " << x1 << "\n";
}
}
else
{
d = b * b - Real(4) * a * c;

std::cout << "D = " << d << "\n";

if (d < Real(0))
{
std::cout << "No real roots\n";
}
else
{
if (d == Real(0))
{
x1 = -b / (Real(2) * a);

std::cout << "x = " << x1 << "\n";
}
else
{
x1 = (-b + d.sqrt()) / (Real(2) * a);
x2 = (-b - d.sqrt()) / (Real(2) * a);

std::cout << "x1 = " << x1 << "\n";
std::cout << "x2 = " << x2 << "\n";
}
}
}

return 0;
}
