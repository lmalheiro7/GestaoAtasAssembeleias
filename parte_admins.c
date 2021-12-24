//
//  parte_admins.c
//  Gestão de atas
//
//  Created by Luis Malheiro on 20/05/2021.
//
#include "parte_admins.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int escrever_binarios_atas(ATA_ELEM *inicio_lista, int numero_ata){
    ATA_ELEM *auxiliar = NULL;
    FILE *fp = NULL;
    fp = fopen("/Users/lmalheiro/Documents/Gestão de atas/atas.dat", "ab");
    if(fp == NULL){
      puts("Erro ao abrir ficheiro\n");
      return -1;
    }
    fwrite(&numero_ata, 1, sizeof(int), fp);
    for (auxiliar = inicio_lista; auxiliar != NULL; auxiliar = auxiliar->seguinte) {
        fwrite(&(auxiliar->info), 1, sizeof(auxiliar->info), fp);
    }
    fclose(fp);
    return 0;
}

int escrever_txt_atas(ATA_ELEM *inicio_lista, int numero_ata){
    ATA_ELEM *auxiliar = NULL;
    FILE *fp = NULL;
    fp = fopen("/Users/lmalheiro/Documents/Gestão de atas/atas.txt", "w");
    if(fp == NULL){
      puts("Erro ao abrir ficheiro\n");
      return -1;
    }
    for (auxiliar = inicio_lista; auxiliar != NULL; auxiliar = auxiliar->seguinte) {
        fprintf(fp, "%s;%s;%s;%s;%s;%i", auxiliar->info.data_ata, auxiliar->info.titulo_ata, auxiliar->info.local_ata, auxiliar->info.texto_ata, auxiliar->info.acionistas_presentes, auxiliar->info.estado_ata);
    }
    fclose(fp);
    return 0;
}

int escrever_binarios_atas_local(ATA_ELEM *inicio_lista, int numero_ata){
    ATA_ELEM *auxiliar = NULL;
    FILE *fp = NULL;
    fp = fopen("atas.txt", "wb+");
    if(fp == NULL){
      puts("Erro ao abrir ficheiro\n");
      return -1;
    }
    fwrite(&numero_ata, 1, sizeof(int), fp);
    for (auxiliar = inicio_lista; auxiliar != NULL; auxiliar = auxiliar->seguinte) {
        fwrite(&(auxiliar->info.local_ata), 1, sizeof(auxiliar->info.local_ata), fp);
    }
    fclose(fp);
    return 0;
}

int escrever_binarios_titulo(ATA_ELEM *inicio_lista, int numero_ata){
    ATA_ELEM *auxiliar = NULL;
    FILE *fp = NULL;
    fp = fopen("atas.txt", "wb+");
    if(fp == NULL){
      puts("Erro ao abrir ficheiro\n");
      return -1;
    }
    fwrite(&numero_ata, 1, sizeof(int), fp);
    for (auxiliar = inicio_lista; auxiliar != NULL; auxiliar = auxiliar->seguinte) {
        fwrite(&(auxiliar->info.titulo_ata), 1, sizeof(auxiliar->info.titulo_ata), fp);
    }
    fclose(fp);
    return 0;
}

int validar_ata(INFO_ATA *ata)
{
    if(ata->estado_ata != 0) return 0;
    return 1;
}

void escapeN(char string[]){
  int temp = strlen(string)-1;
  if(string[temp] == '\n')
    string[temp] = '\0';
}

ATA_ELEM *obter_no_anterior_lista(ATA_ELEM *inicio_lista, ATA_ELEM *nodo){
    if (inicio_lista == nodo) {
        return NULL;
    }
    ATA_ELEM *auxiliar = NULL;
    ATA_ELEM *anterior = inicio_lista;
    for (auxiliar = inicio_lista->seguinte; auxiliar != NULL; auxiliar = auxiliar->seguinte) {
        if (auxiliar == nodo) {
            return anterior;
        }
        anterior = auxiliar;
    }
    return NULL;
}
void trocar_nos_atas(ATA_ELEM **inicio_lista, ATA_ELEM **nodo1, ATA_ELEM **nodo2){
    if ((*inicio_lista) == NULL || (*nodo1) == NULL || (*nodo2) == NULL) {
        return;
    }
    ATA_ELEM* a = obter_no_anterior_lista(*inicio_lista, *nodo1);
    ATA_ELEM* b = obter_no_anterior_lista(*inicio_lista, *nodo2);
    
    if(a) a->seguinte = (*nodo2);
    if(b) b->seguinte = (*nodo1);
    
    ATA_ELEM* ponteiro = NULL;
    ponteiro = (*nodo1)->seguinte;
    (*nodo1)->seguinte = (*nodo2)->seguinte;
    (*nodo2)->seguinte = ponteiro;
    if((*inicio_lista)==(*nodo1))
       *inicio_lista = *nodo2;
    else
       if((*inicio_lista)==(*nodo2))
          *inicio_lista = *nodo1;
}
int existe_ata(ATA_ELEM *inicio_lista, char data_ata[]){
  ATA_ELEM *auxiliar = NULL;

  for(auxiliar = inicio_lista; auxiliar != NULL; auxiliar = auxiliar->seguinte){
    if(strcmp(auxiliar->info.data_ata,data_ata)==0){
      return 1;
    }
  }
  return 0;
}

void listar_atas(ATA_ELEM *inicio_lista){
    ATA_ELEM *auxiliar = NULL;
    auxiliar = inicio_lista;
    if (auxiliar == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    printf("ATAS: \n\n");
    for (auxiliar = inicio_lista; auxiliar != NULL; auxiliar = auxiliar->seguinte) {
        printf("*\tData da ata: %s\n", auxiliar->info.data_ata);
        printf("*\tTitulo da ata: %s\n", auxiliar->info.titulo_ata);
        printf("*\tLocal da ata: %s\n", auxiliar->info.local_ata);
        printf("*\tTexto da ata: %s\n", auxiliar->info.texto_ata);
        printf("*\tAcionistas presentes: %s\n", auxiliar->info.acionistas_presentes);
        printf("*\tEstado da ata: %i\n", auxiliar->info.estado_ata);
        printf("***********************************************\n");
    }
}

int alterar_local_ata(ATA_ELEM *inicio_lista, char titulo_ata[]){
    ATA_ELEM *auxiliar = NULL;
    for(auxiliar = inicio_lista; auxiliar != NULL; auxiliar = auxiliar->seguinte){
      if(strcmp(titulo_ata, auxiliar->info.titulo_ata) == 0){
        printf("Introduza o novo local: ");
        rewind(stdin);
        fgets(auxiliar->info.local_ata,TAM_LOCAL_ATA,stdin);
        return 0;
      }
    }
    printf("ERRO! Não existe ata.\n");
    return 0;
}

int alterar_texto_ata(ATA_ELEM *inicio_lista, char titulo_ata[]){
    ATA_ELEM *auxiliar = NULL;
    for(auxiliar = inicio_lista; auxiliar != NULL; auxiliar = auxiliar->seguinte){
      if(strcmp(titulo_ata, auxiliar->info.titulo_ata) == 0){
        printf("Introduza o novo texto: ");
        rewind(stdin);
        fgets(auxiliar->info.texto_ata,TAM_TEXTO_ATA,stdin);
        return 0;
      }
    }
    printf("ERRO! Não existe ata.\n");
    return 0;
}

int altera_estado_ata(ATA_ELEM *inicio_lista, char titulo_ata[]){
    ATA_ELEM *auxiliar = NULL;
    for (auxiliar = inicio_lista; auxiliar != NULL; auxiliar = auxiliar->seguinte) {
        if (strcmp(titulo_ata, auxiliar->info.titulo_ata) == 0) {
            printf("\nIntroduza um novo estado(1 - Em redação)(2 - Para assinatura)(3 - Concluido): \n");
            scanf("%i", &auxiliar->info.estado_ata);
            return 0;
        }
    }
    printf("Ata não encontrada.\n");
    return 0;
}

void listar_atas_decrescente(ATA_ELEM **inicio_lista){
    ATA_ELEM *auxiliar1 = NULL;
    ATA_ELEM *auxiliar2 = NULL;
    ATA_ELEM *maior = NULL;
    INFO_ATA troca;
    
    if (inicio_lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    for (auxiliar1 = *inicio_lista; auxiliar1 != NULL; auxiliar1 = auxiliar1->seguinte) {
        maior = auxiliar1;
        for (auxiliar2 = auxiliar1; auxiliar2 != NULL; auxiliar2 = auxiliar2->seguinte) {
            if (auxiliar2->info.data_ata > maior->info.data_ata) {
                maior = auxiliar2;
            }
        }
        if (maior != auxiliar1) {
            trocar_nos_atas(inicio_lista, &auxiliar1, &maior);
            auxiliar1 = maior;
        }
    }
}
void listar_atas_estado(ATA_ELEM **inicio_lista){
    ATA_ELEM *auxiliar1 = NULL;
    ATA_ELEM *auxiliar2 = NULL;
    ATA_ELEM *maior = NULL;
    INFO_ATA troca;
    
    if (inicio_lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    for (auxiliar1 = *inicio_lista; auxiliar1 != NULL; auxiliar1 = auxiliar1->seguinte) {
        maior = auxiliar1;
        for (auxiliar2 = auxiliar1; auxiliar2 != NULL; auxiliar2 = auxiliar2->seguinte) {
            if (auxiliar2->info.estado_ata > maior->info.estado_ata) {
                maior = auxiliar2;
            }
        }
        if (maior != auxiliar1) {
            trocar_nos_atas(inicio_lista, &auxiliar1, &maior);
            auxiliar1 = maior;
        }
    }
}
void listar_atas_por_local(ATA_ELEM *inicio_lista, char local_ata[]){
  ATA_ELEM *auxiliar = NULL;
  auxiliar = inicio_lista;

  if(auxiliar == NULL){
    printf("Lista vazia\n");
    return;
  }

  while(auxiliar != NULL && strcmp(auxiliar->info.local_ata, local_ata) != 0){
    auxiliar = auxiliar->seguinte;
  }

  if(auxiliar == NULL){
    printf("ERRO. Neste local não existiram atas.\n");
    return;
  }
  for(auxiliar = inicio_lista; auxiliar != NULL; auxiliar = auxiliar->seguinte){
    if(strcmp(auxiliar->info.local_ata, local_ata) == 0){
        printf("*\tData da ata: %s\n", auxiliar->info.data_ata);
        printf("*\tTitulo da ata: %s\n", auxiliar->info.titulo_ata);
        printf("*\tLocal da ata: %s\n", auxiliar->info.local_ata);
        printf("*\tTexto da ata: %s\n", auxiliar->info.texto_ata);
        printf("*\tAcionistas presentes: %s\n", auxiliar->info.acionistas_presentes);
        printf("*\tEstado da ata: %i\n", auxiliar->info.estado_ata);
        printf("***********************************************\n");
        printf("\n");
    }
  }
}
void listar_atas_para_assinar(ATA_ELEM *inicio_lista){
  ATA_ELEM *auxiliar = NULL;
  auxiliar = inicio_lista;

  if(auxiliar == NULL){
    printf("Lista vazia\n");
    return;
  }

  while(auxiliar != NULL && auxiliar->info.estado_ata != 2){
    auxiliar = auxiliar->seguinte;
  }

  if(auxiliar == NULL){
    printf("ERRO. Neste local não existiram atas.\n");
    return;
  }

  for(auxiliar = inicio_lista; auxiliar != NULL; auxiliar = auxiliar->seguinte){
    if(auxiliar->info.estado_ata == 2){
        printf("*\tData da ata: %s\n", auxiliar->info.data_ata);
        printf("*\tTitulo da ata: %s\n", auxiliar->info.titulo_ata);
        printf("*\tLocal da ata: %s\n", auxiliar->info.local_ata);
        printf("*\tTexto da ata: %s\n", auxiliar->info.texto_ata);
        printf("*\tAcionistas presentes: %s\n", auxiliar->info.acionistas_presentes);
        printf("*\tEstado da ata: %i\n", auxiliar->info.estado_ata);
        printf("***********************************************\n");
        printf("\n");
    }
  }
}

void listar_atas_concluidas(ATA_ELEM *inicio_lista){
  ATA_ELEM *auxiliar = NULL;
  auxiliar = inicio_lista;

  if(auxiliar == NULL){
    printf("Lista vazia\n");
    return;
  }

  while(auxiliar != NULL && auxiliar->info.estado_ata != 3){
    auxiliar = auxiliar->seguinte;
  }

  if(auxiliar == NULL){
    printf("ERRO. Neste local não existiram atas.\n");
    return;
  }

  for(auxiliar = inicio_lista; auxiliar != NULL; auxiliar = auxiliar->seguinte){
    if(auxiliar->info.estado_ata == 3){
        printf("*\tData da ata: %s\n", auxiliar->info.data_ata);
        printf("*\tTitulo da ata: %s\n", auxiliar->info.titulo_ata);
        printf("*\tLocal da ata: %s\n", auxiliar->info.local_ata);
        printf("*\tTexto da ata: %s\n", auxiliar->info.texto_ata);
        printf("*\tAcionistas presentes: %s\n", auxiliar->info.acionistas_presentes);
        printf("*\tEstado da ata: %i\n", auxiliar->info.estado_ata);
        printf("***********************************************\n");
        printf("\n");
    }
  }
}

int validar_utilizador(INFO_USER *user)
{
    if(user->tipo != NULL) return 0;
    return 1;
}

int inserir_lista_ligada_inicio(USER_ELEM **apt_l, INFO_USER *apt_info, int (*validar)(INFO_USER *))
{
    //PROF
    USER_ELEM *novo;

    if(apt_info==NULL) return -1;

    if(validar!=NULL && (*validar)(apt_info)==0) return -1;

    novo = (USER_ELEM *)malloc(sizeof(USER_ELEM));
    if (novo==NULL) return -1;

    novo->info = *apt_info;
    novo->seguinte = *apt_l;
    *apt_l = novo;
    return 1;
}

void inserir_utilizador(INFO_USER *user){
    FILE *fp, *fp1 = NULL;
    fp = fopen("/Users/lmalheiro/Documents/Gestão de atas/utilizadores.txt", "a+");
    fp1 = fopen("/Users/lmalheiro/Documents/Gestão de atas/acionistas.txt", "a+");
    if (fp == NULL) {
        printf("ERRO ao abrir o ficheiro.\n");
        return;
    }
    printf("--------------------\n");
    printf("Nome? \n");
    scanf("%s",user->nome);
    printf("Username? \n");
    scanf("%s",user->username);
    printf("Password? \n");
    scanf("%s",user->password);
    printf("Tipo? (1 - Admin) (2 - Acionista) \n");
    scanf("%hi",&(user->tipo));
    printf("--------------------\n");
    if (user->tipo == 2) {
        fprintf(fp1, "%s;%s;%s;%i \n", user->nome, user->username, user->password, user->tipo);
    }
    fprintf(fp, "%s;%s;%s;%i \n", user->nome, user->username, user->password, user->tipo);
    fclose(fp);
    fclose(fp1);
    return;
}
void editar_utilizador(INFO_USER *user){
    char nome[100];
    char username[100];
    int existe = 0;
    char tecla;

    system("cls");

    FILE *fpr,*fpr1, *fpr2;//file pointer's
    fpr1 = fopen("/Users/lmalheiro/Documents/Gestão de atas/usersFicheiroTemporario.txt","w+");
    fpr = fopen("/Users/lmalheiro/Documents/Gestão de atas/utilizadores.txt","r");
    fpr2 = fopen("/Users/lmalheiro/Documents/Gestão de atas/acionistas.txt","r");
    if(fpr==NULL){
        printf("Nao existem dados gravados");
    }

    printf("Insira o nome que deseja editar: ");
    fflush(stdin);
    gets(nome);


    if(fpr1==NULL){

        printf("\n Ficheiro não pode ser aberto");
    }

    while(fscanf(fpr,"%[^;];%[^;];%[^;];%hi",&user->nome, &user->username, &user->password, &user->tipo) != EOF )

    {
        if(strcmp(user->nome,nome) == 0)
            {
                printf("%s;%s;%s;%i\n", user->nome, user->username, user->password, user->tipo);
                existe = 1;
                printf("Introduza o novo nome: \n");
                fflush(stdin);
                fgets(user->nome, TAM_NOME, stdin);
                escapeN(user->nome);
                printf("Introduza o novo username: \n");
                fflush(stdin);
                fgets(user->username, TAM_USER, stdin);
                escapeN(user->username);
                printf("Introduza a nova password: \n");
                fflush(stdin);
                fgets(user->password, TAM_PASS, stdin);
                escapeN(user->password);
                printf("Introduza o tipo (1 - Admin) (2 - Acionista): \n");
                scanf("%hi", &user->tipo);

                printf("\n Pressione a tecla 's' para fazer update do username : \n");
                fflush(stdin);
                fgets(&tecla, 1, stdin);
                tecla = getchar();

                if(tecla == 's' || tecla == 'S')
                    {
                        fprintf(fpr1, "%s;%s;%s;%i", user->nome, user->username, user->password, user->tipo);
                        printf("Username atualizado com sucesso.\n");
                        if (user->tipo == 2) {
                            fprintf(fpr2, "%s;%s;%s;%i", user->nome, user->username, user->password, user->tipo);
                        }
                    }
            }
    }
    if(!existe) printf("\n\tERRO, não existe nenhum utilizador com tais credenciais.\n");

    fclose(fpr1);
    fclose(fpr);
    fclose(fpr2);
    remove("/Users/lmalheiro/Documents/Gestão de atas/utilizadores.txt");
    rename("/Users/lmalheiro/Documents/Gestão de atas/usersFicheiroTemporario.txt","/Users/lmalheiro/Documents/Gestão de atas/utilizadores.txt");
    
}

void apagar_utilizador(INFO_USER *user){
    char nome[100];
    char username[100];
    int existe = 0;
    char tecla;

    system("cls");

    FILE *fpr,*fpr1;//file pointer's
    fpr1 = fopen("/Users/lmalheiro/Documents/Gestão de atas/usersFicheiroTemporario.txt","w+");
    fpr = fopen("/Users/lmalheiro/Documents/Gestão de atas/utilizadores.txt","r");

    if(fpr==NULL){
        printf("Nao existem dados gravados");
    }

    printf("Insira o nome que deseja editar: ");
    fflush(stdin);
    gets(nome);

    if(fpr1==NULL){

        printf("\n Ficheiro não pode ser aberto");
    }
    
    while(fscanf(fpr,"%[^;];%[^;];%[^;];%hi",&user->nome, &user->username, &user->password, &user->tipo) != EOF )  {
        if (strcmp(user->nome, nome) == 0) {
            printf("%s;%s;%s;%i\n", user->nome, user->username, user->password, user->tipo);
            printf("Tem a certeza que deseja apagar?[S/N]");
            fflush(stdin);
            fgets(&tecla, 1, stdin);
            tecla = getchar();
            if (tecla == 's' || tecla == 'S') {
                existe = 1;
                printf("Utilizador apagado com sucesso.\n");
            }
            else if (tecla == 'n' || tecla == 'N'){
                break;
            }
            else{
                break;
            }
        }
        else{
            fprintf(fpr1, "%s;%s;%s;%i\n", user->nome, user->username, user->password, user->tipo);
        }
    }
    if (existe == 0) {
        printf("\n\t Username não encontrado.\n");
    }
    else{
        fclose(fpr);
        fclose(fpr1);
        remove("/Users/lmalheiro/Documents/Gestão de atas/utilizadores.txt");
        rename("/Users/lmalheiro/Documents/Gestão de atas/usersFicheiroTemporario.txt", "/Users/lmalheiro/Documents/Gestão de atas/utilizadores.txt");
    }
}

void pesquisar_utilizador(INFO_USER *user){
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

    
    while(fscanf(fpr,"%[^;];%[^;];%[^;];%hi",&user->nome, &user->username, &user->password, &user->tipo) != EOF )  {
        if (strcmp(user->nome, nome) == 0) {
            printf("--------------------------\n");
            printf("------ PESQUISA DE UTILIZADORES ------- \n");
            printf("Nome: %s\n", user->nome);
            printf("Username: %s\n", user->username);
            printf("Password: %s\n", user->password);
            printf("Tipo: %i\n", user->tipo);
            printf("--------------------------\n");
        }
    }
    fclose(fpr);
}

void pesquisar_atas(INFO_ATA *atas){
    char local[TAM_LOCAL_ATA];
    int data_ata[TAM_DATA_ATA];

    FILE *fp=NULL;
    fp = fopen("atas.dat", "r");
    
    printf("Introduza a data da ata: \n");
    scanf("%i", &data_ata);
    printf("\nIntroduza o local da ata: ");
    fflush(stdin);
    gets(local);
    
    while (fscanf(fp, "%i:[^;]:[^;]:[^;]:%i", &atas->data_ata, &atas->local_ata, &atas->texto_ata, &atas->acionistas_presentes, &atas->estado_ata)!= EOF) {
        
        if(strcmp(atas->data_ata, data_ata) && strcmp(atas->local_ata, local) == 0){
            printf("Data da ata: %i\nLocal da ata: %c\nTexto da ata: %c\nAcionistas presentes: %c\nEstado da ata: %i\n", atas->data_ata, atas->local_ata, atas->texto_ata, atas->acionistas_presentes, atas->estado_ata);
        }
        if(strcmp(atas->data_ata, data_ata) != 0 || strcmp(atas->local_ata, local) != 0){
            printf("\n\tAta não encontrado");
            pesquisar_atas(atas);
        }
    }
    fclose(fp);
}
/*
 ---------- ---------- ---------- ---------- ---------- ---------- ----------
 */

int inserir_atas_lista(ATA_ELEM **inicio_lista, INFO_ATA newInfo){

  ATA_ELEM *novo = NULL;
  ATA_ELEM *auxiliar = NULL;
  novo = (ATA_ELEM*)malloc(sizeof(ATA_ELEM));

  if(novo == NULL){
    printf("Erro ao alocar memoria\n");
    return -1;
  }

  newInfo.estado_info = 0;
  novo -> info = newInfo;
  novo -> seguinte = NULL;

  if(*inicio_lista == NULL){
    (*inicio_lista) = novo;
  }else{
    auxiliar = *inicio_lista;
    while (auxiliar->seguinte != NULL) {
      auxiliar = auxiliar->seguinte;
    }
    auxiliar->seguinte = novo;
  }

  return 0;
}

int ler_binario_atas(ATA_ELEM **inicio_lista_atas){
  ATA_ELEM *auxilair = NULL;
  FILE *fp = NULL;
  INFO_ATA info;
  fp = fopen("/Users/lmalheiro/Documents/Gestão de atas/atas.dat", "rb");

  if(fp == NULL){
    puts("De momento ainda não foram criadas atas. (Nesta secção poderá consultar atas já criadas)\n");
    return -1;
  }
  while(fread(&info,sizeof(info),1,fp)>0){
      inserir_atas_lista(inicio_lista_atas, info);
  }
  fclose(fp);
  return 0;
}

int menu_admin(){
    INFO_ATA auxiliar;
    ATA_ELEM *inicio_lista_atas = NULL;
    USER_ELEM *inicio_lista_user = NULL;
    INFO_USER info_user;
    INFO_ATA info_ata;
    int estad_ata, resultado, numero_ata = 0;
    char text_ata[TAM_TEXTO_ATA], local_ata[TAM_LOCAL_ATA], data_ata[TAM_DATA_ATA], titulo_ata[TAM_TITULO_ATA];
    int opcao=0, acionista_pres = 0, i, tam;
    do {
        printf("******************************* MENU ADMIN *******************************\n");
        printf("*\t1 - Acrescentar ou criar informacao da ata                            *\n");
        printf("*\t2 - Alterar local da ata                                              *\n");
        printf("*\t3 - Alterar texto da ata                                              *\n");
        printf("*\t4 - Alterar estado de uma ata                                         *\n");
        printf("*\t5 - Listar atas por data descrescente                                 *\n");
        printf("*\t6 - Listar atas por estado                                            *\n");
        printf("*\t7 - Listar atas de um local                                           *\n");
        printf("*\t8 - Listar atas assinadas por um acionista                            *\n"); //FAZER NO F
        printf("*\t9 - Listar atas que devem ser assinadas                               *\n");
        printf("*\t10 -  Listar atas concluidas                                          *\n");
        printf("*\t11 - Inserir novos utilizadores                                       *\n");
        printf("*\t12 - Editar utilizador                                                *\n");
        printf("*\t13 - Eliminar utilizador                                              *\n");
        printf("*\t14 - Pesquisar informacao sobre utilizador                            *\n");
        printf("*\t15 - Pesquisar uma ata                                                *\n");
        printf("*\t0 - Sair do programa                                                  *\n");
        printf("**************************************************************************\n");
        scanf("%d", &opcao);
   
    switch (opcao) {
        case 1:
            printf("\nINFORMACOES DAS ATAS\n");
            printf("Introduza a data da ata [AAAAMMDD]: \n");
            rewind(stdin);
            fgets(auxiliar.data_ata,TAM_DATA_ATA,stdin);
            escapeN(auxiliar.data_ata);
            if (existe_ata(inicio_lista_atas, auxiliar.data_ata) == 0){
              printf("Introduza o titulo da ata: \n");
              rewind(stdin);
              fgets(auxiliar.titulo_ata,TAM_LOCAL_ATA,stdin);
              escapeN(auxiliar.titulo_ata);
              printf("Introduza o local da ata: \n");
              rewind(stdin);
              fgets(auxiliar.local_ata,TAM_LOCAL_ATA,stdin);
              escapeN(auxiliar.local_ata);
              printf("Introduza o texto da ata: \n");
              rewind(stdin);
              fgets(auxiliar.texto_ata,TAM_TEXTO_ATA,stdin);
              escapeN(auxiliar.texto_ata);
              printf("Introduza os acionistas presentes: \n");
              rewind(stdin);
              fgets(auxiliar.acionistas_presentes,TAM_ACIONISTAS_PRESENTES,stdin);
              escapeN(auxiliar.acionistas_presentes);
              rewind(stdin);
              printf("Introduza o estado da ata (1 - em redação ) (2 - Para assinatura) (3 - Concluída): \n");
              rewind(stdin);
              scanf("%i", &auxiliar.estado_ata);
              printf("-----------------------------\n");
                info_ata.numero_ata = ++numero_ata;
                inserir_atas_lista(&inicio_lista_atas, auxiliar);
                escrever_binarios_atas(inicio_lista_atas, numero_ata);
                escrever_txt_atas(inicio_lista_atas, numero_ata);
                printf("Inserção com sucesso. \n");
            }
            else{
              printf("Ata já existe!\n");
            }
            break;
        case 2:
            listar_atas(inicio_lista_atas);
            printf("Introduza o titulo da ata que pretende alterar: \n");
            rewind(stdin);
            fgets(titulo_ata, TAM_TITULO_ATA, stdin);
            escapeN(titulo_ata);
            alterar_local_ata(inicio_lista_atas, titulo_ata);
            escrever_binarios_atas_local(inicio_lista_atas, numero_ata);
            break;
        case 3:
            listar_atas(inicio_lista_atas);
            printf("Introduza o titulo da ata que pretende alterar: \n");
            rewind(stdin);
            fgets(titulo_ata, TAM_TITULO_ATA, stdin);
            escapeN(titulo_ata);
            alterar_texto_ata(inicio_lista_atas, titulo_ata);
            escrever_binarios_titulo(inicio_lista_atas, numero_ata);
            break;
        case 4:
            listar_atas(inicio_lista_atas);
            printf("Introduza o titulo da ata que pretende alterar: \n");
            rewind(stdin);
            fgets(titulo_ata, TAM_TITULO_ATA, stdin);
            escapeN(titulo_ata);
            altera_estado_ata(inicio_lista_atas, titulo_ata);
            break;
        case 5:
            listar_atas_decrescente(&inicio_lista_atas);
            listar_atas(inicio_lista_atas);
            break;
        case 6:
            listar_atas_estado(&inicio_lista_atas);
            listar_atas(inicio_lista_atas);
            break;
        case 7:
            printf("Introduza o local que deseja procurar: \n");
            rewind(stdin);
            fgets(local_ata,TAM_LOCAL_ATA,stdin);
            escapeN(local_ata);
            listar_atas_por_local(inicio_lista_atas, local_ata);
            break;
        case 9:
            listar_atas_para_assinar(inicio_lista_atas);
            break;
        case 10:
            listar_atas_concluidas(inicio_lista_atas);
            break;
        case 11:
            inserir_utilizador(&info_user);
            resultado =inserir_lista_ligada_inicio(&inicio_lista_user, &info_user, validar_utilizador);
            break;
        case 12:
            editar_utilizador(&info_user);
            break;
        case 13:
            apagar_utilizador(&info_user);
            break;
        case 14:
            pesquisar_utilizador(&info_user);
            break;
        case 15:
            listar_atas(inicio_lista_atas);
            break;
        case 0:
            printf("Voltando atrás...\n");
            return -1;
        default:
            printf("Opção inválida.\n");
            break;
            
    }
    }while (opcao < 16);
    return 0;
}
