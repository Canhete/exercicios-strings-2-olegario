/* 4. Subistitua e Remova
Considere as duas regras a seguir que devem ser aplicadas a um vetor de caracteres.
• Substitua cada 'a' por dois 'd's.
• Exclua cada entrada que contenha um 'b'.
Por exemplo, aplicar essas regras ao vetor (a, c, d, b, b, c, a) resulta no vetor (d, d, c, d, c, d, d).
Escreva um programa que tome como entrada um vetor de caracteres e remova cada 'b' e
substitua cada 'a' por dois 'd's. Especificamente, junto com o vetor, você recebe um tamanho
de valor inteiro. Tamanho denota o número de entradas do vetor ao qual a operação deve ser
aplicada. Você não precisa se preocupar em preservar as entradas subsequentes. Por exemplo,
se o vetor for (a, b, a, c, _) e o tamanho for 4, então você pode retornar (d, d, d, d, c).
Você pode assumir que há espaço suficiente no vetor para manter o resultado final. */

#include <stdio.h>
#include <string.h>

void trocar(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void regras(char *string){
    for(int i=0; string[i] != '\0'; i++){
        for(int j=0; string[j] != '\0'; j++){
            if(string[i] == 'b'){
                string[i] = NULL; // Exclue b
            }
            if(string[i] == 'a'){
                string[i] = 'd';
                if(string[i+1] == NULL){
                    string[i+1] = 'd';
                } else {
                    while(string[j] != '\0'){
                        trocar(string[j], string[j+1]);
                    }
                }
            }
        }
    }
}

void main(){
    char string[100];

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    fflush(stdin);

    regras(string);

    for(int i=0; string[i] != '\0'; i++){
        printf("%c,", string[i]);
    }
}