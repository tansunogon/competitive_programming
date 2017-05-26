#pragma once


class RMQ_SparseTable
{
public:
	// table[k][i] means minimum value in [i, i + 2^k)
	// simple code: std::vector<std::vector<int>> table;
	std::vector<int*> table;
	std::vector<int> table_data;

	RMQ_SparseTable(int* A, size_t N)
	{
		// init table (try to make a compact table)
		// simple code: table = std::vector<std::vector<int>>(log(N) + 1, vector<int>(N));
		size_t K_size = log(N) + 1;
		table = std::vector<int*>(K_size);
		table_data = std::vector<int>((N + 1) * K_size - (1 << K_size) + 1);
		for (int k = 0, allocated = 0; k < K_size; ++k)
		{
			table[k] = table_data.data() + allocated;
			allocated += N + 1 - (1 << k);
		}

		for (int i = 0; i < N; ++i)
		{
			table[0][i] = A[i];
		}

		for (int k = 1; (1 << k) <= N; ++k)
		{
			for (int i = 0; i + (1 << k) <= N; ++i)
			{
				table[k][i] = min(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
			}
		}
	}

	// returns min value in [s, t)
	inline int getMin(int s, int t)
	{
		int range = t - s;
		int k = log(range);

		int value1 = table[k][s];
		if (value1 == 0)
			return 0;

		int value2 = table[k][t - (1 << k)];
		return min(value1, value2);
	}

	inline static int log(int n)
	{
		//int ret = 0;
		//while (n = n >> 1)
		//{
		//	ret += 1;
		//}
		//return ret;

#ifdef __GNUC__
		return std::__lg(n);
#else
		if (n >= (1 << 16))
		{
			return 16;
		}
		else if (n >= (1 << 15))
		{
			return 15;
		}
		else if (n >= (1 << 14))
		{
			return 14;
		}
		else if (n >= (1 << 13))
		{
			return 13;
		}
		else if (n >= (1 << 12))
		{
			return 12;
		}
		else if (n >= (1 << 11))
		{
			return 11;
		}
		else if (n >= (1 << 10))
		{
			return 10;
		}
		else if (n >= (1 << 9))
		{
			return 9;
		}
		else if (n >= (1 << 8))
		{
			return 8;
		}
		else if (n >= (1 << 7))
		{
			return 7;
		}
		else if (n >= (1 << 6))
		{
			return 6;
		}
		else if (n >= (1 << 5))
		{
			return 5;
		}
		else if (n >= (1 << 4))
		{
			return 4;
		}
		else if (n >= (1 << 3))
		{
			return 3;
		}
		else if (n >= (1 << 2))
		{
			return 2;
		}
		else if (n >= (1 << 1))
		{
			return 1;
		}
		else
		{
			return 0;
		}
#endif
	}
};