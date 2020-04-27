#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,string argv[])
{	//Parte 1 obtencion de key y validacion
	if(argc != 2){
		
		printf("Usage: ./caesar KEY <int>\n");
		return 1;
	}
		
		
		
		
		
		
		int k=atoi(argv[1]);
		
		if(k<0 ){
			printf("Usage: ./caesar KEY <int>\n");
			return 1;
		}
		
	
		//Parte 2 moldeado de key y texto
		string plaintext = get_string("Plaintext: ");
		printf("ciphertext: ");
		//parte 3 separacion de letra u Otro
		//for para recorrer el string en Char
			for(int i=0;i<strlen(plaintext);i++)
			{	
				//verificar si es letra u otro
				//funcion isalpha
					if(isalpha(plaintext[i])){
						//verificar cual es mayuscula y cual no
							if(islower(plaintext[i])){
								//formula con minusculas c i = (p i + k)% 26
								printf("%c",((((plaintext[i]-'a')+k)%26)+'a'));
							}else{
								//formula con mayuscula c i = (p i + k)% 26
								printf("%c",((((plaintext[i]-'A')+k)%26)+'A'));
							}// aca termina mayuscula o minuscula
							
						
						
					}else{// si es otro NO letra sale por aqui, en char, sin formula
						printf("%c",plaintext[i]);
					}//aca termina el if de alpha
					
					
				
				
				// aca termina el for
			}
	
		printf("\n");
	
}
	
	
