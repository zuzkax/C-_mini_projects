//code doesnt work

#include<iostream>
using namespace std;

struct sAuto{
	
	string nazwa, model;
	int rok_prod, moc;
	char skrzynia;
	float pojemnosc;
	};
	
sAuto inicjuj(const string nazwa, const string model, const int rok, const char skrzynia, const float pojemnosc, const int moc){
	sAuto autox;
	autox.nazwa = nazwa;
	autox.model = model;
	autox.rok_prod = rok;
	autox.skrzynia = skrzynia;
	autox.pojemnosc = pojemnosc;
	autox.moc = moc;
	return autox;
	
	}
/*
void inicjuj1(sAuto& autox, const string nazwa, const string model, const int rok, const char skrzynia, const float pojemnosc, const
int moc){
	autox.nazwa = nazwa;
	autox.model = model;
	autox.rok_prod = rok;
	autox.skrzynia = skrzynia;
	autox.pojemnosc = pojemnosc;
	autox.moc = moc;
	}

void inicjuj(sAuto* autox, const string nazwa, const string model, const int rok, const char skrzynia, const float pojemnosc,const int moc){
	autox->nazwa = nazwa;
	autox->model = model;
	autox->rok_prod = rok;
	autox->skrzynia = skrzynia;
	autox->pojemnosc = pojemnosc;
	autox->moc = moc;
	}
*/

sAuto wczytaj(sAuto (*wfun)(const string, const string, const int, const char, const float, const int)){
	string nazwa, model;
	int rok_prod, moc;
	char skrzynia;
	float pojemnosc;
	
	cout<<"podaj nazwe samochodu"<<endl;
	cin>>nazwa;
	cout<<"podaj model samochodu"<<endl;
	cin>>model;
	cout<<"podaj rok produkcji samochodu"<<endl;
	cin>>rok_prod;
	cout<<"podaj rodzaj skrzyni biegow samochodu"<<endl;
	cin>>skrzynia;
	cout<<"podaj pojemnosc silnika"<<endl;
	cin>>skrzynia;
	cout<<"podaj moc silnika"<<endl;
	cin>>moc;
	
	return(*wfun)(nazwa,model,rok_prod, skrzynia, pojemnosc,moc);//O CHUJ MU CHODZI Z TA POJEMNOSCIA
	
	}

/*
void wczytaj1(sAuto& autox, void (*wfun)(sAuto&, const string,const string, const int, const char, const float, const int)){
	string nazwa, model;
	int rok_prod, moc;
	char skrzynia;
	float pojemnosc;
	
	cout<<"podaj nazwe samochodu"<<endl;
	cin>>nazwa;
	cout<<"podaj model samochodu"<<endl;
	cin>>model;
	cout<<"podaj rok produkcji samochodu"<<endl;
	cin>>rok_prod;
	cout<<"podaj rodzaj skrzyni biegow samochodu"<<endl;
	cin>>skrzynia;
	cout<<"podaj pojemnosc silnika"<<endl;
	cin>>skrzynia;
	cout<<"podaj moc silnika"<<endl;
	cin>>moc;
	
	wfun(autox, nazwa, model, rok_prod, skrzynia, pojemnosc, moc);
}


void wczytaj1(sAuto* autox, void (*wfun)(sAuto*, const string,const string, const int, const char, const float, const int)){
        string nazwa, model;
	int rok_prod, moc;
	char skrzynia;
	float pojemnosc;
	
	cout<<"podaj nazwe samochodu"<<endl;
	cin>>nazwa;
	cout<<"podaj model samochodu"<<endl;
	cin>>model;
	cout<<"podaj rok produkcji samochodu"<<endl;
	cin>>rok_prod;
	cout<<"podaj rodzaj skrzyni biegow samochodu"<<endl;
	cin>>skrzynia;
	cout<<"podaj pojemnosc silnika"<<endl;
	cin>>skrzynia;
	cout<<"podaj moc silnika"<<endl;
	cin>>moc;
	
	wfun(autox, nazwa, model, rok_prod, skrzynia, pojemnosc, moc);
	
}
*/

void wyswietl(const sAuto autox){
	cout<<"nazwa samochodu: "<<autox.nazwa<<endl;
	cout<<"model samochodu: "<<autox.model<<endl;
	cout<<"rok produkcji samochodu: "<<autox.rok_prod<<endl;
	cout<<"rodzaj skrzyni biegow: "<<autox.skrzynia<<endl;
	cout<<"pojemnosc silnika: "<<autox.pojemnosc<<endl;
	cout<<"moc silnika: "<<autox.moc<<endl;
	}
/*
void wyswietl1(const sAuto& autox){
	cout<<"nazwa samochodu: "<<autox.nazwa<<endl;
	cout<<"model samochodu: "<<autox.model<<endl;
	cout<<"rok produkcji samochodu: "<<autox.rok_prod<<endl;
	cout<<"rodzaj skrzyni biegow: "<<autox.skrzynia<<endl;
	cout<<"pojemnosc silnika: "<<autox.pojemnosc<<endl;
	cout<<"moc silnika: "<<autox.moc<<endl;
	}
	*
void wyswietl(const sAuto* autox){
	cout<<"nazwa samochodu: "<<autox->nazwa<<endl;
	cout<<"model samochodu: "<<autox->model<<endl;
	cout<<"rok produkcji samochodu: "<<autox->rok_prod<<endl;
	cout<<"rodzaj skrzyni biegow: "<<autox->skrzynia<<endl;
	cout<<"pojemnosc silnika: "<<autox->pojemnosc<<endl;
	cout<<"moc silnika: "<<autox->moc<<endl;
	}
*/
int main(){
	
	string nazwa, model;
	int rok_prod, moc;
	char skrzynia;
	float pojemnosc;
	
	sAuto auto0;
	auto0 = wczytaj(inicjuj);
	wyswietl(auto0);
	/*
	sAuto& auto1 = auto0;
	inicjuj(auto1, "Dacia", "Sandero", 2008, 'm', 3.0, 81);
	wyswietl1(auto1);

	sAuto* auto2 = &auto1;
	inicjuj1(auto2, "Dacia", "Duster", 2020, 'm', 2.0, 100);
	wyswietl(auto2);
*/
	
	return 0;
	
	}
