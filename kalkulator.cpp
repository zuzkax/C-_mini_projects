#include <cmath>
#include <iostream>
using namespace std;


double suma(double a, double b){
	return a+b;

}

double roznica(double a, double b){
	return a-b;

}
double iloczyn(double a, double b){
	return a*b;

}

double iloraz(double a, double b){

	if(b==0){
		cout<<"error: dzielenie przez 0"<<endl;
		return NAN;
	}
	else{
		return a/b;
	}
}

double kwadrat(double a){
	return a*a;

}

double szescian(double a){
	return a*a*a;

}

double obw_trojkata(double a, double b, double c){
	if(a+b>c && a+c>b && c+b>a){
		return a+b+c;
	}
	else{
		cout<< "error: nie da sie zbudowac trojkata"<<endl;
		return NAN;
	}

}

double pole_trojkata(double a, double b, double c){
	if(a+b>c && a+c>b && c+b>a){
		double s = obw_trojkata(a,b,c)/2;
		return sqrt(s*(s - a)*(s - b)*(s - c));
	}
	else{
		cout<< "error: nie da sie zbudowac trojkata"<<endl;
		return NAN;
	}

}

bool kalkulator() {
    
    cout<<"----------- KALKULATOR -----------"<<endl;
    cout<<"------ MENU ------"<<endl;
    cout<<"wybierz numer"<<endl;
    cout<<"1. oblicz sume"<<endl;
    cout<<"2. oblicz roznice"<<endl;
    cout<<"3. oblicz iloczyn"<<endl;
    cout<<"4. oblicz iloraz"<<endl;
    cout<<"5. oblicz kwadrat"<<endl;
    cout<<"6. oblicz szescian"<<endl;
    cout<<"7. oblicz obwod trojkata"<<endl;
    cout<<"8. oblicz pole trojkata"<<endl;
    cout<<"9. zakoncz program"<<endl;
    

    int nr;
    cin>>nr;
    double a,b,c,output;
    
    switch(nr){
    
    	case 1:
    		cout<<"podaj pierwsza liczbe";
    		cin>>a;
    		cout<<"podaj druga liczbe";
    		cin>>b;
    		output = suma(a,b);
    		break;
    		
    	case 2:
    		cout<<"podaj pierwsza liczbe";
    		cin>>a;
    		cout<<"podaj druga liczbe";
    		cin>>b;
    		output = roznica(a,b);
    		break;
    		
    	case 3:
    		cout<<"podaj pierwsza liczbe";
    		cin>>a;
    		cout<<"podaj druga liczbe";
    		cin>>b;
    		output = iloczyn(a,b);
    		break;
    		
    	case 4:
    		cout<<"podaj dzielna";
    		cin>>a;
    		cout<<"podaj dzielnik";
    		cin>>b;
    		output = iloraz(a,b);
    		break;
    
 	case 5:
    		cout<<"podaj  liczbe";
    		output = kwadrat(a);
    		break;
    		
    	case 6:
    		cout<<"podaj liczbe";
    		cin>>a;
    		output = szescian(a);
    		break;
    		
    	case 7:
    		cout<<"podaj pierwszy bok";
    		cin>>a;
    		cout<<"podaj drugi bok";
    		cin>>b;
    		cout<<"podaj trzeci bok";
    		cin>>c;
    		output = obw_trojkata(a,b,c);
    		break;
    	
    	case 8:
    		cout<<"podaj pierwszy bok";
    		cin>>a;
    		cout<<"podaj drugi bok";
    		cin>>b;
    		cout<<"podaj trzeci bok";
    		cin>>c;
    		output = pole_trojkata(a,b,c);
    		break;
    	
    	case 9:
    		cout<<"zakonczono program"<<endl;
    		return false;
    		
    	default:
    		cout<<"wynrales numer operacji ktory nie istnieje w menu"<<endl;
    		return true;
    }   
    cout<<"wynik:  "<< output<<endl;
    return true;   
}

	
	

int main(){

    while(kalkulator());
    return 0;
}
