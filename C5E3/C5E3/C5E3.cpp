// C5E3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int reverse_bits(unsigned int value) {
	unsigned int temp = 0;
	int i = 1;
	while (i <<= 1) {	//让1不断右移，直到移出得零
		int last_bit = value & 1;
		temp |= last_bit;
		temp <<= 1;
		value >>= 1;
	}
	return temp;
}
int main() {
	printf("%u", reverse_bits(25));

	return 0;
}
