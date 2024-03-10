#include <iostream>
using namespace std;

int * utworz( const int n){

    int * t = new int [n];

    for(int i=0; i<n; i++)       
    	t[i]=0;
	
    return t;
}


void wypelnij(int * t, const int n, int a, int b){
    
    for(int i=0; i<n; i++)
	t[i] = a + rand() % abs(b - a + 1);
    
}
void wypisz(int * t, const int n){

	for(int i=0; i<n; i++)
		cout<<t[i]<<"\t";
}


int dziel(int * t, int l, int p){

	int pivot = t[p];
	int i = l - 1;
	
	for(int j = l; j<p; j++){
		if(t[j] <= pivot){
		      i++;
		      swap(t[i],t[j]);		
		}
	}
	
	swap(t[i+1], t[p]);
	return i+1;
}

void quick_sort(int * t, int l, int p) {
    if (l < p) {
        int pivot_index = dziel(t, l, p);

        quick_sort(t, l, pivot_index - 1);
        quick_sort(t, pivot_index + 1, p);
    }
}

void usun(int *& t){

	if(t){
		delete[] t;
		t = nullptr; 
	}
}

int main() {

    int n = 9;
    int a,b;

    int * t = utworz(n);
    
    cout<<"podaj zakres od"<<endl;
    cin>>a;
    cout<<"do"<<endl;
    cin>>b;
    
    wypelnij(t,n,a,b);
    wypisz(t,n);
    
    cout<<endl;
    
    quick_sort(t,0,n-1);
    wypisz(t,n);
    
    usun(t);


    return 0;
}
