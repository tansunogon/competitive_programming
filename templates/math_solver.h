#pragma once

// f(n) = n �̖񐔂̐�
//   ��: n = 6 �̂Ƃ��A{1, 2, 3, 6} �� 4 ��
// �Ƃ����Ƃ��A
// [1, num] �� f(n) �̘a���v�Z����B
//   ��: num = 3 �̂Ƃ��A
//        f(1) = 1, {1}
//        f(2) = 2, {1, 2}
//        f(3) = 2, {1,    3} ���
//        ans = 5 �ƂȂ�
//
// ab <= num �ƂȂ�A���R�� a, b �̑g�ݍ��킹�̌��𐔂���
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

