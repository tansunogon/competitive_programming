#pragma once

struct Mat
{
	double a = 1.0;
	double b = 0.0;

	Mat operator*(const Mat& rhs) const
	{
		Mat ret;
		ret.a = this->a * rhs.a;
		ret.b = this->a * rhs.b + this->b;
		return ret;
	}
};

long long N;
int M;
long long index[100000];
long long sorted_index[100000];
Mat input_data[100000];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> index[i] >> input_data[i].a >> input_data[i].b;
		sorted_index[i] = index[i];
	}
	sort(sorted_index, sorted_index + M);

	int seg_base = 1;
	while (seg_base < M)
	{
		seg_base *= 2;
	}
	std::vector<Mat> seg(seg_base * 2);

	auto setval = [&](int k, Mat v)
	{
		k += seg_base;
		seg[k] = v;
		while (k > 1)
		{
			k /= 2;
			seg[k] = seg[k * 2 + 1] * seg[k * 2];
		}
	};

	auto getval = [&](int k) -> Mat
	{
		if (k == N)
		{
			return seg[1];
		}
		k += seg_base;
		Mat ret;
		while (k > 1)
		{
			if (k & 1)
			{
				ret = ret * seg[k - 1];
			}
			k /= 2;
		}
		return ret;
	};

	double min_yummy = 1.0;
	double max_yummy = 1.0;
	for (int i = 0; i < M; ++i)
	{
		long long q = index[i];
		int shrinked_index = lower_bound(sorted_index, sorted_index + M, q) - sorted_index;

		setval(shrinked_index, input_data[i]);

		double yummy = seg[1].a + seg[1].b;
		min_yummy = min(min_yummy, yummy);
		max_yummy = max(max_yummy, yummy);
	}

	printf("%.7f\n%.7f\n", min_yummy, max_yummy);
}
