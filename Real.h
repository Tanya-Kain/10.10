#ifndef REAL_H
#define REAL_H

#include <iostream>
#include <string>

class Real
{
private:
int whole;
int fraction;

public:
Real();
Real(int a);
Real(int a, int b);
Real(const std::string& s);

std::string toString() const;

Real operator-() const;

Real operator+(const Real& a) const;
Real& operator+=(const Real& a);

Real operator-(const Real& a) const;
Real& operator-=(const Real& a);

Real operator*(const Real& a) const;
Real& operator*=(const Real& a);

Real operator/(const Real& a) const;
Real& operator/=(const Real& a);

bool operator==(const Real& a) const;
bool operator!=(const Real& a) const;

bool operator<(const Real& a) const;
bool operator<=(const Real& a) const;

bool operator>(const Real& a) const;
bool operator>=(const Real& a) const;

Real sqrt() const;

friend std::ostream& operator<<(std::ostream& out, const Real& a);
friend std::istream& operator>>(std::istream& in, Real& a);
};

#endif 
