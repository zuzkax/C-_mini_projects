#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

struct SOsoba{
  string imie, znak;
  int uro;
  int lucky_num;
  
  bool wczytaj(SOsoba&, ifstream&);
  bool wypisz(SOsoba& o, ostream&);
};

struct SLista{
  string nazwa;
  int n;
  SOsoba* osoby;
  
  bool wczytaj(SLista& l, ifstream& fin);
  bool wypisz(SLista& l, ostream&);
  SOsoba szukaj(SLista&, const string);
  void podzial(SLista&, ofstream&, ofstream&);
  void podzial(SLista&);
  
};
void zeruj(SOsoba& o){
  o.imie = "";
  o.znak = "";
  o.uro = 0;
  o.lucky_num = 0;
}

void usun(SLista& l){
  if(l.osoby){
    for(int i = 0; i<l.n; i++){
      zeruj(l.osoby[i]);
    }
    delete [] l.osoby;
    l.osoby = nullptr;
  }
  l.nazwa = "";
  l.n = 0;
}


bool SOsoba::wczytaj(SOsoba& o, ifstream& fin){
  if(!fin.good()){
    cerr<<"blad otwarcia pliku"<<endl;
    fin.clear();
    fin.close();
    fin.ignore();
    return false;
  }
  if(!(fin >> o.imie)){
    cerr<<"blad wczytania imienia"<<endl;
    fin.clear();
    fin.close();
    fin.ignore();
    return false;
  }
   if(!(fin >> o.uro)){
    cerr<<"blad wczytania roku urodzenia"<<endl;
    fin.clear();
    fin.close();
    fin.ignore();
    return false;
  }
   if(!(fin >> o.znak)){
    cerr<<"blad wczytania znaku"<<endl;
    fin.clear();
    fin.close();
    fin.ignore();
    return false;
  }
   if(!(fin >> o.lucky_num)){
    cerr<<"blad wczytania szczesliwej liczby"<<endl;
    fin.clear();
    fin.close();
    fin.ignore();
    return false;
  }
  return true;
}
  
bool SOsoba::wypisz(SOsoba& o, ostream& out = cout){
  if(!out.good()){
    cerr<<"blad strumienia wyjsciowego"<<endl;
    out.clear();
    return false;
  }
  if(!(out << o.imie<<'\t')){
    cerr<<"blad wypisywania imienia"<<endl;
    out.clear();
    return false;
  }
  if(!(out << o.uro<<'\t')){
    cerr<<"blad wypisywania roku urodzenia"<<endl;
    out.clear();
    return false;
  }
  if(!(out << o.znak<<'\t')){
    cerr<<"blad wypisywania znaku"<<endl;
    out.clear();
    return false;
  }
  if(!(out << o.lucky_num<<'\t')){
    cerr<<"blad wypisywania szczesliwej liczby"<<endl;
    out.clear();
    return false;
  }
  return true;
}

bool SLista::wczytaj(SLista& l, ifstream& fin){
  if(!fin.good()){
    cerr<<"blad otwarcia pliku"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    usun(l);
    return false;
  }
  if(!(fin>>l.nazwa)){
    cerr<<"blad wczytania nazwy listy"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    usun(l);
    return false;
  }
  if(!(fin>>l.n)){
    cerr<<"blad wczytania n listy"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    usun(l);
    return false;
  }
    if(l.n >0){
      osoby = new SOsoba[l.n];
      
      for(int i = 0; i<l.n; i++){
        if(!(l.osoby[i].wczytaj(l.osoby[i],fin))){
          cerr<<"blad wczytania elementu listy osob "<<endl;
          fin.ignore();
          fin.clear();
          fin.close();
          usun(l);
          return false;
        }
      }
    }
     return true; 
}

bool SLista::wypisz(SLista& l, ostream& out = cout){
  if(!out.good()){
    cerr<<"blad otwarcia pliku wyjsciowego"<<endl;
    out.clear();
    return false;
  }
  if(!(out << l.nazwa<<endl)){
    cerr<<"blad wypisania nazwy listy"<<endl;
    out.clear();
    return false;
  }
  if(!(out << l.n<<endl)){
    cerr<<"blad wypisania n listy"<<endl;
    out.clear();
    return false;
  }
  if(l.n > 0){
    for(int i = 0; i<l.n; i++){
      if(!(l.osoby[i].wypisz(l.osoby[i],out))){
        cerr<<"blad wypisywania elementu listy osoby"<<endl;
        out.clear();
        return false;
      }
    }
  }
  return true;
}

SOsoba SLista::szukaj(SLista& l, const string zoo){
  SOsoba * zo = &l.osoby[0];
  for(int i = 0; i<l.n ; i++){
    if(l.osoby[i].znak == zoo){
      zo = &l.osoby[i];
    }
  }
  return *zo;
}

void SLista::podzial(SLista& l){
  for(int i = 0; i<l.n; i++){
    if(l.osoby[i].lucky_num %2 == 0){
      l.osoby[i].wypisz(l.osoby[i]);
    }
  }
}

void SLista::podzial(SLista& l, ofstream& k, ofstream& m){
  if(!(k.good() && m.good())){
    cerr<<"blad strumeni wyjsciowych"<<endl;
    k.clear();
    k.close();
    m.clear();
    m.close();
    exit(0);
  }
  else{
    for(int i = 0; i<l.n; i++){
      if(l.osoby[i].imie.back() == 'a'){
        if(!(l.osoby[i].wypisz(l.osoby[i], k))){
          k.clear();
          k.close();
          exit(0);
        }
      }
      else{
        if(!(l.osoby[i].wypisz(l.osoby[i], m))){
          m.clear();
          m.close();
          exit(0);
        }
      }
    }  
  }
}

int main(int argc, char ** argv){
  if(argc != 5){
    cerr<<"<UZYCIE>"<<endl;
    return -1;
  }

  ifstream wej(argv[1]);
  ofstream wyj_k(argv[2]);
  ofstream wyj_m(argv[3]);
  string zoodiak = argv[4];
 
  if(!(wej.good() && wyj_k.good() && wyj_m.good())){
    cerr<<"strumienie plikowe nie zostaly otwarte"<<endl;
    wej.ignore();
    wej.clear();
    wej.close();
    wyj_k.clear();
    wyj_k.close();
    wyj_m.clear();
    wyj_m.close();
    return -1;
  }
    
  SLista lista = {"",0,nullptr}; //zeby nie bylo wyciekow przy zepsuciu wej.txt
  SOsoba osoba = {"","",0,0};
 
 if(lista.wczytaj(lista,wej)){
  lista.wypisz(lista); //wypisanie na std wyjsciu
  osoba = lista.szukaj(lista, zoodiak);
  if(!(osoba.wypisz(osoba))){
    cerr<<"blad podczas wypisywania danych osobt"<<endl;
    wej.ignore();
    wej.clear();
    wej.close();
    wyj_k.clear();
    wyj_k.close();
    wyj_m.clear();
    wyj_m.close();
    usun(lista);
    return -2;
  }
  lista.podzial(lista, wyj_k, wyj_m);
  lista.podzial(lista);
 }
 else{
  cerr<<"blad wczytywania"<<endl;
  wej.ignore();
  wej.clear();
  wej.close();
  wyj_k.clear();
  wyj_k.close();
  wyj_m.clear();
  wyj_m.close();
  usun(lista);
  return -3;
 }
  wej.ignore();
  wej.clear();
  wej.close();
  wyj_k.clear();
  wyj_k.close();
  wyj_m.clear();
  wyj_m.close(); 
  
  usun(lista);
  return 0;
}
