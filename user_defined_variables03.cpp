#include<iostream>
#include<cmath>
using namespace std;

struct SPunkt{
  float x;
  float y;
};
struct SProsta{
  float a;
  float b;
};
struct SOkrag{
  float a;
  float b;
  float r;
};
struct SRownanie{
  float a;
  float b;
  float c;
};

int rozw_rown(const SRownanie& r, SPunkt& p1, SPunkt& p2){
  float delta = r.b*r.b-4*r.a*r.c;
  if(delta>0){
  
    p1.x = (-r.b + sqrt(delta)) / (2 * r.a);
    p2.x = (-r.b - sqrt(delta)) / (2 * r.a);
    p1.y = p2.y = 0; 
    
    return 2; 
  }
  else if(delta == 0){
  
    p1.x = -r.b/(2 * r.a);
    p2.x = -r.b/(2 * r.a);
    p1.y = 0;
    p2.y = 0;
    
    return 1;
  }
  else return 0;
}

int pkt_przec(const SProsta& p, const SOkrag& o, SPunkt& p1, SPunkt& p2){
  SRownanie r;
  r.a = 1 + p.a * p.a;
  r.b = 2 * (p.a * (p.b - o.b) - o.a);
  r.c = o.b * o.b - o.r * o.r + o.a * o.a - 2 * o.a * p.b;
  return rozw_rown(r,p1,p2);
}

bool czy_prostopadle(const SProsta& p1, const SProsta& p2){
  if(p1.a == p2.a) return true;
  else return false;
}

int main(){
  SPunkt p1 = {0, 0}, p2 = {0, 0};
  SProsta prosta1 = {-1.0, 3.0};
  SProsta prosta2 = {1.0, -3.0};
  SOkrag okrag = {0.0, 1.0, 2.0};

  int d1 = pkt_przec(prosta1, okrag, p1, p2);
  if(d1 == 2) {
        cout << "Prosta przecina okrąg w punktach: " << endl;
        cout << "(" << p1.x << ", " << p1.y << ")" << endl;
        cout << "(" << p2.x << ", " << p2.y << ")" << endl;
    } else if(d1 == 1) {
        cout << "Prosta jest styczna do okręgu w punkcie: " << endl;
        cout << "(" << p1.x << ", " << p1.y << ")" << endl;
    } else if(d1 == 0) {
        cout << "Prosta nie przecina okręgu" << endl;
    } else {
        cout << "Brak rozwiązania - to nie jest równanie kwadratowe";
    }
    
    cout << "Czy proste sa prostopadle? " << boolalpha << czy_prostopadle(prosta1, prosta2) << endl;
    return 0;
}
