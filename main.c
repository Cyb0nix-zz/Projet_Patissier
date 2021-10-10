#include <stdio.h>
#include <malloc.h>
#include "patissier.h"


int main() {
    Element_str* l_gouts = initialiser_gouts();
    File_Commandes* f_commandes = init_file_commande();
    File_Degustation* f_degustation = init_file_degustation();
    passer_commande("CMVP",f_commandes);
    Gateau* gateau_1 = creer_gateau(traiter_commande(f_commandes));
    construire_gateau(gateau_1,l_gouts);
    livrer(gateau_1,f_degustation);
    for (int i = 0; i < 4; ++i) {
        Element_str* tmp = gateau_1->p_gouts->gout;
        printf("%s",tmp->texte);
        tmp = tmp->next;

    }
    degustation(f_degustation,4);
    printf("%d",f_degustation->gateau->parts);



    return 0;
}

/*void menu() {
    char choix_etage = NULL;
    while (choix_etage != "o" && choix_etage != "n") {
        printf("Souhaiteriez vous un étage de gâteau ? \n"
               "oui : o \n"
               "non : n \n");
        scanf("%s", choix_etage);

        if(choix_etage == "o") {
            char choix_gout = NULL;
            while (choix_gout != "C" && choix_gout != "V" && choix_gout != "F" && choix_gout != "A" &&
                   choix_gout != "P" &&
                   choix_gout != "B" && choix_gout != "M") {
                printf("Quel(s) goût(s) aimeriez vous ? Saisissez l'initiale correspondante \n"
                       "Chocolat : C \nVanille : V \nFraise : F \nAbricot : A \nPomme : P \nBanane : B \nMyrtille : M\n");
                scanf("%s", choix_gout);
            }
        }
        if(choix_etage == "n")  {

            char nouveau_gateau = NULL;
            printf("Voudriez vous un autre gâteau ? \n"
                   "oui : o \n"
                   "non : n \n");
            scanf("%s", nouveau_gateau);

            if (nouveau_gateau = "o")   {
                choix_etage = "o";
            }
            else (nouveau_gateau = "n"); {
                printf("Merci d'avoir passé commande ! Nous vous la préparons !");
            }
        }
    }
}
*/