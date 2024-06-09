#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct SStudent{
	string imie,nazwisko;
	int num_in, l_ocen;
	float * wykaz;
	
	bool wczytaj(ifstream&);
	bool wypisz(ostream& );
	
  SStudent() : imie(""), nazwisko(""), num_in(0), l_ocen(0), wykaz(nullptr){
    cout<<"konstruktor"<<endl;
  }
  ~SStudent() {
    if(wykaz){
      delete [] wykaz;
      wykaz = nullptr;
    }
    cout<<"destruktor studenta"<<endl;
  }
	};
	
struct SLista{
	string nazwa;
	int l_studentow;
	SStudent * wykaz;
	
	bool wczytaj(ifstream&);
	bool wypisz(ostream&);
	double srednia();
	
  SLista() : nazwa(""), l_studentow(0), wykaz(nullptr){
    cout<<"konstruktor listy"<<endl;
  }
  ~SLista(){
    if(wykaz){
      delete [] wykaz;
      wykaz = nullptr;
    }
  cout<<"destruktor listy"<<endl;
  }
	};

bool SStudent::wczytaj(ifstream& fin){
	if(!fin.good()){
		cerr<<"blad strumienia wejsciowego"<<endl;
		fin.ignore();
		fin.clear();
		fin.close();
		return false;
		}
	
	if(!(fin>>imie)){
		cerr<<"blad wczytania imienia"<<endl;
		fin.ignore();
		fin.clear();
		fin.close();
		return false;
		}
	if(!(fin>>nazwisko)){
		cerr<<"blad wczytania nazwiska"<<endl;
		fin.ignore();
		fin.clear();
		fin.close();
		return false;
		}
	if(!(fin>>num_in)){
		cerr<<"blad wczytania numeru indeksu"<<endl;
		fin.ignore();
		fin.clear();
		fin.close();
		return false;
		}
	if(!(fin>>l_ocen)){
		cerr<<"blad wczytania liczby ocen"<<endl;
		fin.ignore();
		fin.clear();
		fin.close();
		return false;
		}
	if(l_ocen>0){
		wykaz = new float[l_ocen];
		
		for(int i =0; i<l_ocen; i++){
			if(!(fin>>wykaz[i])){
				cerr<<"blad wczytania oceny w petli"<<endl;
				fin.ignore();
				fin.clear();
				fin.close();
				delete [] wykaz;
				wykaz = nullptr;
				return false;
			}
		}
	}
	return true;
    	
}
bool SStudent::wypisz(ostream& out = cout){
	if(!out.good()){
		cerr<<"blad strumienia wyjsciowego"<<endl;
		out.clear();
		return false;
		}
	if(!(out<<imie<<'\t')){
		cerr<<"blad wypisywania imienia"<<endl;
		out.clear();
		return false;
		}
	if(!(out<<nazwisko<<'\t')){
		cerr<<"blad wypisywania nazwiska"<<endl;
		out.clear();
		return false;
		}
	if(!(out<<num_in<<'\t')){
		cerr<<"blad wypisywania numeru indeksu"<<endl;
		out.clear();
		return false;
		}
	if(!(out<<l_ocen<<'\t')){
		cerr<<"blad wypisywania liczby studentow"<<endl;
		out.clear();
		return false;
		}
	if(l_ocen > 0){
		for(int i = 0; i<l_ocen; i++){
			if(!(out<<wykaz[i]<<'\t')){
				cerr<<"blad wypisywania oceny w petli"<<endl;
				out.clear();
				return false;			
				}
			}
		
		}
		if(!(out<<endl)){
			cerr<<"blad wypisywania endl"<<endl;
			out.clear();
			return false;
		}
			
	
		return true;
	
	}
	
bool SLista::wczytaj(ifstream& fin){
	if(!fin.good()){
		cerr<<"blad strumienia wejsciowego"<<endl;
		fin.ignore();
		fin.clear();
		fin.close();
		return false;
		}
	
	if(!(fin>>nazwa)){
		cerr<<"blad wczytania nazwy listy"<<endl;
		fin.ignore();
		fin.clear();
		fin.close();
		return false;
		}
	if(!(fin>>l_studentow)){
		cerr<<"blad wczytania liczby studentow"<<endl;
		fin.ignore();
		fin.clear();
		fin.close();
		return false;
		}

	if(l_studentow>0){
		wykaz = new SStudent[l_studentow];
		
		for(int i = 0; i<l_studentow; i++){
			if(!(wykaz[i].wczytaj(fin))){
				cerr<<"blad wczytania studenta w petli"<<endl;
				fin.ignore();
				fin.clear();
				fin.close();
				delete [] wykaz;
				wykaz = nullptr;
				return false;
			}
		}
	}
	return true;
	
	}	
bool SLista::wypisz(ostream& out = cout){
	if(!out.good()){
		cerr<<"blad strumienia wyjsciowego"<<endl;
		out.clear();
		return false;
		}
	if(!(out<<nazwa<<endl)){
		cerr<<"blad wypisywania nazwy listy"<<endl;
		out.clear();
		return false;
		}
	if(!(out<<l_studentow<<endl)){
		cerr<<"blad wypisywania liczby studentow"<<endl;
		out.clear();
		return false;
		}
	if(l_studentow > 0){
		for(int i = 0; i<l_studentow; i++){
			if(!(wykaz[i].wypisz(out))){
				cerr<<"blad wypisywania studentow w petli"<<endl;
				out.clear();
				return false;			
				}
			}
		
		}
		return true;
	}
double SLista::srednia(){
	int suma = 0;
	int liczba = l_studentow;
	
	for(int i = 0; i<l_studentow; i++){
	    if(wykaz[i].wykaz != nullptr){
		for(int j = 0; j<wykaz[j].l_ocen; j++){
			if(wykaz[i].wykaz[j] == 5.0){
				suma += 1;
				}
			}
      
		}
	
	}
	return static_cast<double>(suma)/ static_cast<double>(liczba);
}
	
int main(int argc, char** argv){
	
	if(argc != 2){
		cerr<<"nieprawidlowa ilosc argumentow"<<endl;
		cerr<<"uzycie; <nazwa programu> <plik wejsciowy>"<<endl;
		return -1;
	}
	
	ifstream wej(argv[1]);
	
	if(!wej.good()){
		cerr<<"blad otwarcia pliku wejsciowego"<<endl;
		wej.ignore();
		wej.clear();
		wej.close();
		return -2;
		}
	
	SLista lista ;
	
	if(!(lista.wczytaj(wej))){
		cerr<<"blad wczytania danych"<<endl;
		wej.ignore();
		wej.clear();
		wej.close();
		return -3;
		}
	if(!(lista.wypisz())){
		cerr<<"blad wypisania danych"<<endl;
		wej.ignore();
		wej.clear();
		wej.close();
		return -3;
		}
	cout<<"srednia ilosc ocen bdb wsrod studentow: "<< lista.srednia()<<" jest zatrwazajaco duza"<<endl;
		
	
	return 0;
	}
