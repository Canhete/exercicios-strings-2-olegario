/*3. Calcule a codificação da coluna da planilha
As planilhas geralmente usam uma codificação alfabética das colunas sucessivas.
Especificamente, as colunas são identificadas por "A", "B", "С",..., "X", "Y", "Z", " АА", “АB”,....,
"ZZ", "AAA", "AAB",.... Implemente uma função que converta um id de coluna de planilha para o
inteiro correspondente, com "A" correspondente a 1. Por exemplo, você deve retornar 4 para
"D", 27 para "AA", 702 para "ZZ", etc. Como você testaria seu código? Dica: Existem 26
caracteres em ["'A", "Z"], e cada um pode ser mapeado para um inteiro.*/

#include <stdio.h>
#include <stdio.h>
#include <ctype.h>

int converterAlfabeto(char *string){
    int res = 0;
    for(int i=0; string[i]!='\0'; i++){
        char c = toupper(string[i]);
        if(c<'A' || c>'Z'){ // Ignora caracteres diferentes de A a Z
            continue;
        }
        int valor = c - 'A' + 1;
        res = res * 26 + valor;
    }
    return res;
}

void main(){
    char string[100];

    printf("Digite uma string com letras: ");
    fgets(string, sizeof(string), stdin);

    fflush(stdin);

    int resultado = converterAlfabeto(string);

    printf("%s = %d\n", string, resultado);
}