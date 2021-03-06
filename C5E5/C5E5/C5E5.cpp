// C5E5.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int set_bit(int value, int bit_col) {
	return value |= 1 << bit_col;
}
int clear_bit(int value, int bit_col) {
	return value &= ~(1 << bit_col);
}
int assign_bit(int value, int bit_col, int flag) {
	if (flag)
		return set_bit(value, bit_col);
	else
		return clear_bit(value, bit_col);
}


int
store_bit_field(int original_value, int value_to_store,
	unsigned starting_bit, unsigned ending_bit) {
	while (ending_bit != starting_bit + 1) {
		int bit;
		if (!value_to_store)			//如果已经全部存入，则补零
			bit = 0;
		else
			bit = value_to_store & 1;		//否则取最低位
		original_value = assign_bit(original_value, ending_bit, bit);
		ending_bit++;
		value_to_store >>= 1;
	}
	return original_value;
}

int main()
{
	unsigned int  mask = ~0;
	printf("%x", mask);
	int dst, src, beg, end;
	scanf("%x,%x,%d,%d", &dst, &src, &beg, &end);
	printf("0x%x", store_bit_field(dst, src, beg, end));

    return 0;
}

