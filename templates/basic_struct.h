#pragma once

#include <iostream>
struct iostream_init_struct
{ 
	iostream_init_struct()
	{
		std::cin.tie(0);
		std::ios::sync_with_stdio(false);
	}
} iostream_init;

using ll = long long;
struct initll
{
public:
	long long value = -1e15;
	initll() {}
	initll(long long value) : value(value) {}
	operator long long() const
	{
		return value;
	}
};
struct initl
{
public:
	long value = -1;
	initl() {}
	initl(long value) : value(value) {}
	operator long() const
	{
		return value;
	}
};

class modll
{
public:
	static const long long MOD;
	long long value;
	modll() : value(0) {}
	modll(long long value) : value(value) {}
	modll operator+(const modll& rhs) const
	{
		modll ret;
		ret.value = (value + rhs.value) % MOD;
		return ret;
	}
	modll operator+=(const modll& rhs)
	{
		value = (value + rhs.value) % MOD;
		return *this;
	}
	modll operator-(const modll& rhs) const
	{
		modll ret;
		ret.value = (value - rhs.value + MOD) % MOD;
		return ret;
	}
	modll operator-=(const modll& rhs)
	{
		value = (value - rhs.value + MOD) % MOD;
		return *this;
	}
	modll operator*(const modll& rhs) const
	{
		modll ret;
		ret.value = (value * rhs.value) % MOD;
		return ret;
	}
	modll operator*=(const modll& rhs)
	{
		value = (value * rhs.value) % MOD;
		return *this;
	}
	operator long long() const
	{
		return value;
	}
};
const long long modll::MOD = 1e9 + 7;

class modl
{
public:
	static const long MOD;
	long value;
	modl() : value(0) {}
	modl(long value) : value(value) {}
	modl operator+(const modl& rhs) const
	{
		modl ret;
		ret.value = (value + rhs.value) % MOD;
		return ret;
	}
	modl operator+=(const modl& rhs)
	{
		value = (value + rhs.value) % MOD;
		return *this;
	}
	operator long() const
	{
		return value;
	}
};
const long modl::MOD = 1e9;

#include <boost/multiprecision/cpp_int.hpp>
using cpp_int = boost::multiprecision::cpp_int;

#include <boost/multiprecision/cpp_bin_float.hpp>
using float_100 = boost::multiprecision::cpp_bin_float_100;

#include <vector>
#include <cstdio>
class cpp_uint
{
	static const unsigned long MOD;
public:
	std::vector<unsigned long> vec;
	void operator=(unsigned long value)
	{
		vec.clear();
		vec.push_back(value);
	}
	void operator+=(const cpp_uint& rhs)
	{
		unsigned long carry = 0;
		size_t i = 0;
		for (; i < rhs.vec.size(); ++i)
		{
			unsigned long long temp = carry;
			temp += rhs.vec[i];
			if (i < vec.size())
			{
				temp += vec[i];
				unsigned long lower = temp % MOD;
				unsigned long upper = temp / MOD;
				vec[i] = lower;
				carry = upper;
			}
			else
			{
				unsigned long lower = temp % MOD;
				unsigned long upper = temp / MOD;
				vec.push_back(lower);
				carry = upper;
			}
		}
		if (carry > 0)
		{
			unsigned long long temp = carry;
			if (i < vec.size())
			{
				temp += vec[i];
				unsigned long lower = temp % MOD;
				unsigned long upper = temp / MOD;
				vec[i] = lower;
				carry = upper;
			}
			else
			{
				unsigned long lower = temp % MOD;
				unsigned long upper = temp / MOD;
				vec.push_back(lower);
				carry = upper;
			}
		}
	}
	void print() const
	{
		for (int i = vec.size() - 1; i >= 0; --i)
		{
			if (i == vec.size() - 1)
				std::printf("%lu", vec[i]);
			else
				std::printf("%09lu", vec[i]);
		}
	}
};
const unsigned long cpp_uint::MOD = 1e9;

// represents 1 + p
class around_one
{
public:
	double p;
	around_one() : p () {}
	around_one(double p) : p(p) {}
	operator double() const
	{
		return 1.0 + p;
	}
	around_one square() const
	{
		return around_one(2 * p + p * p);
	}
	void operator*=(const around_one& rhs)
	{
		p += rhs.p + p * rhs.p;
	}
	around_one pow(unsigned long long n) const
	{
		around_one ret;
		around_one power_of_two(p);
		while (n > 0)
		{
			if (n & 1)
				ret *= power_of_two;
			power_of_two = power_of_two.square();
			n /= 2;
		}
		return ret;
	}
};