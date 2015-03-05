/*model zaklada odczytywanie wpisanej ostatnio wartości u uwzglednienie jej w mozliowosciach wygranej
tak aby nie sprawdzac za kazdym razem stanu calej tablicy
model wygranych
w wierszu 123
w kolumniej 456
na przekatnej 78  przechowywane w tabeli int mozliw[8];

kazda mozliosci wygranej (1-8) moze przyjac nastepujace stany

mozliw[8]
0 - bedzie remis 
1 - wygrana gracza
2 - wygrana komputera
3 - szansa gracza
4 - d. szansa gracza
5 - stan poczatkowy np. mozliw[7]=7;
6 - szansa komputera
7 - d. szansa komputera

czyj_ruch
1 - komputer
2 - gracz

potrzeba bedzie 
f., ktora otrzymujac znak i miejsce wstawienia zmieni mozliosci oraz wyswietli ewentualny komunikat o wygranej
f., ktora nakaze okreslona reakcje dla komputera w przypadku możliwości '6'
f., która będzie wczytywac ruch gracza
f., która będzie bronić zajętych pól
f., pisząca plansze i instrukcję,
f., ruszająca komputerem,
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	char plans[3][3];
	int czyj_ruch;		//	1- K(G);	2-G
	int ostat_ruch;		//	przechowywuje gdzie pojawił się ostatni znak
	int pozst_ruch;
	int kto_wygral;		//	1- K(G);	2-G;	0-REMIS
	int mozliw[8];		//	0-remis; 1-s.g; 2-s.k; 3-ds.g; 4-ds.k; 5-wyg.g; 6-wyg.k; 7-nic; 
} *kk_t;

void wynik(kk_t g){
	char *rezultat;
	if(g->kto_wygral == 1){
		rezultat="Przegrałeś z moim programem \n:D";
	}else if(g->kto_wygral == 2){
		rezultat="niestety... \nWygrałeś";
	}else{
		rezultat="REMIS. \nDzięki. To była uczciwa walka";
	}
	printf("KONIEC GRY.\nWynik: %s\n", rezultat);
}

int wygrana(kk_t g){
	int i;
	for( i = 0; i < 8; i++){
		if(g->mozliw[i] >= 5){
		//	printf("Wynik funkcji wygrana: %d (1-K 2-G 0-REMIS inne błąd)\n",(7 - g->mozliw[i])); //DEBUGER!!!
			return (7 - g->mozliw[i]);
		}
	}
	return 0;
}

void zmien_mozliw(kk_t g, int linia){ // przyjmuje g i linie w zakresie 0-7 o wartościach 0-7
	if(g->mozliw[linia] == 0){
	} else if (g->mozliw[linia] == 7) {
		g->mozliw[linia] = g->czyj_ruch;
	} else if (((g->mozliw[linia]+1)%2) != (g->czyj_ruch - 1)) {
		g->mozliw[linia] = 0;
	} else {
		g->mozliw[linia] += 2;
	}
}

int analizuj_sytuacje(kk_t g){
	int i,i_ruch, j_ruch;
	i_ruch= ((g->ostat_ruch-1+3)/3)-1;
	j_ruch= g->ostat_ruch-3*i_ruch-1+3;
//	printf("analizuj_sytuacje: i_ruch=%d, j_ruch=%d\n", i_ruch, j_ruch);
	
	zmien_mozliw(g, i_ruch);
	zmien_mozliw(g, j_ruch);
	if(  g->ostat_ruch == 5){
		zmien_mozliw(g, 6);
		zmien_mozliw(g, 7);
	}else if(  g->ostat_ruch == 7 ||  g->ostat_ruch == 3){
		zmien_mozliw(g, 6);
	}else if(  g->ostat_ruch == 9 ||  g->ostat_ruch == 1){
		zmien_mozliw(g, 7);
	}
	//printf("0-remis; 1-s.g; 2-s.k; 3-ds.g; 4-ds.k; 5-wyg.g; 6-wyg.k; 7-nic \n Dla g->ostat_ruch = %d:\n",g->ostat_ruch);
	for(i=0;i<8;i++){
	//	printf("g->mozliw[%d]=%d\n", i,g->mozliw[i]); 
	}
}

int wstaw_by_wygrac(kk_t g){
	int i, ruch, i_ruch, j_ruch, zmiennna;
	zmiennna=0;
	if(g->plans[1][1] == '-'){
		return 5;
	}
	if((g->plans[0][0] == 'O' && g->plans[2][2] =='O') || 
	    (g->plans[0][2] == 'O' && g->plans[2][0] =='O')){
		for(i=0; i<8; i++){
			if(g->mozliw[i] == 2)
				return wstaw_w_linie(g,i);
		}
	 }
	do{
			ruch=1+2*(rand() % 5);
			i_ruch= ((ruch-1+3)/3)-1;
			j_ruch= ruch-3*i_ruch-1;
			zmiennna++;
			if(zmiennna>30)
				return (rand() % 8)+1;
	}while(g->plans[i_ruch][j_ruch] != '-');
	return ruch;
}

int wstaw_w_linie(kk_t g, int linia){	//przyjumie linie 0-7 i zamienia na 1-8
	int ruch, i_ruch, j_ruch;
	linia++;
	if(linia>=1 && linia<=3){
		do{
			ruch=(linia-1)*3+(rand() % 3)+1;
			i_ruch= ((ruch-1+3)/3)-1;
			j_ruch= ruch-3*i_ruch-1;
		}while(g->plans[linia-1][j_ruch] != '-');	
		return ruch;
	}else if(linia>=4 && linia<=6){
		do{
			ruch=(linia-3)+3*(rand() % 3);
			i_ruch= ((ruch-1+3)/3)-1;
			j_ruch= ruch-3*i_ruch-1;
		}while(g->plans[i_ruch][linia-3-1] != '-');	
		return ruch;
	}else if(linia==7){
		do{
			ruch=7-2*(rand() % 3);
			i_ruch= ((ruch-1+3)/3)-1;
			j_ruch= ruch-3*i_ruch-1;
		}while(g->plans[i_ruch][j_ruch] != '-');	
		return ruch;
	}else if(linia==8){
		do{
			ruch=9-4*(rand() % 3);
			i_ruch= ((ruch-1+3)/3)-1;
			j_ruch= ruch-3*i_ruch-1;
		}while(g->plans[i_ruch][j_ruch] != '-');	
		return ruch;
	}
	return (rand() % 8)+1;
}

int ruch_komputera(kk_t g){
	int i;
	for(i=0; i<8; i++){
		if(g->mozliw[i] == 4)
			return wstaw_w_linie(g,i);
	}
	for(i=0; i<8; i++){
		if(g->mozliw[i] == 3)
			return wstaw_w_linie(g,i);
	}
	return wstaw_by_wygrac(g);
	//return (rand() % 8)+1;
}

void nast_ruch(kk_t g){
	if( g->czyj_ruch == 1) {	// Ruch wykonuje komputer (X)
		int ruch, i_ruch,j_ruch;
		do{
			ruch=ruch_komputera(g);
			i_ruch= ((ruch-1+3)/3)-1;
			j_ruch= ruch-3*i_ruch-1;
		}while(g->plans[i_ruch][j_ruch] != '-');	
		g->plans[i_ruch][j_ruch]='X';
		g->ostat_ruch=ruch;
		g->czyj_ruch=2;
	} else{					// Ruch wykonuje gracz (O)
		int ruch, i_ruch,j_ruch;
		int blad=0;
		do{
			if(blad>0){
				printf("BŁĄD: Ruch %d niedozwolony! Podaj inny\n",ruch);
			}
			scanf("%d", &ruch);
			i_ruch= ((ruch-1+3)/3)-1;
			j_ruch= ruch-3*i_ruch-1;
			blad++;
		}while(g->plans[i_ruch][j_ruch] != '-');	
		g->plans[i_ruch][j_ruch]='O';
		g->ostat_ruch=ruch;
		g->czyj_ruch=1;
	}
	analizuj_sytuacje(g);
}
//wyswietl powinno byc chyba nizej
void wyswietl(kk_t g){
	int i, j;
	int k=9;
	printf("Plansza: \t Numery pól:\n",k-2, k-1, k);
	for( i = 2; i>=0;i--){
		for(j = 0; j<3; j++){
			printf("  %c",g->plans[i][j]);
		}
		printf("\t| %d %d %d\n",k-2, k-1, k);
		k -= 3;
	}
}

int graj(kk_t g){
	while(g->pozst_ruch>0){
		nast_ruch(g);
		wyswietl(g);
		if( (g->kto_wygral = wygrana(g)) == 0){
			g->pozst_ruch--;
		} else {
			return 0;
		}
	}
}



void inicjuj(kk_t g){
	int i,j,x;
  do{
	  printf("Kto zaczyna? Wciśnij:\n 1 - komputer\n 2 - gracz\n");
    scanf("%d",&x);
  }while(x != 1 && x != 2);
  g->czyj_ruch = x;	//domysl: gracz
	for( i = 2; i>=0;i--){
		for(j = 0; j<3; j++){
			g->plans[i][j]='-';
		}
	}
	for(i = 0; i < 8; i++){
		g->mozliw[i]=7;
	}
	g->pozst_ruch=9;	//maksymalna liczba ruchów (chyba, że wcześniej wygrana)
	g->kto_wygral=0;		//domysl: 0 - remis
}

void personalizuj(kk_t g);

int main(int argc, char **argv){
	char odpowiedz;
	do{
		srand(time(NULL));
		kk_t g = malloc(sizeof *g);
		//personalizuj(g, argc, argv);
		inicjuj(g);
		wyswietl(g);
		graj(g);
		wynik(g);
		printf("GRAMY JESZCZE RAZ? (t/n)\n");
		scanf("%s", &odpowiedz);
	}while(odpowiedz == 116);
	printf("Ok! Narazie. \n");
	return 0;
}
