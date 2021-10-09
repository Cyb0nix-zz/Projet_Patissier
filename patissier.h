
#ifndef PROJET_PATISSIER_PATISSIER_H
#define PROJET_PATISSIER_PATISSIER_H

typedef struct Element_str{
    char texte[50];
    struct Element_str* next;
}Element_str;

typedef struct Gateau{
    struct Element_str* commande;
    struct Pile_Gouts* p_gouts;
}Gateau;

typedef struct File_Commandes{
    struct Element_str* commande;
}File_Commandes;

typedef struct Pile_Gouts{
//TODO
}Pile_Gouts;

typedef struct Element_gtx{
    struct Gateau* gateau;
    struct Element_gtx* next;
}Element_gtx;

typedef struct File_Degustation{
//TODO
}File_Degustation;

Element_str* creer_gout(char* gout);

Element_str* initialiser_gouts();

File_Commandes* initialiser_file_commandes();

#endif //PROJET_PATISSIER_PATISSIER_H
