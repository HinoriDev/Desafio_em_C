#include <stdio.h>
int main(){

    char cpf[12];
    int numeros[11];
    int dv1, dv2, resto, soma;

    printf("Digite o CPF: ");
    scanf("%s", cpf);

        // Converter caracteres para inteiros
    for (int cont = 0; cont < 11; cont++) {
        numeros[cont] = cpf[cont] - '0';
    }

    
    // Verificar se todos os dígitos são iguais
    int iguais = 1;
    for (int cont = 1; cont < 11; cont++) {
        if (numeros[cont] != numeros[0]) {
            iguais = 0;
            break;
        }
    }
    if (iguais) {
        printf("CPF INVÁLIDO\n");
        return 0;
    }

    // Calcular DV1
    soma = 0;
    for (int cont = 0, peso = 10; cont < 9; cont++, peso--) {
        soma += numeros[cont] * peso;
    }
    resto = soma % 11;
    dv1 = (resto < 2) ? 0 : 11 - resto;

    // Calcular DV2
    soma = 0;
    for (int cont = 0, peso = 11; cont < 10; cont++, peso--) {
        soma += numeros[cont] * peso;
    }
    resto = soma % 11;
    dv2 = (resto < 2) ? 0 : 11 - resto;

    // Verificar se os dois DV estão corretos
    if (dv1 == numeros[9] && dv2 == numeros[10])
        printf("CPF VÁLIDO\n");
    else
        printf("CPF INVÁLIDO\n");

    return 0;
}