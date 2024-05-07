#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

struct SProstopadloscian{
  float d;
  float s;
  float h;
};

SProstopadloscian* wczytaj(const char* plik_wej, int& n){
  
  ifstream fin(plik_wej);//tworzenie strumienia plikowego do odczytu o nazwie fin
  if(!fin.good()){
    cerr<<"blad otwarcia pliku"<<endl;
    fin.clear();
    fin.ignore();
    fin.close();
    return nullptr;
  }
  else{
    fin >> n;
    if(n <= 0){
      cerr<<"n musi byc wieksze od 0";
      return nullptr;
    }
    else{
      SProstopadloscian* prostopadlosciany = new SProstopadloscian[n]; //tablica dynamiczna z obiektami
      
      for(unsigned int i = 0; i<n; i++){
        fin >> prostopadlosciany[i].d >>   prostopadlosciany[i].s >>   prostopadlosciany[i].h;
      }
      return prostopadlosciany;
    }
    fin.clear();
    fin.ignore();
    fin.close();
  } 
}

float pole(const SProstopadloscian* p){
  return p->d*p->s*2 + p->h*p->d*2 + p->h*p->s*2;
}

int znajdz_pole(const SProstopadloscian* p, const int n){
  int polee = 0;
  for(unsigned int i = 0; i<n; i++){
    if(polee < pole(&p[i])){
      polee = pole(&p[i]);
    }
  }
  return polee;
}

float objetosc(const SProstopadloscian& p){
  return 
}

void wypisz(const SProstopadloscian* p){
  cout<< p->d <<'\t' << p->s <<'\t' << p->h << endl;
}

int main(int argc, char ** argv){

  if(argc != 2){
    cerr<<"nieprawidłowa liczba argumentow";
    return -1;
  }
  //const char* plik_wej = argv[1];
  int n = 0;
  
  SProstopadloscian* p = wczytaj(argv[1], n);
  if(p){
    wypisz(p);
    cout<<znajdz_pole(p,n);
}
  
  
  return 0;
}
