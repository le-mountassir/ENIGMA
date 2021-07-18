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
	int enc_st;
	printf("Do you want to ENCr or DECr ? [E] [D]\n");
	scanf("%s", &choice);
	if(choice == 'e' || choice =='E'){
		char message[500];
		printf("type the message you want to encrypte\n");
		scanf("%s", message);
		printf("how many Rotors you want to use? 1-5\n-");
		scanf("%d", &rotor);
		printf("select the encryption stating point 1-16\n-");
		scanf("%d", &enc_st);
		//printf("encryption done :\n %s", );
		printf("your decryption codes \n-R: %d\n-S.P: %d", rotor, enc_st);
	}
	else if(choice == 'd'|| choice == 'D'){
		int code[20];
		printf("enter the keys:\n 1-R: ");
		scanf("%d", &rotor);
		printf("\n2-S.P: ");
		scanf("%d", &enc_st);
		printf("type the code you want to decrypte\n");
		scanf("%ls", code);
	}
	else
		printf("wrong option");
	return 0;
}
