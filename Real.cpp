#include "Real.h"

Real::Real()
{
whole = 0;
fraction = 0;
}

Real::Real(int a)
{
whole = a;
fraction = 0;
}

Real::Real(int a, int b)
{
whole = a;
fraction = b;

if (fraction >= 1000)
{
whole += fraction / 1000;
fraction %= 1000;
}

if (fraction <= -1000)
{
whole += fraction / 1000;
fraction %= 1000;
}

if (whole > 0 && fraction < 0)
{
whole--;
fraction += 1000;
}

if (whole < 0 && fraction > 0)
{
whole++;
fraction -= 1000;
}
}

Real::Real(const std::string& s)
{
int i;
int sign;
int value;

whole = 0;
fraction = 0;

i = 0;
sign = 1;

if (s[0] == '-')
{
sign = -1;
i++;
}

while (i < (int)s.size() && s[i] != '.')
{
whole = whole * 10 + (s[i] - '0');
i++;
}

whole *= sign;

if (i < (int)s.size() && s[i] == '.')
{
i++;
value = 0;

if (i < (int)s.size())
value += (s[i] - '0') * 100;

i++;

if (i < (int)s.size())
value += (s[i] - '0') * 10;

i++;

if (i < (int)s.size())
value += (s[i] - '0');

fraction = value * sign;
}
}

std::string Real::toString() const
{
std::string s;
int f;

if (whole == 0 && fraction < 0)
s = "-0";
else
{
s = std::to_string(whole);
}

if (fraction < 0)
f = -fraction;
else
f = fraction;

if (fraction != 0)
{
s += ".";

if (f < 100)
s += "0";

if (f < 10)
s += "0";

s += std::to_string(f);
}

return s;
}

Real Real::operator-() const
{
return Real(-whole, -fraction);
}

Real Real::operator+(const Real& a) const
{
int f;
int w;

w = whole + a.whole;
f = fraction + a.fraction;

if (f >= 1000)
{
w++;
f -= 1000;
}

if (f <= -1000)
{
w--;
f += 1000;
}

if (w > 0 && f < 0)
{
w--;
f += 1000;
}

if (w < 0 && f > 0)
{
w++;
f -= 1000;
}

return Real(w, f);
}

Real& Real::operator+=(const Real& a)
{
*this = *this + a;
return *this;
}

Real Real::operator-(const Real& a) const
{
return *this + (-a);
}

Real& Real::operator-=(const Real& a)
{
*this = *this - a;
return *this;
}

Real Real::operator*(const Real& a) const
{
long long x;
long long y;
long long z;
int w;
int f;

x = (long long)whole * 1000 + fraction;
y = (long long)a.whole * 1000 + a.fraction;

z = x * y;

w = (int)(z / 1000000);
f = (int)(z % 1000000 / 1000);

return Real(w, f);
}

Real& Real::operator*=(const Real& a)
{
*this = *this * a;
return *this;
}

Real Real::operator/(const Real& a) const
{
long long x;
long long y;
long long z;
int w;
int f;

x = (long long)whole * 1000 + fraction;
y = (long long)a.whole * 1000 + a.fraction;

if (y == 0)
throw "division by zero";

z = x * 1000 / y;

w = (int)(z / 1000);
f = (int)(z % 1000);

return Real(w, f);
}

Real& Real::operator/=(const Real& a)
{
*this = *this / a;
return *this;
}

bool Real::operator==(const Real& a) const
{
return whole == a.whole && fraction == a.fraction;
}

bool Real::operator!=(const Real& a) const
{
return !(*this == a);
}

bool Real::operator<(const Real& a) const
{
if (whole != a.whole)
return whole < a.whole;

return fraction < a.fraction;
}

bool Real::operator<=(const Real& a) const
{
return *this < a || *this == a;
}

bool Real::operator>(const Real& a) const
{
return !(*this <= a);
}

bool Real::operator>=(const Real& a) const
{
return !(*this < a);
}

Real Real::sqrt() const
{
long long x;
long long left;
long long right;
long long middle;
long long answer;

x = (long long)whole * 1000 + fraction;

if (x < 0)
throw "square root of negative number";

if (x == 0)
return Real(0);

left = 0;
right = x * 1000;
answer = 0;

while (left <= right)
{
middle = (left + right) / 2;

if (middle * middle <= x * 1000)
{
answer = middle;
left = middle + 1;
}
else
{
right = middle - 1;
}
}

return Real((int)(answer / 1000),
(int)(answer % 1000));
}

std::ostream& operator<<(std::ostream& out, const Real& a)
{
out << a.toString();
return out;
}

std::istream& operator>>(std::istream& in, Real& a)
{
std::string s;

in >> s;
a = Real(s);

return in;
}

