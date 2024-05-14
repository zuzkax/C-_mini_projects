#include <iostream>
#include <cstdlib> 
//#include <ctime>  
using namespace std;

struct SWielomian {
    int stopien;
    float* wspolczynniki;
};

float losuj(const float min, const float max){
  return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

float* wspolczynniki(SWielomian& w, const unsigned int stopien = 1, const double min = -5.5, const double max = 5.5){
  
  if (stopien < 0) {
        cerr << "Stopien wielomianu musi byc liczba naturalna"<<endl;
        return nullptr;
    }
  w.stopien = stopien;
  w.wspolczynniki = new float[stopien+1];
  
  for (int i = 0; i <= stopien; i++){
        w.wspolczynniki[i] = losuj(min, max);
    }
  return w.wspolczynniki;
}

void wypisz(const float w, const unsigned i){//wypisuje i-ty wyraz wielomianu
  if (i == 0) {
    cout<<w;
  }else {
    cout << w << "x^" << i;
    }
}

void wypisz(const SWielomian& w){
  for(int i =0; i<=w.stopien; i++){
    wypisz(w.wspolczynniki[i],i);
    cout<<'\t';
  }
  cout<<endl;
}

float wartosc_wielomianu(const SWielomian& w, const float x) {
    float wynik = 0.0;
    for (int i = w.stopien; i >= 0; --i) {
        wynik = wynik * x + w.wspolczynniki[i];
    }
    return wynik;
}


void usun(float *&tab){
  if(tab){
    delete [] tab;
    tab = nullptr;
  }
}

int main(int argc, char **argv){
  
  if(argc != 3){
    cerr<<"error"<<endl;
    return -1;
  }
  SWielomian w;
  int stopien = atoi(argv[1]);
  float x = atof(argv[2]);
  float wartosc = 0;
  
  if(argc == 5){
    float min = atoi(argv[3]), max = atoi(argv[4]);
    if(min < 0 && max > 0 && stopien > 1){
      wspolczynniki(w, stopien, min, max);
      wartosc = wartosc_wielomianu(w, x);
      cout << "Wartosc wielomianu stopnia " << w.stopien - 1 << " dla x = " << x<<"wynosi: " << wartosc << endl;
      wypisz(w);//wypisuje caly wielomain
    }
  }else{
    cout << "Podano zla wartosc min, max lub stopien. ";
    cout << "Wartosc wielomianu wyliczona zostaje " << "dla argumentow domyslnych" << endl;
    cout << "stopien = 1, min = -5.5, max = 5.5" << endl;
    wspolczynniki(w);
    wartosc = wartosc_wielomianu(w, x);
    cout << "Wartosc wielomianu stopnia " << w.stopien - 1 << " dla x = " << x << " wynosi: " << wartosc << endl;
    wypisz(w);
  }
  
  usun(w.wspolczynniki);

  return 0;
}

