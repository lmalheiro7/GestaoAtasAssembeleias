//
//  main.c
//  Gestão de atas
//
//  Created by Luis Malheiro on 19/05/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parte_admins.h"
#include "parte_acionistas.h"

 int menu_inicial(INFO_USER *user){
     int tentativas = 3, logins = 0;
     char username[20], password[20];
     char username2[20] = "admin", password2[20] = "admin";
     int tipo_user = 0, tipo_user1 = 1, tipo_user2 = 2, opcao = 0;
     
     do{
         printf("Tipo de user?\n 1 - Administrador.\n 2 - Acionista \n");
         scanf("%d", &tipo_user);
         if (tipo_user >= 3 || tipo_user <=0) {
             printf("ERRO! Introduza uma opcao válida.\n");
             return -1;
             }
         printf("----------LOGIN-------\n");
         printf("Username? \n");
         fflush(stdin);
         gets(username);
         
         printf("Password? \n");
         fflush(stdin);
         gets(password);
         
         FILE *fp, *fp1 =NULL;
         fp= fopen("/Users/lmalheiro/Documents/Gestão de atas/utilizadores.txt", "r");
         fp1= fopen("/Users/lmalheiro/Documents/Gestão de atas/acionistas.txt", "r");
         if (fp == NULL) {
             printf("ERRO! Não existe ficheiro txt.\n");
             return 1;
         }
         //UTILIZADOR POR DEFEITO
         if ((tipo_user == 1) && (strcmp(username, username2) == 0)) {
             menu_admin();
             tentativas = 1;
         }
         else{
         while(fscanf(fp,"%[^;];%[^;];%[^;];%hi",&user->nome, &user->username, &user->password, &user->tipo) != EOF ){
             //UTILIZADOR ADMIN A PARTIR DO FICHEIRO TXT
             if ((strcmp(username, user->username) == 0) && (tipo_user == 1) && (strcmp(password, user->password) == 0)) {
                 menu_admin();
                 tentativas = 1;
             }
     }
         }
         if (tipo_user == 2) {
             while(fscanf(fp1,"%[^;];%[^;];%[^;];%hi",&user->nome, &user->username, &user->password, &user->tipo) != EOF ){
                 if ((strcmp(username, user->username) == 0) && (strcmp(password, user->password) == 0)) {
                     menu_acionista();
                     tentativas = 1;
                 }
         }
         }
         if ((strcmp(username, user->username) != 0) && (strcmp(password, user->password) != 0)) {
             printf("ERRO, dados inválidos.\n\n");
             tentativas --;
         }
         fclose(fp);
         fclose(fp1);
     }while (tentativas != 0 && logins == 0);
     if (tentativas == 0) {
         printf("ERRO! Máximo de tentavivas acalçandas.\n");
     }
     return 0;
 }

int main(int argc, const char * argv[]) {
    INFO_USER info_user;
    menu_inicial(&info_user);
    return 0;
}
