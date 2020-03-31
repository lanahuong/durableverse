
typedef struct card {
  int cout;
  type t;
  int num;
} card;

typedef struct studentCard {
    int Dev_pts;
    int Dur_pts;
    Eleve filiere;
} studentCard;

typedef enum type {PERSONNEL, ACTION} type;
typedef enum student {FISE, FISA} student;
typedef enum staff {ThomasLim = 1, MarieSzafranski, AlainFaye, ChristopheMouilleron, StefaniaDumbrava, JulienForest, NicolasBrunel, LaurenceBourard, DimitriWatel, ViteraY, KevinGoilard, VincentJeannas, MassinissaMerabet, Anne_LaureLigozat, CatherineDubois, EricLejeune, ChristineMathias, KatrinSalhab, AbassSagna, LaurentPrevel} staff;
typedef enum action {CoursDeveloppementDurable = 21, Recrutement, RentreeFISE, RentreeFISA, EnergieVerte, Diplomation, Decharge, Recyclage, ZeroPapier, RepasVegetarien, FermetureAnuelle} action;

typedef struct cardList {
  int length;
  card* cards;
} cardList; 

typedef struct stack {
    student_card* contain;
    int top;
} stack;

typedef struct board* {
    stack FISE;
    stack FISA; 
    card* Personnel[3];
    cardList deck;
    cardList hand;
    cardList discard;
} board;

typedef struct ensiie {
    int DD;
    int PE;
    int nCard;
    int nStudent;
    board cb;
} ensiie;
