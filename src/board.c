#include "../headers/board.h"
struct board {
    int DD;
    int PE;
    int FiseCount;
    int FisaCount; 
    int duraBonus;
    int devBonus;
    queue personnel;
    cardList deck;
    cardList hand;
    cardList discard;
};