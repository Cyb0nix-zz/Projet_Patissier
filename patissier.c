//imports des fichiers et librairies
#include "patissier.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//appels des variables permanentes
Element_str* l_gouts;
File_Commandes* f_commandes;
File_Degustation* f_degustation;


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

void passer_commande(char commande[50], struct File_Commandes* f_commandes){
    Element_str* nouvelle_element = (Element_str*) malloc(sizeof(Element_str));
    strcpy(nouvelle_element->texte, commande);
    nouvelle_element->next = NULL;

    if (f_commandes->commande == NULL){
        f_commandes->commande = nouvelle_element;
    }else{
        if()
    }
}

int nbr_commande(Element_str* liste)
{
    if( liste == NULL){
        return 0;
    }
    else{
        return 1 + nbr_commande(liste->next);
    }
}


