#pragma once


// index begins with 1
class BIT
{
public:
	vector<long long> data;
	const int msb_n;

	BIT(int n) : data(n + 1), msb_n(msb(n)) {}

	void add(int i, int v)
	{
		for (int x = i; x < data.size(); x += x & -x)
		{
			data[x] += v;
		}
	}

	//long long sum(int i)
	//{
	//	int ret = 0;
	//	for (int x = i; x > 0; x -= x & -x)
	//	{
	//		ret += data[x];
	//	}
	//	return ret;
	//}

	int lowerBound(long long v)
	{
		int x = 0;
		for (int k = msb_n; k > 0; k /= 2)
		{
			if (x + k < data.size() && data[x + k] < v)
			{
				v -= data[x + k];
				x += k;
			}
		}
		return x + 1;
	}

	inline static int msb(int n)
	{
		int ret = 1;
		while (ret <= n)
		{
			ret *= 2;
		}
		return ret / 2;
	}
};

// index begins with 1
class BIT_RangeAdd
{
public:
	std::vector<long long[2]> data;
	const int msb_n;

	BIT_RangeAdd(size_t n) : data(n + 2), msb_n(msb(n + 1)) {}

	// add v to every var in [l, r)
	void rangeAdd(long long v, int l, int r)
	{
		for (int i = l; i < data.size(); i += i & -i)
		{
			data[i][0] -= v * l;
			data[i][1] += v;
		}

		for (int i = r; i < data.size(); i += i & -i)
		{
			data[i][0] += v * r;
			data[i][1] -= v;
		}
	}

	// sum of [1, index)
	long long sum(int index)
	{
		long long value0 = 0;
		long long value1 = 0;
		for (int i = index; i > 0; i -= i & -i)
		{
			value0 += data[i][0];
			value1 += data[i][1];
		}
		return value0 + index  * value1;
	}

	int lowerBound(int v)
	{
		int x = 0;
		long long value0 = 0;
		long long value1 = 0;
		for (int k = msb_n; k > 0; k /= 2)
		{
			if (x + k >= data.size())
			{
				continue;
			}
			if (value0 + data[x + k][0] + (value1 + data[x + k][1]) * (x + k) < v)
			{
				value0 += data[x + k][0];
				value1 += data[x + k][1];
				x += k;
			}
		}
		return x;
	}

	inline static int msb(int n)
	{
		int ret = 1;
		while (ret <= n)
		{
			ret *= 2;
		}
		return ret / 2;
	}
};