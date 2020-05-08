#include "../headers/interface.h"


#include <stdio.h>

/* 
requires n int
assigns
ensures return the associate personnel card */
char* interface_getName(int n){
    char* res;
    switch(n){

        case 1:
            res= "Thomas Lim";
            break;
        case 2:
            res= "Marie Szafranski";
            break;
        case 3:
            res= "Alain Faye";
            break;
        case 4:
            res= "Christophe Mouilleron";
            break;
        case 5:
            res= "Stefania Dumbrava";
            break;
        case 6:
            res= "Julien Forest";
            break;
        case 7:
            res= "Nicolas Brunel";
            break;
        case 8:
            res= "Laurence Bourard";
            break;
        case 9:
            res= "Dimitri Watel";
            break;
        case 10:
            res= "Vitera Y";
            break;
        case 11:
            res= "Kevin Goilard";
            break;
        case 12:
            res= "Vincent Jeannas";
            break;
        case 13:
            res= "Massinissa Merabet";
            break;
        case 14:
            res= "Anne_Laure Ligozat";
            break;
        case 15:
            res= "Catherine Dubois";
            break;
        case 16:
            res= "Eric Lejeune";
            break;
        case 17:
            res= "Christine Mathias";
            break;
        case 18:
            res= "Katrin Salhab";
            break;
        case 19:
            res= "Abass Sagna";
            break;
        case 20:
            res= "Laurent Prevel";
            break;
        }
    return res;
}


/*
requires the current turn currturn
assigns
ensures display new turn and it's number and additionnal informations
*/

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

/*requires 
assigns
ensures display "Nouvelle Phase" and the player associated to the new phase
*/
void interface_newPhase(int player){
    printf("Nouvelle phase\nC'est à l'ENSIIE %d de jouer !\n\n",player);
}

/*requires 2 correctly formatted board (player1=current player, player2=adversary)
assigns
ensures display the board of each player
*/
void interface_board(board p1, board p2){
    /*le joeur actuel est p1 et le joueur adverse est p2*/
    int i =0;
    queue q_perso_p1 = card_getPersonnel(p1);
    queue q_perso_p2 = card_getPersonnel(p2);
    
    /*on affiche en colonne les cartes du board*/
    printf("TERRAIN ADVERSE\n");
    printf("Nombre de carte FISE | Nombre de carte FISA | Personnels\n");
    printf("%20d%23d%13s",card_getFiseCount(p2), card_getFisaCount(p2), interface_getName(structure_getQueueContent(card_getPersonnel(p2))[0]));
    for(i=1;i<structure_getQueueSize(q_perso_p2);i++){
        printf("                                                   %s\n", interface_getName(structure_getQueueContent(card_getPersonnel(p2))[i]));
    }
    printf("\nMON TERRAIN\n");
    printf("Nombre de carte FISE | Nombre de carte FISA | Personnels\n");
    printf("%20d%23d%13s",card_getFiseCount(p1), card_getFisaCount(p1), interface_getName(structure_getQueueContent(card_getPersonnel(p1))[0]));
    for(i=1;i<structure_getQueueSize(q_perso_p1);i++){
        printf("                                                   %s\n", interface_getName(structure_getQueueContent(card_getPersonnel(p1))[i]));
    }
}

/*requires 
 * assigns
 * ensures ask the player which type of card it wants
 *         return the chosen type of card (0 for fise 1 for fisa)
 */
int interface_fiseOrFisa(){
    int tmp = -1;
    /*la boucle se termine lorque le joueur choisi 1 ou 0 */
    while(tmp != 0 || tmp != 1){
        printf("Quelle carte veux-tu ?\nTape 0 pour un carte FISE\nTape 1 pour une carte FISA\n");
        scanf("%d",&tmp);
        if (tmp != 0 || tmp != 1){printf("Erreur : Seulement 0 ou 1 accepté\n");}
    }
    return tmp;
}


/*requires 
 * assigns 
 * ensures The function ask the player what to do : play a card or finish the turn. 
 *         The function only propose the card which cost less than player s PE. If no card
 *         available then the only choice is to end the turn
 *         return -1 if the player finish the turn
 *         otherwise return the number of the card
 */
int interface_choice(board p, int PE){
    int tmp = -1;
    printf("Cartes dans la main\n");
    for (int i = 0; i < structure_getCardListLength(card_getHand(p)) -1; i++){
        printf("%d %s\n", structure_getCardListContent(card_getHand(p))[i], interface_getName(structure_getCardListContent(card_getHand(p))[i]));
    }
    printf("Cartes jouables\n");
    for (int j = 0; j< structure_getCardListLength(card_getHand(p)) -1; j++){
        if ( PE <= card_getCost(structure_getCardListContent(card_getHand(p))[j]) ){
            printf("%d %s\n", structure_getCardListContent(card_getHand(p))[j], interface_getName(structure_getCardListContent(card_getHand(p))[j]) );
        }
    }

    scanf("Rentrer le n° de la carte que tu veux jouer (ou -1 si tu n'en jouer aucune) :%d",&tmp);
    return tmp;

}

/*requires the winner( player 0 or 1) and players' DD
 * assigns
 * ensures display the winner & the final score 
 * */

void interface_endGame(int winner, int DD1, int DD2){
    printf("=============== FIN DU JEU ===============\n");
    printf("            Score final %d||%d\n",DD1, DD2);
    printf(" Le joueur %d remporte la partie !\n",winner);

}
