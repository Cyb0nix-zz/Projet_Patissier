#include <stdio.h>
#include "patissier.h"

int main() {


    return 0;
}

void menu() {
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
