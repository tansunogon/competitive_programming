#pragma once

#include <initializer_list>
template <typename T, size_t N>
class square_matrix
{
public:
	T ary[N][N] = {};
	square_matrix(bool identity = false)
	{
		if (identity)
		{
			for (size_t i = 0; i < N; ++i)
			{
				ary[i][i] = 1;
			}
		}
	}
	square_matrix(std::initializer_list<std::initializer_list<int>> list)
	{
		size_t r = 0;
		for (auto row : list)
		{
			size_t c = 0;
			for (auto element : row)
			{
				ary[r][c] = element;
				++c;
			}
			++r;
		}
	}
	square_matrix operator*(const square_matrix& rhs) const
	{
		square_matrix ret;
		for (size_t i = 0; i < N; ++i)
		{
			for (size_t k = 0; k < N; ++k)
			{
				for (size_t j = 0; j < N; ++j)
				{
					ret.ary[i][j] += this->ary[i][k] * rhs.ary[k][j];
				}
			}
		}
		return ret;
	}
	square_matrix pow(long long n) const
	{
		square_matrix ret(true);
		square_matrix pow_of_two = *this;
		while (n > 0)
		{
			if (n & 1)
				ret = ret * pow_of_two;
			pow_of_two = pow_of_two * pow_of_two;
			n >>= 1;
		}
		return ret;
	}
};