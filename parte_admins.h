//
//  parte_admins.h
//  Gestão de atas
//
//  Created by Luis Malheiro on 20/05/2021.
//
#define TAM_DATA_ATA 11
#define TAM_LOCAL_ATA 50
#define TAM_TITULO_ATA 100
#define TAM_TEXTO_ATA 500
#define TAM_ACIONISTAS_PRESENTES 500

#define TAM_NOME 50
#define TAM_USER 50
#define TAM_PASS 50
#define MAX_ACIONISTAS 50
#ifndef parte_admins_h
#define parte_admins_h

#define NUMERO_MAXIMO_ASSINATURAS 8
#include <stdio.h>

typedef struct ata{
    char data_ata[TAM_DATA_ATA];
    char titulo_ata[TAM_TITULO_ATA];
    char local_ata[TAM_LOCAL_ATA];
    char texto_ata[TAM_TEXTO_ATA];
    char acionistas_presentes[50][TAM_ACIONISTAS_PRESENTES]; //[MAX_ACIONISTAS]
    int estado_ata;
    int numero_ata;
    int estado_info;
    int info_ata[1000];
}INFO_ATA;

typedef struct username{
    char nome[TAM_NOME];
    char username[TAM_USER];
    char password[TAM_PASS];
    short int tipo;   //1- admin 2- acionista
    int numero_utilizadores;
}INFO_USER;

typedef struct ata_elem{
    INFO_ATA info;
    struct ata_elem *seguinte;
}ATA_ELEM;

typedef struct user_elem{
    INFO_USER info;
    struct user_elem *seguinte;
}USER_ELEM;

void escapeN(char string[]);
ATA_ELEM *obter_no_anterior_lista(ATA_ELEM *inicio_lista, ATA_ELEM *nodo);
void trocar_nos_atas(ATA_ELEM **inicio_lista, ATA_ELEM **nodo1, ATA_ELEM **nodo2);
int existe_ata(ATA_ELEM *inicio_lista, char data_ata[]);
void listar_atas(ATA_ELEM *inicio_lista);
int alterar_data(ATA_ELEM *inicio_lista, int data_ata[]);
int alterar_texto_ata(ATA_ELEM *inicio_lista, char text_ata[]);
int alterar_estado_ata(ATA_ELEM *inicio_lista, int estad_ata);
void listar_atas_decrescente(ATA_ELEM **inicio_lista);
void listar_atas_estado(ATA_ELEM **inicio_lista);
void listar_atas_local(ATA_ELEM **inicio_lista);
int inserir_lista_ligada_inicio(USER_ELEM **apt_l, INFO_USER *apt_info, int (*validar)(INFO_USER *));
void inserir_utilizador(INFO_USER *user);
void editar_utilizador(INFO_USER *user);
void apagar_utilizador(INFO_USER *user);
void pesquisar_utilizador(INFO_USER *user);
int menu_admin();

#endif /* parte_admins_h */
