// C5E4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

unsigned character_offset(unsigned bit_number) {
	return bit_number / 8;
}
unsigned bit_offset(unsigned bit_number) {
	return bit_number % 8;
}
void set_bit(char bit_array[], unsigned bit_number) {
	//if (bit_number >= )
	bit_array[character_offset(bit_number)] |= 1 << bit_offset(bit_number);
}

void clear_bit(char bit_array[], unsigned bit_number) {
	bit_array[character_offset(bit_number)] &= ~(1 << bit_offset(bit_number));
}
void assign_bit(char bit_array[], unsigned bit_number, int value) {

}
int test_bit(char bit_array[], unsigned bit_number) {
	return bit_array[character_offset(bit_number)] & 1 << bit_offset(bit_number);
}
int main()
{
	return 0;
}

