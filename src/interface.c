#include "../headers/interface.h"


#include <stdio.h>

/* 
requires n int
assigns
ensures return the associate personnel card */
char* interface_getName(int n){
    switch(n+1){

        case 1:
            return "Thomas Lim";
            break;
        case 2:
            return "Marie Szafranski";
            break;
        case 3:
            return "Alain Faye";
            break;
        case 4:
            return "Christophe Mouilleron";
            break;
        case 5:
            return "Stefania Dumbrava";
            break;
        case 6:
            return "Julien Forest";
            break;
        case 7:
            return "Nicolas Brunel";
            break;
        case 8:
            return "Laurence Bourard";
            break;
        case 9:
            return "Dimitri Watel";
            break;
        case 10:
            return "Vitera Y";
            break;
        case 11:
            return "Kevin Goilard";
            break;
        case 12:
            return "Vincent Jeannas";
            break;
        case 13:
            return "Massinissa Merabet";
            break;
        case 14:
            return "Anne_Laure Ligozat";
            break;
        case 15:
            return "Catherine Dubois";
            break;
        case 16:
            return "Eric Lejeune";
            break;
        case 17:
            return "Christine Mathias";
            break;
        case 18:
            return "Katrin Salhab";
            break;
        case 19:
            return "Abass Sagna";
            break;
        case 20:
            return "Laurent Prevel";
            break;
        case 21:
            return "Cours Développement durable";
            break;
        case 22:
            return "Recrutement";
            break;
        case 23:
            return "Rentrée FISE";
            break;
        case 24:
            return "Rentrée FISA";
            break;
        case 25:
            return "Energie verte";
            break;
        case 26:
            return "Diplomation";
            break;
        case 27:
            return "Décharge";
            break;
        case 28:
            return "Recyclage";
            break;
        case 29:
            return "Zéro papier";
            break;
        case 30:
            return "Repas végétarien";
            break;
        case 31:
            return "Fermeture annuelle";
            break;
        }
    return "";
}


/*
requires the current turn currturn
assigns
ensures display new turn and it's number and additionnal informations
*/

void interface_newTurn(int currturn){
    printf("\n\n=================================================\n");
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
    printf("--------------------------------------------------------\n");
    printf("Nouvelle phase\nC'est à l'ENSIIE %d de jouer !\n\n",player);
}

/*requires 2 correctly formatted board (player1=current player, player2=adversary)
assigns
ensures display the board of each player
*/
void interface_board(board p1, board p2){
    /*le joeur actuel est p1 et le joueur adverse est p2*/
    int i =0;
    queue* q_perso_p1 = card_getPersonnel(p1);
    queue* q_perso_p2 = card_getPersonnel(p2);
    
    /*on affiche en colonne les cartes du board*/
    printf("TERRAIN ADVERSE\n");
    printf("PE : %d\tDD : %d\n", board_getPE(p2),board_getDD(p2));
    printf("Nombre de carte FISE | Nombre de carte FISA | Personnels\n");
    if (structure_getQueueSize(q_perso_p2)>0) {
        printf("%20d%23d%24s\n",card_getFiseCount(p2), card_getFisaCount(p2), interface_getName(structure_getQueueContent(q_perso_p2)[0]));
        for(i=1;i<structure_getQueueSize(q_perso_p2);i++){
            printf("%67s\n", interface_getName(structure_getQueueContent(q_perso_p2)[i]));
        }
    } else {
        printf("%20d%23d\n",card_getFiseCount(p2),card_getFisaCount(p2));
    } 
    printf("\nMON TERRAIN\n");
    printf("PE : %d\tDD : %d\n", board_getPE(p1),board_getDD(p1));
    printf("Nombre de carte FISE | Nombre de carte FISA | Personnels\n");
    if (structure_isEmptyQueue(q_perso_p1)){
        printf("%20d%23d\n",card_getFiseCount(p1), card_getFisaCount(p1));
    } else {
        printf("%20d%23d%24s\n",card_getFiseCount(p1), card_getFisaCount(p1), interface_getName(structure_getQueueContent(q_perso_p1)[0]));
        for(i=1;i<structure_getQueueSize(q_perso_p1);i++){
            printf("%67s\n", interface_getName(structure_getQueueContent(q_perso_p1)[i]));
        }
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
    while(tmp != 0 && tmp != 1){
        printf("Quelle carte veux-tu ?\nTape 0 pour un carte FISE\nTape 1 pour une carte FISA\n");
        scanf("%d",&tmp);
        if (tmp != 0 && tmp != 1){printf("Erreur : Seulement 0 ou 1 accepté\n");}
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
    cardList* hand = card_getHand(p);
    printf("PE : %d\tDD : %d\n", PE,board_getDD(p));
    printf("Cartes dans la main\n");
    if (structure_isEmptyCardList(hand)) {
        printf("Vous n'avez plus de cartes en main\n");
    } else {
        for (int i = 0; i < structure_getCardListLength(hand); i++){
            char* name = interface_getName(hand->content[i]);
            printf("%d %s\n", hand->content[i]+1, name);
            //free(name);
        }
        printf("Cartes jouables\n");
        for (int j = 0; j< structure_getCardListLength(hand); j++){
            if (card_getCost(hand->content[j])<=PE ){
            char* name = interface_getName(hand->content[j]);
            printf("%d %s\n", hand->content[j]+1, name);
            //free(name);
            }
        }

    printf("Rentrer le n° de la carte que tu veux jouer (ou -1 si tu n'en joue aucune) : ");
    scanf("%d",&tmp);
    }
    return tmp-1;

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
