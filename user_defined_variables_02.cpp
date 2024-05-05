#include <iostream>
#include <string>

using namespace std;

//utworzenie struktury sAuto z polami
struct sAuto {
	string nazwa;
	/*
	string model;
	int rok;
	char skrzynia;
	float pojemnosc;
	int moc;
	*/
};

void zeruj(sAuto*& Auto, const short n){
	for(short i = 0; i<n; i++){
		Auto[i].nazwa = "";
	}

}


bool wczytaj(sAuto& Auto){
	cout<<"wykorzystanie fun. wczytaj(sAuto& Auto)"<<endl;

	cout<<"podaj nazwe samochodu"<<endl;
	if(!(cin>>Auto.nazwa)){ //DIAGNOSTYKA STRUMIENIA, 
		cerr<<"blad przypisania danych"<<endl;
		return false;
	}
	return true;
}

bool wczytaj(sAuto* Auto){
	cout<<"wykorzystanie fun. wczytaj(sAuto* Auto)"<<endl;
	
	cout<<"podaj nazwe samochodu"<<endl;
	if(!(cin>>Auto->nazwa)){
		cerr<<"blad przypisania danych"<<endl;
		return false;
	}
	return true;
}

sAuto* wczytaj(const short n){
	cout<<"wykorzystanie fun. wczytaj(const short n)"<<endl;
	sAuto* tab = new sAuto[n];
	zeruj(tab,n);
	
	
	for(short i = 0; i<n; i++){//usupelniania teblicy aut
		if(wczytaj(tab[i])==false){//jezeli nie powiedzie sie wczytanie danych
			cerr<<"blad przypisania danych"<<endl;
			if(tab){//USUNIECIE TAB
				delete [] tab;
				tab = nullptr;
			}
		}
	}
	return tab;
}

bool wczytaj(sAuto* t, const short n){//pobiera 'kopie' orginalu t
	t = new sAuto[n];
	zeruj(t,n);

	for(short i = 0; i<n; i++){
		if(wczytaj(t[i])==false){
			cerr<<"blad przypisania danych"<<endl;
			return false;
		}
	}
	return true;
}
bool wczytaj1(sAuto*& t, const short n){
	t = new sAuto[n];
	zeruj(t,n);
	
	for(short i = 0; i<n; i++){
		if(wczytaj(t[i])==false){
			cerr<<"blad przypisania danych"<<endl;
			return false;
		}
	}
	return true;
}

bool wypisz(const sAuto* Auto){//wskaznik do konkretnego obiektu

	if(!(cout<<Auto->nazwa<<'\t')){
		cerr<<"blad wyswitlenia danych"<<endl;
		return false;
	}
	return true;
}

bool wypisz(const sAuto* t, const short n){
	for(short i = 0; i<n; i++){
		if(!(cout<<wypisz(&t[i])<<endl)){//bez referencji traktuje t[i] jako tablice
			cerr<<"blad wyswitlenia danych"<<endl;
			return false;
		}
	}
	return true;
}

void usun(sAuto*& tab){
	if(tab){
		delete [] tab;
		tab = nullptr;
	}
}

int main(){

	short n;
	cout<<"podaj rozmiar tablicy dynamicznej, ilosc samochodow"<<endl;
	cin>>n;
	
	sAuto * tab1 = nullptr; //wskaznik do tablicy z obiektami sAuto 
	sAuto * tab2 = nullptr;
	tab2 = new sAuto[n];
	zeruj(tab2,n);
	
	
	if((wczytaj1(tab1,n))==false){
		cerr<<"blad fun wczytaj"<<endl;
		return -1;
	}
	wypisz(tab1,n);
	
	/*
	if(!(wczytaj(tab2,n))){
		cerr<<"blad fun wczytaj"<<endl;
		return -1;
	}
	wypisz(tab2,n);
	*/
	usun(tab2);
	usun(tab1);

	return 0;
}
