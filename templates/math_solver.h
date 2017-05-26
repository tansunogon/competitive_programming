#pragma once

// f(n) = n の約数の数
//   例: n = 6 のとき、{1, 2, 3, 6} の 4 つ
// としたとき、
// [1, num] で f(n) の和を計算する。
//   例: num = 3 のとき、
//        f(1) = 1, {1}
//        f(2) = 2, {1, 2}
//        f(3) = 2, {1,    3} より
//        ans = 5 となる
//
// ab <= num となる、自然数 a, b の組み合わせの個数を数える
// O(num^(1/2))
#include <cmath>
int sum_of_divisors_of_not_more_than_num(int num)
{
	int ans = 0;
	int s = std::sqrt(num);
	for (int k = 1; k <= s; ++k)
		ans += num / k;
	return 2 * ans - s*s;
}

