#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct SOsoba {
    int id;
    string email;
    int rokUrodzenia;
    string imie;
  };
  
SOsoba wczytaj(ifstream& fin){
  SOsoba osoba;
  if(!fin.good()){
    cerr<<"blad otwarcia pliku"<<endl;
    fin.clear();
    fin.ignore();
    fin.close();
    return nullptr;
  }
  else{
    fin>>osoba.id >> osoba.email >> osoba.rokUrodzenia >> osoba.imie;
    fin.clear();
    fin.ignore();
    fin.close();
    return osoba;
  }
  
}
bool wypisz(SOsoba& o, ostream& out = cout){
  if(!out.good()){
    cerr<<"blad wpisywania od  pliku"<<endl;
    out.clear();
    out.close();
    return false;
  }
  else{
    out << o.id << " " << o.email << " " << o.rokUrodzenia << " " << o.imie << endl;
    out.clear();
    out.close();
    return true;
  }
}

struct SLista{
  int n;
  SOsoba* osoby; //wsk do tab dyn z osobami
};

bool wczytaj(SLista& l, ifstream& fin){
  if(wczytaj(fin)){
    fin >> l.n;
    for(int i = 0; i<n; i++){
      
    }
  }

}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "error" << endl;
        return -1;
    }
    
    ifstream wej(argv[1]);
    ofstream wyj(argc[2]);
    
    
    if(wej.good() && wyj.good()) {
    //sprawdzanie działania
		
		wej.clear();
		wej.ignore();
		wej.close();
		
		wyj.clear();
		wyj.close();
	} else {
		cerr << "Strumienie plikowe nie zostaly otwarte\n";
		
		wej.clear();
		wej.ignore();
		wej.close();
		
		wyj.clear();
		wyj.close();
		
		return -1;
	}
 
 return 0;
}
