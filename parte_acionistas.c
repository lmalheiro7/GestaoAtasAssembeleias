//
//  parte_acionistas.c
//  Gestão de atas
//
//  Created by Luis Malheiro on 21/05/2021.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parte_acionistas.h"
#include "parte_admins.h"


char *pop(char STACK[][20], int *contador, char assinatura_acionista[]){
    char aux[20]={'\0'};
    if ((*contador)<=0) {
        printf("Stack cheia.\n");
    }
    else{
        strcpy(aux, STACK[(*contador)-1]);
        (*contador)--;
    }
    return aux;
}

void push(char STACK[][20], char assinatura_acionista[], int *contador){
    if ((*contador) >= NUMERO_MAXIMO_ASSINATURAS) {
        printf("Stack cheia.\n");
        return;
    }
    strcpy(STACK[*contador], assinatura_acionista);
    (*contador)++;
}
/*
int stack_vazia(STACK* auxiliar){
    printf("%d", auxiliar->tamanho);
    return (auxiliar->tamanho == 0);
}

int tamanho(STACK* auxiliar){
    return (auxiliar->tamanho);
}

char topo(STACK* auxiliar){
    if (stack_vazia(auxiliar)) {
        return -1;
    }
    return(auxiliar->topo->info.acionistas_presentes);
}
STACK* criar_stack(){
    STACK* stack = (STACK*) malloc(sizeof(STACK));
    stack->tamanho = 0;
    stack->topo = NULL;
    return stack;
}

void push (STACK* stack, INFO_ATA info){
    NO_STACK* no_stack = (NO_STACK*) malloc(sizeof(NO_STACK));
    no_stack->info = info;
    no_stack->proximo = stack->topo;
    stack->topo = no_stack;
    stack->tamanho++;
}

void escrever_pilha(STACK* auxiliar){
    if (stack_vazia(auxiliar)) {
        printf("Stack vazia.\n");
        return;
    }
    NO_STACK* ponteiro = auxiliar->topo;
    printf("\n[");
    while (ponteiro != NULL) {
        printf("%s", ponteiro->info.acionistas_presentes);
        ponteiro = ponteiro->proximo;
    }
    printf("]");
}

void eliminar_elemento(STACK* auxiliar){
    if (!stack_vazia(auxiliar)) {
        NO_STACK* ponteiro = auxiliar->topo;
        auxiliar->topo = ponteiro->proximo;
        free(ponteiro);
        auxiliar->tamanho--;
    }
}
int saber_indice_pos(STACK* auxiliar, NO_STACK* auxiliar_no){
    if (auxiliar_no != NULL) {
        NO_STACK* ponteiro = auxiliar->topo;
        int indice_pos=0;
        while (ponteiro != auxiliar_no && ponteiro != NULL) {
            ponteiro = ponteiro->proximo;
            indice_pos++;
        }
        if (ponteiro != NULL) {
            return indice_pos;
        }
    }
    printf("Nó não pertence à stack.\n");
    return -1;
}

NO_STACK* andarPosicoes(STACK* auxiliar, int indice_pos){
    int i=0;
    if (indice_pos >= 0 && indice_pos < auxiliar->tamanho) {
        NO_STACK* no_stack = auxiliar->topo;
        for (i=0; i<indice_pos; i++) {
            no_stack = no_stack->proximo;
        }
        return no_stack;
    }
    printf("Indíce inválido.\n");
    return 0;
}

//-----------------------
void pesquisa_de_ata(INFO_ATA *ata){
    char nome[100];
    system("cls");

    FILE *fpr;
    fpr = fopen("/Users/lmalheiro/Documents/Gestão de atas/utilizadores.txt","r");

    if(fpr==NULL){
        printf("Nao existem dados gravados");
    }

    printf("Insira o nome que deseja pesquisar: ");
    fflush(stdin);
    gets(nome);

    
    while(fscanf(fpr,"%[^;];%[^;];%[^;];%hi",&ata->data_ata, &ata->titulo_ata, &ata->local_ata, &ata->texto_ata, &ata->acionistas_presentes, &ata->estado_ata) != EOF )  {
        printf("%s;%s;%s;%s;%s;&i", ata->data_ata, ata->titulo_ata, ata->local_ata, ata->texto_ata, ata->acionistas_presentes, ata->estado_ata);
        fflush(stdin);
        gets(ata->info_ata);
    }
    printf("Inserção com sucesso.\n");
    fclose(fpr);
}

int menu_ver_atas(){
    STACK* stack = criar_stack();
    INFO_ATA info_ata;
    NO_STACK* auxiliar;
    int opcao, vazio;
    
    do{
        printf("****************CONSULTA DE ASSINATURAS*****************\n");
        printf("*1 - Verificar se não tem assinaturas(stack vazia)     *\n");
        printf("*2 - Mostrar o tamanho da stack                        *\n");
        printf("*3 - Mostrar o topo da stack                           *\n");
        printf("*4 - Adicionar um elemento da stack                    *\n");
        printf("*5 - Retirar um elemento da pilha                      *\n");
        printf("*6 - Imprimir a stack completa                         *\n");
        printf("*7 -  Sair                                             *\n");
        printf("********************************************************\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                vazio = stack_vazia(stack);
                if (vazio == 0) {
                    printf("A stack não está vazia.\n");
                }
                else{
                    printf("A stack está vazia.\n");
                }
                break;
            case 2:
                printf("O tamanho da stack é %d. \n", tamanho(stack));
                break;
            case 3:
                if (topo(stack) != -1) {
                    printf("%d \n", topo(stack));
                }
                else{
                    printf("A stack está vazia logo não existe topo.\n");
                }
                break;
            case 4:
                pesquisa_de_ata(&info_ata);
                break;
            case 5:
                if (stack_vazia(stack)) {
                    printf("A stack já se encontra vazia.\n");
                }
                else{
                    eliminar_elemento(stack);
                    printf("O topo da stack foi removido.\n");
                }
                break;
            case 6:
                printf("\n");
                escrever_pilha(stack);
                printf("\n");
            case 7:
                break;
            default:
                printf("Opção Inválida.\n");
                break;
        }
        
    }while (opcao != 7);
    return 0;
}
*/
//-----------------------------------------------------------
char pesquisa_user(INFO_USER *user){
    int tipo = 0;
    system("cls");

    FILE *fpr;
    fpr = fopen("/Users/lmalheiro/Documents/Gestão de atas/utilizadores.txt","r");

    if(fpr==NULL){
        printf("Nao existem dados gravados");
    }

    tipo = 2;

    printf("------ ACIONISTAS ------- \n");
    while(fscanf(fpr,"%[^;];%[^;];%[^;];%hi",&user->nome, &user->username, &user->password, &user->tipo) != EOF )  {
        if (user->tipo == tipo) {
            printf("Nome: %s\n", user->nome);
            printf("Username: %s\n", user->username);
            printf("Password: %s\n", user->password);
            printf("Tipo: %i\n", user->tipo);
            printf("--------------------------\n");
        }
    }
    fclose(fpr);
    return menu_acionista();
}

char pesquisar_acionista_por_nome(INFO_USER *user){
    char nome[100];
    system("cls");

    FILE *fpr;
    fpr = fopen("/Users/lmalheiro/Documents/Gestão de atas/acionistas.txt","r");

    if(fpr==NULL){
        printf("Nao existem dados gravados");
    }

    printf("Insira o nome que deseja pesquisar: ");
    fflush(stdin);
    gets(nome);
    
    while(fscanf(fpr,"%[^;];%[^;];%[^;];%hi",&user->nome, &user->username, &user->password, &user->tipo) != EOF )  {
        if (strcmp(user->nome, nome) == 0) {
            printf("------ PESQUISA DE UTILIZADORES ------- \n");
            printf("Nome: %s\n", user->nome);
            printf("Username: %s\n", user->username);
            printf("Password: %s\n", user->password);
            printf("Tipo: %i\n", user->tipo);
            printf("--------------------------\n");
        }
    }
    fclose(fpr);
    return menu_acionista();
}

int menu_acionista(){
    USER_ELEM *inicio_lista_acionistas = NULL;
    ATA_ELEM *inicio_lista_atas = NULL;
    INFO_USER info_user;
    
    char nome[TAM_NOME], nome_perfil[TAM_NOME], user[TAM_USER], password[TAM_PASS];
    int opcao=0;

  printf("************************ MENU ACIONISTA ************************\n");
  printf("*\t1 - Listar todos os acionistas                              *\n");
  printf("*\t2 - Procurar acionista por nome                             *\n");
  printf("*\t3 - Ver atas que tem para assinar                           *\n");
  printf("*\t0 - SAIR DO PROGRAMA                                        *\n");
  printf("***************************************************************\n");
  scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            pesquisa_user(&info_user);
            break;
        case 2:
            pesquisar_acionista_por_nome(&inicio_lista_acionistas);
            break;
        case 3:
            
        case 0:
            printf("Voltando atrás.\n");
            break;
        default:
            printf("Opção Inválida.\n");
            break;
    }while (opcao != 0) {
        break;
    }
    return 0;
}
