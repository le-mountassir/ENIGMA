#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *rot(char *message, int rotor, int s_p, int rdm){
	int i;
	while(rotor > 0){
		i = 0;
		while(message[i]){
			int enc = s_p;
			if(message[i] <= 'z' && message[i] >= 'a'){
					while(enc > 0){
						if(message[i]== 'z')
							message[i] = 'a';
						else
							message[i]++;
						enc--;
					}
			}
			s_p += rdm;
			i++;
		}
		s_p +=12;
		rotor--;
	}
	return message;
}
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
	int rdm;
	printf("Do you want to ENCr or DECr ? [E] [D]\n");
	scanf("%s", &choice);
	if(choice == 'e' || choice =='E'){
		char message[500];
		printf("type the message you want to encrypte\n");
		scanf("%s", message);
		printf("how many Rotors you want to use? 3->5\n-");
		scanf("%d", &rotor);
		printf("select the encryption stating point 1->16\n-");
		scanf("%d", &enc_st);
		printf("choose a number between 1->12\n-");
		scanf("%d", &rdm);
		printf("\nencryption done :\n %s ", rot(message, rotor, enc_st, rdm) );
		printf("\nyour decryption codes \n-R: %d\n-S.P: %d\n-R_number: %d", rotor, enc_st, rdm);
	}
	else if(choice == 'd'|| choice == 'D'){
		int code[20];
		printf("enter the keys:\n 1-R: ");
		scanf("%d", &rotor);
		printf("\n2-S.P: ");
		scanf("%d", &enc_st);
		printf("\n 3-R_number: ");
		scanf("%d", &rdm);
		printf("type the code you want to decrypte\n");
		scanf("%ls", code);
	}
	else
		printf("wrong option");
	return 0;
}
