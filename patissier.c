//imports des fichiers et librairies
#include "patissier.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

Element_str* creer_gout(char* gout){
    /*
     * fonction créant la structure comprenant les goûts
     * argument : pointeur vers le tableau gout
     * return : pointeur vers le nouveau goût
     */
    Element_str* nouveau_gout = (Element_str*)malloc(sizeof(Element_str));
    strcpy(nouveau_gout->texte,gout);
    nouveau_gout->next = NULL;
    return nouveau_gout;
}

Element_str* initialiser_gouts(){
    /*
     * fonction créant le tableau avec les noms de goûts
     * argument : /
     * return : variable comportant le goût souhaité
     */
    char* gouts[] = {"Chocolat","Vanille","Fraise","Abricot","Pomme","Banane","Myrtille"};
    Element_str* l_gout;
    l_gout = creer_gout(gouts[0]);
    Element_str* nouveau_gout = l_gout;

    for (int i = 1; i < 7; ++i) {
        nouveau_gout->next = creer_gout(gouts[i]);
        nouveau_gout = nouveau_gout->next;
    }
    return l_gout;
}

File_Commandes* init_file_commande(){

    File_Commandes* f_commandes = (File_Commandes *) malloc(sizeof(File_Commandes));
    f_commandes->commande = NULL;

    return f_commandes;
}

void passer_commande(char commande[50], struct File_Commandes* f_commandes){
    Element_str* nouvelle_element = (Element_str*)malloc(sizeof(Element_str));
    strcpy(nouvelle_element->texte, commande);
    nouvelle_element->next = NULL;

    if (f_commandes->commande == NULL){
        f_commandes->commande = nouvelle_element;
    }else{
        int cpt = 0;
        Element_str* tmp = f_commandes->commande;
        while (tmp->next != NULL){
            tmp = tmp->next;
            cpt++;
        }

        if (cpt<10){
            tmp->next = nouvelle_element;
        } else{
            printf("Nombre maximal de commande simultané atteint\n");
        }

    }
}

Element_str* traiter_commande(File_Commandes* f_commandes){

    if (f_commandes->commande != NULL){
        Element_str* res = (Element_str*) malloc(sizeof(Element_str));
        *res = *f_commandes->commande;
        Element_str* old = f_commandes->commande;
        f_commandes->commande = f_commandes->commande->next;
        free(old);
        return res;
    }
    return NULL;
}

Gateau* creer_gateau(Element_str* commande){
    Gateau* gateau = (Gateau*) malloc(sizeof(Gateau));
    gateau->commande = commande;
    gateau->p_gouts = NULL;
    return gateau;
}

void construire_gateau(Gateau* gateau, Element_str* l_gouts){
    gateau->p_gouts = init_pile_gout();
    for (int i = 0; i < sizeof(gateau->commande->texte); ++i) {
        Element_str* tmp = l_gouts;
        while (tmp != NULL){
            //printf("%c",tmp->texte[0]);
            if (gateau->commande->texte[i] == tmp->texte[0]){
                ajouter_gout(gateau->p_gouts,tmp->texte);
            }
            tmp = tmp->next;
        }
    }
}

Pile_Gouts* init_pile_gout(){
    Pile_Gouts* pile_gouts = (Pile_Gouts*) malloc(sizeof(Pile_Gouts));
    pile_gouts->gout = NULL;
    return pile_gouts;
}

void ajouter_gout(Pile_Gouts* p_gout, char* gout){
    Element_str* nouveau_gout = (Element_str*) malloc(sizeof(Element_str));
    strcpy(nouveau_gout->texte,gout);
    nouveau_gout->next = p_gout->gout;
    p_gout->gout = nouveau_gout;
}

File_Degustation* init_file_degustation(){
    File_Degustation * f_degustation = (File_Degustation*) malloc(sizeof(File_Degustation));
    f_degustation->gateau = NULL;

    return f_degustation;
}

void livrer(Gateau* gateau, File_Degustation* f_degustation){
    Element_gtx * nouveau_gateau = (Element_gtx*)malloc(sizeof(Element_gtx));
    nouveau_gateau->gateau = gateau;
    nouveau_gateau->next = NULL;
    nouveau_gateau->parts = 5;

    if (f_degustation->gateau == NULL){
        f_degustation->gateau = nouveau_gateau;
    }else{
        Element_gtx* tmp = f_degustation->gateau;
        while (tmp->next != NULL){
            tmp = tmp->next;
        }

        tmp->next = nouveau_gateau;

    }
}

void degustation(File_Degustation* f_degustation, int nb_parts){
    if (f_degustation->gateau != NULL){
        for (int i = 0; i < nb_parts; ++i) {
            f_degustation->gateau->parts--;
            if(f_degustation->gateau->parts == 0){
                Element_gtx * old = f_degustation->gateau;
                f_degustation->gateau = f_degustation->gateau->next;
                free(old);
            }
        }
    } else{
        printf("Il n'y a plus de gateau\n");
    }
}







