#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);

    FILE *file;
    file = fopen(arquivo, "w");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    fprintf(file, "%s,", cpf);
    fclose(file);

    file = fopen(arquivo, "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    fprintf(file, "%s,", nome);
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    fprintf(file, "%s,", sobrenome);
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    fprintf(file, "%s", cargo);
    fclose(file);

    return 1;
}

int consulta() {
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 0;
    }

    while (fgets(conteudo, 200, file) != NULL) {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    fclose(file);
    return 1;
}

void deletar() {
    char cpf[40];
    char arquivo[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);

    if (remove(arquivo) == 0) {
        printf("Arquivo deletado com sucesso.\n");
    } else {
        printf("Não foi possível deletar o arquivo.\n");
    }

    system("pause");
}

int main() {
    int opcao = 0;
    int laco = 1;

    while (laco == 1) {
        system("cls");
        setlocale(LC_ALL, "Portuguese");

        printf("### Junção de Nomes da EBAC ###\n\n");
        printf("Escolha a opção desejada no menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Opção: ");

        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                printf("Você escolheu registrar nomes!\n");
                registro();
                break;

            case 2:
                printf("Você resolveu consultar nomes\n");
                consulta();
                break;

            case 3:
                deletar();
                break;

            default:
                printf("Essa opção não está disponível\n");
                break;
        }
    }

    return 0;
}



	
	

