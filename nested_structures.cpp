#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct SOsoba {
    int id;
    string email;
    int rokUrodzenia;
    string imie;
    
    SOsoba wczytaj(ifstream&);
    bool wypisz(SOsoba&, ostream&);
    void usun(SOsoba&);
};
  
struct SLista{
  string nazwa;
  int n;
  SOsoba* osoby; //wsk do tab dyn z osobami
  
  bool wczytaj(SLista&, ifstream&);
  bool wypisz(SLista&, ostream&);
  SOsoba szukaj(SLista&, const unsigned int);
  void podzial(SLista& , ofstream&, ofstream&);
  
  void usun(){//dlaczego tu nie ma parametrow
    if(osoby){
      delete [] osoby;
      osoby = nullptr;
    }
  }
  
};
SOsoba SOsoba::wczytaj(ifstream& fin){//co dokladnie znaczy ::
  SOsoba osoba = {0,"",0,""};//zerowanie
  if(!fin.good()){
    cerr<<"blad strumienia wejsciowego"<<endl;
    fin.clear();
    fin.ignore();
    fin.close();
    return osoba;
  }
  else{
    //PELNA DIAGNOSTYKA
    fin>>osoba.id;
    if(!fin.good()) {
      cerr << "Blad wczytywania id"<<endl;
      fin.ignore();
      fin.clear();
      fin.close();
      return osoba;
      }
      
    fin>>osoba.email;
    if(!fin.good()) {
      cerr << "Blad wczytywania email"<<endl;
      fin.ignore();
      fin.clear();
      fin.close();
      return osoba;
      }
      
    fin>>osoba.rokUrodzenia;
    if(!fin.good()) {
      cerr << "Blad wczytywania rokUrodznia"<<endl;
      fin.ignore();
      fin.clear();
      fin.close();
      return osoba;
      }
      
    fin>>osoba.imie;
    if(!fin.good()) {
      cerr << "Blad wczytywania imie"<<endl;
      fin.ignore();
      fin.clear();
      fin.close();
      return osoba;
      }
  }
  return osoba;
  
}
bool SOsoba::wypisz(SOsoba& o, ostream& out = cout){
//PELNA DIAGNOSTYKA
  if(!out.good()){
    cerr<<"blad strumienia wejsciowego"<<endl;
    out.clear();
    //out.close();
    return false;
  }
  out << o.id;
  if(!out.good()) {
    cerr << "Blad wypisywania id"<<endl;
    out.clear();
    return false;
    }
  out << o.email;
  if(!out.good()) {
    cerr << "Blad wypisywania email"<<endl;
    out.clear();
    return false;
    }
  out << o.rokUrodzenia;
  if(!out.good()) {
    cerr << "Blad wypisywania rokUrodzenia"<<endl;
    out.clear();
    return false;
    }
  out << o.imie;
  if(!out.good()) {
    cerr << "Blad wypisywania imie"<<endl;
    out.clear();
    return false;
    }
    return true;
  
}

bool SLista::wczytaj(SLista& l, ifstream& fin){
  if(!fin.good()){
    cerr<<"blad strumienia wejsciowego"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    l.usun();
    return false;
  }
  fin >> l.nazwa;
  if(!fin.good()){
    cerr<<"blad wczytywania nazwy listy"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    l.usun();//czy tutaj zawsze musi byc usuniecie?
    return false;
  }
  fin >> l.n;
  if(!fin.good()){
    cerr<<"blad wczytywania rozmiaru lisy"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    l.usun();
    return false;
  }
  if(l.n<=0){
    cerr<<"liczba osob musi byc wieksza od 0"<<endl;
    return false;
  }
  l.osoby = new SOsoba[l.n];
  
  for(int i = 0; i<n; i++){
    l.osoby[i] = l.osoby[i].wczytaj(fin);
  }
  return true;
  
}

bool SLista::wypisz(SLista& l, ostream& out = cout){
  if(!out.good()){
    cerr<<"blad strumiania wyjsciowego"<<endl;
    out.clear();
    return false;
  }
  out << l.nazwa <<endl;
  if(!out.good()){
    cerr<<"blad wpisywania nazwy listy"<<endl;
    out.clear();
    return false;
  }
  out << l.n <<endl;
  if(!out.good()){
    cerr<<"blad wpisywania wielkosci listy"<<endl;
    out.clear();
    return false;
  }
  for(int i = 0; i<n; i++){
    if(!(l.osoby[i].wypisz(l.osoby[i],out))){
      cerr<<"blad w petli wypisz"<<endl;
      out.clear();
      return false;
    }
  }
  return true;
}

SOsoba SLista::szukaj(SLista& l, const unsigned int id){
  SOsoba os = {0, "", 0, ""};
    for(int i=0; i<l.n; ++i) {
      if(l.osoby[i].id==id) {
        return l.osoby[i];
      }
    }
    return os;
}

void SLista::podzial(SLista& l, ofstream& fout_k, ofstream& fout_m){
  if(!(fout_k.good() && fout_m.good())) {
    cerr << "Blad strumieni wyjsciowych.\n";
    fout_k.clear();
    fout_k.close();
    fout_m.clear();
    fout_m.close();
    exit(0);
  }
  for(int i=0; i<l.n; ++i) {
    if(l.osoby[i].imie.back()=='a') {
      if(!(l.osoby[i].wypisz(l.osoby[i], fout_k))) {
	cerr << "Napotkano blad.\n";
        fout_k.clear();
	fout_k.close();
	exit(0);
      }
    } 
    else {
      if(!(l.osoby[i].wypisz(l.osoby[i], fout_m))) {
	cerr << "Napotkano blad.\n";
	fout_m.clear();
	fout_m.close();
  	exit(0);
      }
    }
  }
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "error" << endl;
        return -1;
    }
    
    ifstream wej(argv[1]);
    ofstream wyj_k(argv[2]);
    ofstream wyj_m(argv[3]);
    
    
    if(!(wej.good()) && !(wyj_k.good()) && !(wyj_m.good())) {
      cerr << "Strumienie plikowe nie zostaly otwarte\n";
      wej.clear();
      wej.ignore();
      wej.close();
      wyj_k.clear();
      wyj_k.close();	
      wyj_m.clear();
      wyj_m.close();
      return -1;
    }
    
    SLista lista;
    SOsoba osoba;
    
      if(lista.wczytaj(lista, wej)) {
        lista.wypisz(lista);
	osoba = lista.szukaj(lista, atoi(argv[4]));
	    if(osoba.id!=0) {
	      if(!osoba.wypisz(osoba)) {
		  cerr << "Napotkano blad podczas wypisywania danych osoby.\n";
		  lista.usun();
		  return -2;
	      }
	      lista.podzial(lista, wyj_k, wyj_m);
	    } 
	    else {
	      cerr << "Nie znaleziono osoby o podanym id.\n";
	      lista.usun();
	      return -3;
	    }
	    lista.usun();
      } 
      else {
	cerr << "Nastapil blad podczas wczytywania listy.\n";
	  wej.ignore();
	  wej.clear();
	  wej.close();
	  lista.usun();
	  return -4;
      }
	
      lista.usun();
	
      wej.close();
      wyj_k.close();
      wyj_m.close();
 
 return 0;
}
