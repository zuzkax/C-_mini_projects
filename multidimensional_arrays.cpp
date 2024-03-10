#include <iostream>
using namespace std;

int ** utworz(const int n, const int m){
    
    int ** t = new int * [n];
    
    for(int i=0; i<n; i++)

        t[i] = new int [m];

    for(int i=0; i<n; i++)

        for(int j=0; j<m; j++)

            t[i][j] = 0;
            
    return t;        
} 

void utworz(int **& t, const int n, const int m){

    t = new int * [n];

    for(int i=0; i<n; i++)

        t[i] = new int [m];

    for(int i=0; i<n; i++)
    
        for(int j=0; j<m; j++) 
        
            t[i][j]=0;
	
}

void utworzl(int** t, const int n, const int m){

    for(int i=0; i<n; i++)

        for(int j=0; j<m; j++) 
        
            t[i][j]=0;

}

void wypisz(const int * const *t, const int n, const int m){
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
            cout << t[i][j] << "\t";
        cout<<endl;    
        }
    cout<<endl;
}

void wypelnij(int ** t, const int n, const int m){
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>t[i][j];
    
}

void wypelnij(int **& t, const int n, const int m, int a, int b){
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            t[i][j] = a + rand() % abs(b - a + 1);
    
}

void usun(int **& t, const int n){
	if(t){
		for(int i = 0; i<n; i++)
			delete [] t[i];
			
		delete [] t;
		t = nullptr;	
	}
}


int main(){
    
    int n,m,a,b;
    
    cout<<"podaj n "<<endl;
    cin>>n;
    cout<<"podaj m "<<endl;
    cin>>m;
    cout<<"podaj a "<<endl;
    cin>>a;
    cout<<"podaj b "<<endl;
    cin>>b;
    
    int ** t1 = utworz(n,m);
    int ** t2 = nullptr;
    
    wypelnij(t1,n,m);
    cout<<"macierz wypelniona liczbami z klawiatury"<<endl;
    wypisz(t1,n,m);

    utworz(t2,n,m);   
    wypelnij(t2,n,m,a,b);  
    cout<<"wypelnienie liczbami losowymi"<<endl;
    wypisz(t2,n,m);
    
    usun(t1,n);
    usun(t2,n);

    return 0;
}
