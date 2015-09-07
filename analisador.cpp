#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ehLetra(char c){
	if((c>=65 && c<=90) || (c>=97 && c<=122))
		return 1;
	else
		return 0;
}

int ehNumero(char c){
	if((c>=49 && c<=57))
		return 1;
	else
		return 0;
}

int ehCaracter(char c){
	if(ehLetra(c) || ehNumero(c))
		return 1;
	else
		return 0;
}

void acrescentaCaracter(char *s, char c){
	int len = strlen(s);
	s[len] = c;
	s[len + 1] = '\0';
}

int main(){

	char entrada[255];
	char lexema[255] = "";
	char ch;
	int i = 0;

	FILE *fp;
	printf("informe o nome do arquivo de entrada : ");
	scanf("%s", entrada);
	fp = fopen(entrada,"r");

	while( (ch=fgetc(fp))!= EOF ){
		if(ehLetra(ch)){
			acrescentaCaracter(lexema,ch);
			ch=fgetc(fp);
			while(ehLetra(ch) || ehNumero(ch)){
				acrescentaCaracter(lexema,ch);
				ch=fgetc(fp);
			}
			printf("%s\n", lexema);
			strcpy(lexema,"");
		}
		else if(ehNumero(ch)){
			acrescentaCaracter(lexema,ch);
			ch=fgetc(fp);
			while(ehNumero(ch)){
				acrescentaCaracter(lexema,ch);
				ch=fgetc(fp);
			}
			printf("%s\n", lexema);
			strcpy(lexema,"");
		}				
	}

	fclose(fp);

	return 0;
}
