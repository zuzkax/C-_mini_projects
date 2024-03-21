#include<iostream>
#include<cstring>
#include<string>
using namespace std;

void kopiuj1(const string src, char *& dest){
  int n = src.size();
  dest = new char[n+1];
  src.copy(dest,n);
  dest[n] = '\0';
}

void kopiuj2(const char* src, string & dest, size_t n){
  dest = src;
  dest.erase(0,n);
}

string kopiuj3(const string src, size_t n){
  string dest = src;
  dest.erase(0,n);
  return dest;
}

void usun(char *& tab){
  if(tab){
    delete [] tab;
    tab = nullptr;
  }
} 
int poz(const string src, const char* str){
  return src.find(str);
}

int poz2(const string src, const string str){
  return src.find(str);
}

int porownaj(const string str1, const string str2){
  if(str1 < str2){
    return -1;
  }
  else if(str1> str2){
    return 1;
  }
  else{
    return 0;
  }
}

int main(int argc, char * argv[]){
  if(argc < 6){
    cerr<<"nieprawidlowa liczba argumentow"<<endl;
    cerr<<"Użyj: nazwa_programu <string0> <n> <string1> <string2> <szukany znak>"<<endl;
    return -100;
  }
  
  const char * src = argv[1];
  size_t n = atoi(argv[2]);
  const string str1 = argv[3];
  const string str2 = argv[4];
  const char* str = argv[5];
  
  
  char * dest;
  kopiuj1(src, dest);
  cout<<"sprawdzenie kopiuj1:  "<<dest<<endl;
  
  usun(dest);
  
 
  string dest_2; 
  dest_2 = src;
  cout<<"kopiowanie '=': "<<dest_2<<endl;
  
  
  string str3;
  str3 = str1 + str2;
  cout<<str3<<endl;
  
  
  kopiuj2(src, dest_2, n);
  cout<<"sprawdzenie kopiuj2:  "<<dest_2<<endl;
  
 
  const string src_5 = src;
  cout<<"sprawdzenie kopiuj3: "<<kopiuj3(src_5,n)<<endl;
  
 
  cout<<"sprawdzenie poz: "<<poz(src, str)<<endl;
  
 
  cout<<"sprawdzenie poz2: "<<poz(src, str)<<endl;
  

  cout<<"sprawdzenie porownaj:  "<<porownaj(str1,str2)<<endl;
  
  return 0;
}
