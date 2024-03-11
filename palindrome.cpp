#include<iostream>
#include<cstring>
#include <cctype>
using namespace std;


bool palindrom( const char * zdanie){
	//usuwanie znakow spec i bialych
	
	int len = strlen(zdanie);
	int index = 0;
	
	char * nowe_zdanie = new char[len];
	
	for(int i=0; i<len; i++){
		if(isalnum(zdanie[i])){//isalnum sprawdza czy znak jest alfanumeryczny
			nowe_zdanie[index++] = tolower(zdanie[i]);
		}
		
	}
	//czy palindrom
	int len_nowe = strlen(nowe_zdanie);
	int i = 0;
	int j = len_nowe -1; // -1 bo '\0'
	
	while(i<j){
		if(nowe_zdanie[i] != nowe_zdanie[j]){
			return false;
		}
		else{
			i++;
			j--;
		}
	}
	delete [] nowe_zdanie;
	nowe_zdanie = nullptr;
	return true;
}

int main(int argc, char * argv[]){
	
	const char * zdanie = argv[1];
  
	bool wynik = palindrom(zdanie);
	
	if(wynik){
	  cout<<"podane zdanie jest palindrom"<<endl;
	}
	else{
	  cout<<"podane zdanie nie jest palindrom"<<endl;
	}
  
	
	return 0;
}
