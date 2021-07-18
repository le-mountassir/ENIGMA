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
	char choice;
	int rotor;
	printf("Do you want to ENCr or DECr ? [E] [D]\n");
	scanf("%s", &choice);
	if(choice == 'e' || choice =='E'){
		char message[500];
		printf("type the message you want to encrypte\n");
		scanf("%s", message);
		printf("how many Rotors you want to use? 1-5\n");
		scanf("%d", &rotor);
	}
	else if(choice == 'd'|| choice == 'D'){
		int code[20];
		printf("enter the keys:\n Rotors: ")
		scanf();
		printf("\nstarting point :")
		printf("type the code you want to decrypte\n");
		scanf("%s", code);
	}
	else
		printf("wrong option");
	return 0;
}
