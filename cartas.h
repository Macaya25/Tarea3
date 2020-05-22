typedef struct card {
	char  name[14];
	short int Dmg;
	short int Hp;
} card;

card *Cartas;

int upload_cards(char*);
