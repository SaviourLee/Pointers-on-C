// C7E6.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

#if 0
char* int2txtbelow10(int num) {
	char *str = NULL;
	switch (num) {
	case 1:
		str = "ONE";
		break;
	case 2:
		str = "TWO";
		break;
	case 3:
		str = "THREE";
		break;
	case 4:
		str = "FOUR";
		break;
	case 5:
		str = "FIVE";
		break;
	case 6:
		str = "SIX";
		break;
	case 7:
		str = "SEVEN";
		break;
	case 8:
		str = "EIGHT";
		break;
	case 9:
		str = "NINE";
		break;
	case 10:
		str = "TEN";
		break;
	}
	return str;
}

char* int2txt10to20(int num) {
	char *str = NULL;
	switch (num) {
	case 11:
		str = "ELEVEN";
		break;
	case 12:
		str = "TWELVE";
		break;
	case 13:
		str = "THIRTEEN";
		break;
	case 14:
		str = "FOURTEEN";
		break;
	case 15:
		str = "FIFTEEN";
		break;
	case 16:
		str = "SIXTEEN";
		break;
	case 17:
		str = "SEVENTEEN";
		break;
	case 18:
		str = "EIGHTEEN";
		break;
	case 19:
		str = "NINETEEN";
		break;
	}
	return str;
}

char* int2txtover20(int num) {
	char *str = NULL;
	switch (num) {
	case 2:
		str = "TWENTY";
		break;
	case 3:
		str = "THIRTY";
		break;
	case 4:
		str = "FOURTY";
		break;
	case 5:
		str = "FIFTY";
		break;
	case 6:
		str = "SIXTY";
		break;
	case 7:
		str = "SEVENTY";
		break;
	case 8:
		str = "EIGHTY";
		break;
	case 9:
		str = "NINETY";
		break;
	}
	return str;
}


char* int2txt(int num) {
	char *str;
	if (num < 20) {
		switch (num) {
		case 1:
			str = "ONE";
			break;
		case 2:
			str = "TWO";
			break;
		case 3:
			str = "THREE";
			break;
		case 4:
			str = "FOUR";
			break;
		case 5:
			str = "FIVE";
			break;
		case 6:
			str = "SIX";
			break;
		case 7:
			str = "SEVEN";
			break;
		case 8:
			str = "EIGHT";
			break;
		case 9:
			str = "NINE";
			break;
		case 10:
			str = "TEN";
			break;
		case 11:
			str = "ELEVEN";
			break;
		case 12:
			str = "TWELVE";
			break;
		case 13:
			str = "THIRTEEN";
			break;
		case 14:
			str = "FOURTEEN";
			break;
		case 15:
			str = "FIFTEEN";
			break;
		case 16:
			str = "SIXTEEN";
			break;
		case 17:
			str = "SEVENTEEN";
			break;
		case 18:
			str = "EIGHTEEN";
			break;
		case 19:
			str = "NINETEEN";
			break;
		}
	}
	return str;
}
#endif

static char *digits[] = {"", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN",
							"EIGHT", "NINE", "TEN", "ELEVEN", "TWELVE", "THIRTEEN",
							"FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EITHTEEN"
							"NINTEEN"};
static char *tens[] = {
	"", "", "TWENTY ", "THIRTY ", "FORTY ", "FIFTY ", "SIXTY ", "SEVENTY ",
	"EIGHTY ", "NINETY "
};

static char *magnitudes[] = {
	"", " THOUSAND ", " MILLION ", " BILLION "
};

static void
do_one_group(unsigned int amount, char *buffer, char **magnitude)
{
	int value = amount / 1000;
	if (value > 0) {
		do_one_group(value, buffer, magnitude + 1);
	}
	amount %= 1000;
	value = amount / 100;
	if (value > 0) {
		strcat(buffer, digits[value]);
		strcat(buffer, " HUNDERD ");
	}
	value = amount % 100;
	if (value >= 20) {
		strcat(buffer, tens[value / 10]);
//		strcat(buffer, " ");
		strcat(buffer, digits[value % 10]);
	}else
		strcat(buffer, digits[value]);
	if(amount > 0)
		strcat(buffer, *magnitude);

}

void written_amount(unsigned int amount, char *buffer) {
/*	int temp = 0;
	temp = amount / 100;
	strcat(buffer, int2txtbelow10(temp));
	strcat(buffer, " HUNDERD ");
	amount %= 100;
	if (amount <= 10)
		strcat(buffer, int2txtbelow10(amount));
	else if (amount < 20) {
		strcat(buffer, int2txt10to20(amount));
	}
	else{
		temp = amount % 10;
		amount /= 10;
		strcat(buffer, int2txtover20(amount));
		strcat(buffer, " ");
		strcat(buffer, int2txt10to20(temp));
	}
	printf("%s\n", buffer);*/
	if (amount == 0) {
		strcat(buffer, "ZERO");
	}
	do_one_group(amount, buffer, magnitudes);

}

int main()
{
	char buf[200] = "\0";
	written_amount(1223, buf);
	printf("%s", buf);
    return 0;
}

