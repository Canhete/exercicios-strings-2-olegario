/* Cada dígito, além de 0 e 1, em um teclado de telefone corresponde a uma das três ou quatro
letras do alfabeto, como mostrado na figura abaixo. Como as palavras são mais fáceis de
lembrar do que os números, é natural perguntar se um número de telefone de 7 ou 10 dígitos
pode ser representado por uma palavra. Por exemplo, "2276696" corresponde a "ACRONYM" e
também "ABPOMZN".

Escreva um programa que tome como entrada um número de telefone, especificado como uma
sequência de dígitos, e retorna todas as possíveis sequências de caracteres que correspondem
ao número de telefone. O teclado do celular é especificado por um mapeamento que pega um
dígito e retorna o conjunto correspondente de caracteres. As sequências de caracteres não
precisam ser palavras ou frases corretas. */

/* 2 = A
    22 = B
    222 = C
    9999 = Z
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char *map[] = {
    "",
    "",
    "ABC",
    "DEF",
    "GHI",
    "JKL",
    "MNO",
    "PQRS",
    "TUV",
    "WXYZ"
};

void menomico(char *tel, int pos, char *letras){
    if(tel[pos] == '\0'){
        printf("%s\n", letras);
        return;
    }

    int num = tel[pos] - '0';
    const char *mapa = map[num];

    for(int i = 0; mapa[i] != '\0'; i++){
        letras[pos] = mapa[i];
        menomico(tel, pos+1, letras);
    }
}

void main(){
    char tel[100];

    printf("Digite um número de telefone: ");
    fgets(tel, sizeof(tel), stdin);

    size_t len = strlen(tel);
    if(len > 0 && tel[len - 1] == '\n'){
        tel[len - 1] = '\0';
        len--;
    }

    char resultado[100];

    printf("Combinações possíveis:\n");
    menomico(tel, 0, resultado);
}