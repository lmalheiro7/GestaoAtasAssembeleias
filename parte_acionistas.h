//
//  parte_acionistas.h
//  Gestão de atas
//
//  Created by Luis Malheiro on 21/05/2021.
//

#ifndef parte_acionistas_h
#define parte_acionistas_h

#include <stdio.h>
#include "parte_admins.h"


typedef struct no_stack{
    INFO_ATA info;
    struct no_stack* proximo;
} NO_STACK;

typedef struct stack{
    int tamanho;
    NO_STACK* topo;
} STACK;

USER_ELEM *procura_no_anterior_acionista(USER_ELEM *inicio_lista, USER_ELEM *no);
void trocar_nos_acionistas(USER_ELEM **inicio_lista, USER_ELEM **no1, USER_ELEM **no2);
void listar_acionistas_ordem_alfabetica(USER_ELEM **inicio_lista);
void listar_todos_acionistas(USER_ELEM *inicio_lista);
void procurar_acionista_por_nome(USER_ELEM *inicio_lista, char nome[]);
void verificar_atas_para_assinar(ATA_ELEM *info);
int alterar_perfil(USER_ELEM *inicio_lista, char nome_perfil[], char user[], char password[]);
int menu_acionista();
char pesquisa_user(INFO_USER *user);
char pesquisar_acionista_por_nome(INFO_USER *user);

#endif /* parte_acionistas_h */
