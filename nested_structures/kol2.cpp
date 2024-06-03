#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct SMieszkanie{
  int num, pok;
  float pow, wys;
  
  bool wczytaj_M(ifstream& , SMieszkanie&);
  bool zapisz(ostream&, const SMieszkanie&);
};

struct SPietro{
  int num, l_mieszkan;
  SMieszkanie * opis;
  
  bool wczytaj_P(ifstream&, SPietro&);
  bool zapisz(ostream&, const SPietro*);
  
};

struct SKlatka{
  int num, l_pieter;
  SPietro * opis;
  
  bool wczytaj_K(ifstream& , SKlatka&);
  bool zapisz(ostream&, const SKlatka*);
};

struct SBlok{
  int num, l_klatek;
  string ul;
  SKlatka * opis;
  
  bool wczytaj(ifstream& ,const string, SBlok&);
  bool zapisz(ostream&, const SBlok*);
};

void usun(SPietro& p){
  if(p.opis){
    delete [] p.opis;
    p.opis = nullptr;
    } 
    p.num = 0;
    p.l_mieszkan = 0;
}
void usun(SKlatka& k){
  if(k.opis){
    for(int i = 0; i<k.l_pieter; i++){
      usun(k.opis[i]);
    }
    delete [] k.opis;
    k.opis = nullptr;
  }
  k.num = 0;
  k.l_pieter = 0;
}

void usun(SBlok& b){
  if(b.opis){
    for(int i = 0; i<b.l_klatek; i++){
      usun(b.opis[i]);
    }
    delete [] b.opis;
    b.opis = nullptr;
  }
  b.ul = "";
  b.num = 0;
  b.l_klatek = 0; 
}

bool SMieszkanie::wczytaj_M(ifstream& fin, SMieszkanie& m){
  if(!fin.good()){
    cerr<<"blad otwarcia pliku wejsciowego"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    //usun(m);
    return false;
  }
  if(!(fin>>m.num)){
    cerr<<"blad wczytania numeru mieszkania"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    //usun(m);
    return false;
  }
  if(!(fin>>m.pow)){
    cerr<<"blad wczytania powierzchni mieszkania"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
   // usun(m);
    return false;
  }
  if(!(fin>>m.wys)){
    cerr<<"blad wczytania wysokosci mieszkania"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    //usun(m);
    return false;
  }
  if(!(fin>>m.pok)){
    cerr<<"blad wczytania liczne pokoi"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    //usun(m);
    return false;
  }
  return true;
}

bool SPietro::wczytaj_P(ifstream& fin, SPietro& p){
  if(!fin.good()){
    cerr<<"blad otwarcia pliku wejsciowego"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    usun(p);
    return false;
  }
  if(!(fin>>p.num)){
    cerr<<"blad wczytania numeru mieszkania"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    usun(p);
    return false;
  }
  if(!(fin>>p.l_mieszkan)){
    cerr<<"blad wczytania numeru mieszkania"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    usun(p);
    return false;
  }
  if(p.l_mieszkan >0){
    p.opis = new SMieszkanie[p.l_mieszkan];
    for(int i = 0; i< p.l_mieszkan; i++){
      if(!(p.opis[i].wczytaj_M(fin, p.opis[i]))){
        cerr<<"blad wczytania mieszkania w peltli"<<endl;
        fin.ignore();
        fin.clear();
        fin.close();
        usun(p);
        return false;      
      }
    }
  }
  return true;
}

bool SKlatka::wczytaj_K(ifstream& fin, SKlatka& k){
  if(!fin.good()){
    cerr<<"blad otwarcia pliku wejsciowego"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    usun(k);
    return false;
  }
  if(!(fin>>k.num)){
    cerr<<"blad wczytania numeru klatki"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    usun(k);
    return false;
  }
    if(!(fin>>k.l_pieter)){
    cerr<<"blad wczytania liczby klatek"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    usun(k);
    return false;
  }
  if(k.l_pieter >0){
    k.opis = new SPietro[k.l_pieter];
    
    for(int i = 0; i< k.l_pieter; i++){
      if(!(k.opis[i].wczytaj_P(fin, k.opis[i]))){
        cerr<<"blad wczytania pietra w peltli"<<endl;
        fin.ignore();
        fin.clear();
        fin.close();
        usun(k);
        return false;      
      }
    }
  }
  return true;
}

bool SBlok::wczytaj(ifstream& fin ,const string nazwa, SBlok& b){
  if(!fin.good()){
    cerr<<"blad otwarcia pliku wejsciowego"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    usun(b);
    return false;
  }
  if(!(fin>>b.ul)){
    cerr<<"blad wczytania ulicy"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    usun(b);
    return false;
  }
  if(!(fin>>b.num)){
    cerr<<"blad wczytania numeru bloku"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    usun(b);
    return false;
  }
  if(!(fin>>b.l_klatek)){
    cerr<<"blad wczytania liczby klatek"<<endl;
    fin.ignore();
    fin.clear();
    fin.close();
    usun(b);
    return false;
  }
  if(b.l_klatek >0){
    b.opis = new SKlatka[b.l_klatek];
    
    for(int i = 0; i<l_klatek; i++){
      if(!(b.opis[i].wczytaj_K(fin, b.opis[i]))){
        cerr<<"blad wczytywania klatki w pwtli"<<endl;
        fin.ignore();
        fin.clear();
        fin.close();
        usun(b);
        return false;
      }
    }  
  }
  return true;
}

bool SMieszkanie::zapisz(ostream& out, const SMieszkanie& m){
  if(!out.good()){
    cerr<<"blad otwarcia strumienia wyjsciowego"<<endl;
    out.clear();
    return false;
  }
  if(!(out << m.num << '\t')){
    cerr<<"blad zapisywania numeru mieszkania"<<endl;
    out.clear();
    return false;
  }
  if(!(out << m.pow << '\t')){
    cerr<<"blad zapisywania powierzchni mieszkania"<<endl;
    out.clear();
    return false;
  }
  if(!(out << m.wys << '\t')){
    cerr<<"blad zapisywania wysokosci mieszkania"<<endl;
    out.clear();
    return false;
  }
  if(!(out << m.pok << endl)){
    cerr<<"blad zapisywania liczby pokoi"<<endl;
    out.clear();
    return false;
  }
  return true;
}

bool SPietro::zapisz(ostream& out, const SPietro* p){
  if(!out.good()){
    cerr<<"blad otwarcia strumienia wyjsciowego"<<endl;
    out.clear();
    return false;
  }
  if(!(out << p->num << '\t')){
    cerr<<"blad zapisywania numeru pietra"<<endl;
    out.clear();
    return false;
  } 
  if(!(out << p->l_mieszkan<< endl)){
    cerr<<"blad zapisywania liczby mieszkan"<<endl;
    out.clear();
    return false;
  }
  if(p->l_mieszkan>0){
    for(int i = 0; i<p->l_mieszkan; i++){
      if(!(out <<p->opis[i].zapisz(out,p->opis[i]))){
        cerr<<"blad zapisywania mieszkania w petli"<<endl;
        out.clear();
        return false;
      }
    }
  }
  return true;
}
bool SKlatka::zapisz(ostream& out, const SKlatka* k){
  if(!out.good()){
    cerr<<"blad otwarcia strumienia wyjsciowego"<<endl;
    out.clear();
    return false;
  }
  if(!(out << k->num << '\t')){
    cerr<<"blad zapisywania numeru klatki"<<endl;
    out.clear();
    return false;
  } 
  if(!(out << k->l_pieter<< endl)){
    cerr<<"blad zapisywania liczby pieter"<<endl;
    out.clear();
    return false;
  }
  if(k->l_pieter>0){
    for(int i = 0; i<k->l_pieter; i++){
      if(!(out <<k->opis[i].zapisz(out,&k->opis[i]))){
        cerr<<"blad zapisywania pieter w petli"<<endl;
        out.clear();
        return false;
      }
    }
  }
  return true;
}
bool SBlok::zapisz(ostream& out, const SBlok* b){
  if(!out.good()){
    cerr<<"blad otwarcia strumienia wyjsciowego"<<endl;
    out.clear();
    return false;
  }
  if(!(out << b->ul << '\t')){
    cerr<<"blad zapisywania ulicy bloku"<<endl;
    out.clear();
    return false;
  } 
  if(!(out << b->num << endl)){
    cerr<<"blad zapisywania numeru bloku"<<endl;
    out.clear();
    return false;
  } 
  if(!(out << b->l_klatek<< endl)){
    cerr<<"blad zapisywania liczby klatek"<<endl;
    out.clear();
    return false;
  }
  if(b->l_klatek>0){
    for(int i = 0; i<b->l_klatek; i++){
      if(!(out <<b->opis[i].zapisz(out,&b->opis[i]))){
        cerr<<"blad zapisywania klatek w petli"<<endl;
        out.clear();
        return false;
      }
    }
  }
  return true;
}

float wysokosc_pietra(const SPietro& p){
  float max_wys = 0.0;
  for(int i = 0; i<p.l_mieszkan; i++){
    if( max_wys < p.opis[i].wys){
      max_wys = p.opis[i].wys;
    }
  }
  return max_wys;
}

float wysokosc_klatki(const SKlatka& k){
  float wysokosc = 0.0;
  for(int i = 0; i< k.l_pieter; i++){
    wysokosc += wysokosc_pietra(k.opis[i]);
  }
  return wysokosc;
}
float wysokosc_bloku(const SBlok& b){
  float wysokosc = 0.0;
  
  for(int i = 0; i<b.l_klatek; i++){
    if(wysokosc < wysokosc_klatki(b.opis[i])){
      wysokosc = wysokosc_klatki(b.opis[i]);
    }
  }
  return wysokosc;
}


int main(int argc, char ** argv){

  if(argc != 3){
    cerr<<"<UZYCIE>"<<endl;
    return -2;
  }

  ifstream wej(argv[1]);
  ofstream wyj(argv[2]);
  
  if(!(wyj.good() || wej.good())){
    cerr<<"blad otwarcia strumieni plikowych"<<endl;
    wej.ignore();
    wej.clear();
    wej.close();
    wyj.clear();
    wyj.close();
    return -1;
  }
  
  SBlok blok = {0,0,"",nullptr};
  
  if(!(blok.wczytaj(wej, "nazwa",blok))){//po co ta nazwa ??
    cerr<<"blad wczytywania danych"<<endl;
    wej.ignore();
    wej.clear();
    wej.close();
    wyj.clear();
    wyj.close();
    usun(blok);
    return -3;
  }
  if(!(blok.zapisz(cout, &blok))){
    cerr<<"zapisywanie na std wyjsciu nie powiodlo sie"<<endl;
    wej.ignore();
    wej.clear();
    wej.close();
    wyj.clear();
    wyj.close();
    usun(blok);
    return -4;
  }
  if(!(blok.zapisz(wyj,&blok))){
    cerr<<"zapisywanie do pilku nie powiodlo sie"<<endl;
    wej.ignore();
    wej.clear();
    wej.close();
    wyj.clear();
    wyj.close();
    usun(blok);
    return -5;
  }
  
  cout<<"wysokosc bloku = "<< wysokosc_bloku(blok)<<endl;
  
  for(int i = 0;i<blok.l_klatek; i++){
    cout<<"dla klatki "<< i+1 <<"wysokosc = "<<wysokosc_klatki(blok.opis[i]) << endl;
    for(int j = 0; j<blok.opis[i].l_pieter; j++){
      cout<<"dla pietra "<<j+1 << " w klatce "<< i + 1<<"wysokos =  "<<wysokosc_pietra(blok.opis[i].opis[j])<< endl;
    }
  }
  
  usun(blok);
  return 0;
}
