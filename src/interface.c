#include "../headers/interface.h"


#include <stdio.h>

void interface_newTurn(int currturn){
    printf("\nPrépare toi !\nUn nouveau tour commence...\n");

    printf("infomration sur le tour :\n\nTour n°%d\n",currturn);
    if (currturn % 2 == 0){
       	    printf("Tour pair : Les cartes FISA disaparaissent\n");

    }
    else {
	    printf("Tour impair : Les cartes FISA apparaissent\n");
    }

    if (currturn < 6){
	    printf("1 carte Personnel max sur le plateau\n");
    }
    else if (currturn >= 6 && currturn < 11){
	    printf("2 cartes Personnel max sur le plateau\n");
    }
    else if (currturn >= 11){
	    printf("3 cartes Personnel max sur le plateau\n");
    }
    printf("\n");
}


void interface_newPhase(int player){
 	printf("Nouvelle phase\nC'est à l'ENSIIE %d de jouer !\n\n",player);
}

void interface_board(board p1, board p2){

	printf("TERRAIN ADVERSE\n");
	printf("Nombre de carte FISE | Nombre de carte FISA | Personnels\n");
	printf("*%d                      *%d                      *%d",card_getFiseCount(&p1), card_getFisaCount(&p1), structure_getQueueContent(card_getPersonnel(&p1))[0]);



}
int main(){
    return 0;
}
