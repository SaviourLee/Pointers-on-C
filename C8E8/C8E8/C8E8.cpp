// C8E8.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
bool chess_board[8][8] = { 0 };
#if 0
bool check_attack(int x, int y) {
	return chess_board[x][y] != 0;
}
void sign_attack_range(int x, int y) {
	for (int i = 0; i < 8; i++) {
		if(i != y)//chess_board[x][i] != 2)
			chess_board[x][i] = 1;
		if (i != x)
			chess_board[i][y] = 1;
		if(chess_board[(x + i) % 8][(y + i) % 8] != 2)
			chess_board[(x + i) % 8][(y + i) % 8] = 1;//标记正斜线
//		printf("x = %d, y = %d, i = %d\n", x, y, i);
		if(x - i >= 0 && y + i < 8) {	//反斜线
			if (chess_board[x-i][y+i] != 2)
				chess_board[x-i][y+i] = 1;
		}
		if(y - i >= 0 && x + i <8) {	//反斜线
			if (chess_board[x + i][y - i] != 2)
				chess_board[x + i][y - i] = 1;
		}
//		printf("test\n");
	}
}
void unsign_attack_range(int x, int y) {
	for (int i = 0; i < 8; i++) {
		if (chess_board[x][i] != 2)
			chess_board[x][i] = 0;
		if (chess_board[i][y] != 2)
			chess_board[i][y] = 0;
		if (chess_board[(x + i) % 8][(y + i) % 8] != 2)
			chess_board[(x + i) % 8][(y + i) % 8] = 0;//标记正斜线
													  //		printf("x = %d, y = %d, i = %d\n", x, y, i);
		if (x - i >= 0 && y + i < 8) {	//反斜线
			if (chess_board[x - i][y + i] != 2)
				chess_board[x - i][y + i] = 0;
		}
		if (y - i >= 0 && x + i <8) {	//反斜线
			if (chess_board[x + i][y - i] != 2)
				chess_board[x + i][y - i] = 0;
		}
		//		printf("test\n");
	}
}

void print_chess_board() {
	printf("\n");
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%d ", chess_board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
bool put_queen_in_line(int x) {
//	bool flag = false;
	int i;
	printf("level %d\n", x+1);
	for (i = 0; i < 8; i++) {
		printf("i = %d ", i);
		if (!check_attack(x, i)) {	//如果未被攻击
			chess_board[x][i] = 2;	//放置王后
//			flag = true;
			sign_attack_range(x, i);	//标记其位置
			print_chess_board();
			if (x + 1 > 8)
				break;
			bool result = put_queen_in_line(x + 1);//计算下一行
			if (!result) {		//失败继续下次循环
				chess_board[x][i] = 0;
				unsign_attack_range(x, i);
				continue;
			}
			return true;		//成功则返回
		}
	}
	printf("i = %d\n", i);
	if (i >= 8)
		return false;
	
	
}
#endif //自己的思路有问题

void print_chess_board() {
	static int cnt = 0;
	cnt++;
	printf("This is the %d answer:\n", cnt);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chess_board[i][j])
				printf("Q");
			else
				printf("+");
		}
		printf("\n");
	}
	printf("\n");
}
bool check_attack(int x, int y) {
	for (int i = 1; i < 8; i++) {
//		if (chess_board[i][y])//不用检查行，因为递归一定是从新行开始的
//			return false;
//		printf("checking x = %d, i = %d\n", x, i);
//		printf("chess_board[%d][%d]: %d\n", x-i, y, chess_board[x - i][y]);
//		printf("--------------------------------------------\n");
//		print_chess_board();
//		printf("--------------------------------------------\n");
		if (x >= i && chess_board[x - i][y]) {//检查列(上方)
//			printf("error 1\n");
			return true;
		}
		if (y - i >= 0 && chess_board[x][y - i]) {
//			printf("error 2\n");
			return true;
		}
		if (y + i < 8 && chess_board[x][y + i]) {
//			printf("error 3\n");
			return true;
		}	
		if (x >= i && y >= i && chess_board[x - i][y - i]) { //检查左上
//			printf("error 4\n");
			return true;
		}
		if ((x >= i && y + i < 8) && chess_board[x - i][y + i]) {	//检查右上
//			printf("error 5\n");
			return true;
		}
	}
//	printf("返回false x = %d\n", x);
	return false;
}
void place_queen(int x) {
//	printf("x = %d\n", x);
//	print_chess_board();
	for (int y = 0; y < 8; y++) {
		chess_board[x][y] = true;
//		printf("x = %d, y = %d\n", x, y);
		if (x == 0 || !check_attack(x, y)) {
//			printf("y = %d\n", y);
			if (x < 7) {
//				printf("before x = %d\n", x);
				place_queen(x + 1);
//				printf("after x = %d\n", x);
			}
			else {
				print_chess_board();
//				printf("test1\n");
			}
		}
		chess_board[x][y] = false;
	}
}

int main()
{
	place_queen(0);
//	put_queen_in_line(0);
//	print_chess_board();
    return 0;
}

