/* Data da submissao: 28/06/2020
* Nome: Luiz Guilherme Silva Moreira
* RA: 202391
*/

#include <stdio.h>

/* Definicoes de variaveis */
#define TAM_BUFFER 60
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];
char chave[] = "SENHASECRETA";

int main() {
	/* Variaveis auxiliares */
	int aux_int = 0, letra = 0, k = 0, deslocamento = 0, cont_chave = 0;
	char decode;
	
	/* Leitura da entrada */
	fgets(buffer_entrada, TAM_BUFFER, stdin);

	k = 0;
	cont_chave = 0;

	/* Decodificacao */	
	while(buffer_entrada[k] != '\n'){

		if(buffer_entrada[k] < 65 || buffer_entrada[k] > 90){
			buffer_saida[k] = buffer_entrada[k];
		}else{
			aux_int = buffer_entrada[k];
			letra = chave[cont_chave];
			
			if(aux_int >= letra){
				deslocamento = (aux_int - letra) + 1;
			}else if(aux_int < letra){
				deslocamento = ((90 - letra) + 1) + ((aux_int - 65) + 1);
			}
			decode = 64 + deslocamento;
			buffer_saida[k] = decode; 
		}
		
		if(cont_chave < 11){
			cont_chave++;
		}else{
			cont_chave = 0;
		}
		
		k++;
	}

	/* Escrever saida na tela */
	printf("%s\n", buffer_saida);

	return 0;
}
