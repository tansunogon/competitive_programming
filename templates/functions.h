#pragma once

template <class T>
void fill(T &obj, T value)
{
	obj = value;
}
template <class ArrayType, size_t N, class T>
void fill(ArrayType (&ary)[N], T value)
{
	for (size_t i = 0; i < N; ++i)
	{
		fill(ary[i], value);
	}
}



// multikey-quicksort (faster than std::sort() when you sort strings)
// http://d.hatena.ne.jp/echizen_tm/20100815/1281872393

// <- small
int si_temp_s[100000];
// <- middle ........ large ->
int si_temp_ml[100000];

// sort [l, r)
void multikey_qsort(int l, int r, int depth)
{
	if (r - l < 2)
	{
		return;
	}

	char pivot = *(s[si[l]] + depth);
	int sorted = 0;
	int small = 0;
	int middle = 0;
	int large = 0;
	for (int ins_i = l; ins_i < r; ++ins_i)
	{
		int index = si[ins_i];
		char c = *(s[index] + depth);
		if (c == '\n')
		{
			si[l + sorted++] = index;
		}
		else if (c < pivot)
		{
			si_temp_s[small++] = index;
		}
		else if (c == pivot)
		{
			si_temp_ml[middle++] = index;
		}
		else
		{
			si_temp_ml[r - ++large] = index;
		}
	}
	memcpy(si + (l + sorted), si_temp_s, sizeof(int) * small);
	memcpy(si + (l + sorted + small), si_temp_ml, sizeof(int) * middle);
	memcpy(si + (l + sorted + small + middle), si_temp_ml + (r - large), sizeof(int) * large);
	multikey_qsort(l + sorted, l + sorted + small, depth);
	multikey_qsort(l + sorted + small, l + sorted + small + middle, depth + 1);
	multikey_qsort(l + sorted + small + middle, r, depth);

}
void multikey_qsort()
{
	multikey_qsort(0, N, 0);
}