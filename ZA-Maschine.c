#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *lower(char *code){
	int i = 0;
	while(code[i]){
		if(code[i] <= 'Z' && code[i] >= 'A')
			code[i] += 32;
		i++;
	}
	return code;
}

int main(){
	char choice[1];
	printf("Do you want to ENCr or DECr ? [E] [D]\n");
	scanf("%s", choice);
	if(choice[0] == 'e' ||choice[0]=='E'){
		char message[500];
		printf("type the message you want to encrypte\n");
		scanf("%s", message);
		printf("%s", lower(message));
	}
	else if(choice[0] == 'd'|| choice[0]=='D'){
		printf("typre the code you want to decrypte\n");
		int code[20];
	}
	else
		printf("wrong option");
	return 0;
}
