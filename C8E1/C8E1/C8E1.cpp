// C8E1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	char char_value[3][6][4][5] = {
		{//0
			{//0,0
				{0}
			}
		},
		{//1
			{//1,0
				{0}
			},
			{//1,1
				{0},
				{0,' '}
			},
			{//1,2
				{0},
				{0},
				{0, 0, 0, 'A'},
				{0, 0, 0, 0, 'x'}
			},
			{//1,3
				{0},
				{0},
				{0, 0, 0xf3}
			},
			{//1,4
				{0},
				{0},
				{0, 0, 0, '\n'}
			}
		},
		{//2

		}
	};
    return 0;
}

