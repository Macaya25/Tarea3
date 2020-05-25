typedef struct card {
	char  name[14];
	short int Dmg;
	short int Hp;
} card;

typedef struct valor_dados{
	int roll_player;
	int roll_gm;
	struct valor_dados * next;
} valor_dados;

card *Cartas;

int upload_cards(char*);
void show_match(int, card, card, int, int);
int* cartas_jugador();
int roll_count(valor_dados*);
