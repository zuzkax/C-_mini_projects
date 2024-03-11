#include<iostream>
using namespace std;

bool bialy_znak(char znak){
	if(znak == ' ' || znak == '\t' || znak == '\n' || znak == '\r'){ //std::isspace
		return true;
	}
	else{
		return false;
		
	}
}

int liczba_wyrazow(const char * zdanie){
	int liczba_wyrazow = 0;
	
	while(*zdanie){
		while(*zdanie && bialy_znak(*zdanie)){
			zdanie ++;	
		}
		if(*zdanie) {
			liczba_wyrazow++;	
		}
		while(*zdanie && !bialy_znak(*zdanie)){
			zdanie++;
		}
		
	}
	return liczba_wyrazow;
	
}

int main(int argc, char * argv[]){
	
	const char * zdanie = argv[1];
	
	cout<<liczba_wyrazow(zdanie)<<endl;
	
	return 0;
}
