#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int len = 0;
int dec;

char *int_char(int *code){
	int i = 0;
	while(code[i]){
		i++;
	}
	char *stri;
	stri = (char *)malloc((i+1) * sizeof(char));
	i = 0;
	while(code[i]){
		stri[i] = code[i] + 96;
		i++;
	}
	return stri;
}
int *char_2int(char *message){
	int i;
	while(message[len])
		len++;
	int *rt;
	rt = (int *)malloc(len * sizeof(int));
	i = 0;
	while(message[i]){
	rt[i] = message[i] - 96;
		i++;
	}
	return rt;
}

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
		s_p +=(rdm+3);
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
	int x = 0;
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
		printf("choose a number between 4->12\n-");
		scanf("%d", &rdm);
		int *arra;
		arra = (int *)malloc(len * sizeof(int));
		arra = char_2int(rot(message, rotor, enc_st, rdm));
		for(x; x < len; x++){
			printf("%d",arra[x]);
			if(!(x+1 == len))
				printf(" ,");
		}
		printf("\nyour decryption keys \n-1: %d\n-2: %d\n-3: %d", rotor, enc_st, rdm);
	}
	else if(choice == 'd'|| choice == 'D'){
		dec = 1;
		int *code;
		int i = 0;
		code = (int *)malloc(20 * sizeof(int));
		printf("enter the keys:\n1-: ");
		scanf("%d", &rotor);
		printf("\n2-: ");
		scanf("%d", &enc_st);
		printf("\n3-: ");
		scanf("%d", &rdm);
		printf("type the code you want to decrypte *press enter after each code*\n");
		while(i < 5){
			scanf("%d", &code[i]);
			i++;
		}
		printf("Decryption : %s",int_char(code));
	}
	else
		printf("wrong option");
	return 0;
}
