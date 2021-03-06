// C9E12.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
int prepare_key(char *key) {
	if (strlen(key) == 0)
		return FALSE;
	for (int i = 0; i < strlen(key); i++) {
		if (!isalpha(key[i]))
			return FALSE;
		toupper(key[i]);
	}
	char* orig = key;
	char cha = 'A';
	for (int i = strlen(key); i < 26; i++) {
		while (strchr(orig, cha) != NULL)
			cha++;
		key[i] = cha;
	}
	key[26] = '\0';


	return TRUE;
}
void encrypt(char *data, char const *key) {
	while(*data != '\0'){
		if (!isalpha(*data))
			continue;
		if (isupper(*data)) {
			*data = *(key + (*data - 'A'));
		}
		else if (islower(*data)) {
			*data = tolower(*(key + (toupper(*data) - 'A')));
		}
		data++;
	}
}
void decrypt(char *data, char const *key) {
//	char *temp = data;
	while (*data != '\0') {
		int loc = strchr(key, toupper(*data)) - key;
		if (islower(*data))
			*data = 'a' + loc;
		else if (isupper(*data))
			*data = 'A' + loc;
		data++;
	}
}

int main()
{
	char d[] = "AbcDEFG";
	char str[27] = "FUCK";
	prepare_key(str);
	printf("%s\n", str);
	encrypt(d, str);
	printf("%s\n", d);
	decrypt(d, str);
	printf("%s\n", d);
    return 0;
}

