#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include <ctime>
#include <time.h>
#include <windows.h>
#include <chrono>
using namespace std;


class Lista{	
	//zmienne
	public:
	int data;
	Lista *next;
	Lista *myHead;


void display(Lista *head){	//funkcja, ktora pokazuje elementy listy
	Lista * p=head;		//zmienna pomocnicza 
	while(p!=NULL){
		cout<<p->data<<endl;
		p=p->next;				//pokazywanie wartosci kazdego wskaznika i inkrementacja 
		cout<<"\n";
	}
	delete p;	//zwolnienie pamieci
}
Lista *popfront( Lista * head){
	if(head!=NULL){
	
	Lista *temp=head;		//zmienna pomocnicza 
	if(temp){
		head=temp->next;	// g³owa wskazuje na nastêpny element
	delete temp;		//zwolnienie pamieci
	}
	return head;
	
}
else{					//funkcja dodaje element na poczatku listy ,zwalnia pamiec i wskazuje na glowe
		return head;

}
		
}
Lista *popvalue(Lista *head, int val){	//funkcja usuwa podana wartosc i wskazuje na glowe
	Lista *p =find(head, val);	//sprawdza czy wartosc jest na liscie
	
	if(p==head){
	p=popfront(head);				//usuwa glowe jesli p==head
}else{
	Lista * temp=head;
	if(p!=NULL){
		Lista * pprev, *pnext;
		while(temp!=NULL){		
		if(temp->next==p){		
			pprev=temp;				//sprwdzenie gdzie jest p i zapisanie wczesniejszego elementu
			break;
		}
		else{
			temp=temp->next;	
		}
	}
		delete temp;			//zwolnienie pamieci
		pnext=p->next;			//przypisanie nastepnej wartosci od p do pnext
		if(pprev!=NULL){
			pprev->next=pnext;		//usuniecie p i wskazanie na pnext przez pprev
	}
		if(pnext!=NULL){
			
			pprev->next=pnext;
		}
		delete p;			//zwolnienie pamieci
		return head;

	}else{
		delete p;		//zwolnienie pamieci
		return head;
	}
	

}
}
Lista* swapvalue(Lista*head, int oldval, int newval){
	Lista *p=find(head, oldval);			//sprawdzanie wartosci 
	if(p!=NULL){
		p->data=newval;		//zamiana wartosci
		
		return head;
	}else{
		Lista * newHead= new Lista;
		newHead =pushfront(head,newval);	//dodanie z przodu elementu
		return newHead;
	}
}
Lista * find(Lista*head, int val){
	while(head!=NULL){
		if(head->data==val){		//funkcja szuka wartossci na liscie
			return head;
		}
		else{
			head=head->next;
		}
	}
	return NULL;			//zwraca NULL jesli nie znajdzie
}
Lista * popback( Lista *head){
	
Lista *p=head;

if(p!=NULL){
	if(p->next!=NULL){
	while(p->next->next!=NULL)p=p->next;			
	delete p->next;					//funkcja usuwa ostatni element znajdujacy sie na liscie
	p->next=NULL;							
	
}else{
	delete p;					
	head=NULL;					
	
}
return head;
}
else {

return head;
}
	
}
	


Lista  *pushfront(Lista *head, int val){

	Lista * newHead= new Lista;
	newHead->data=val;			//przypisanie wartosci nowemu elementowi
	newHead->next=head;			//przypisanie nastepnego wskaznika
	return newHead;

}
Lista * pushback(Lista *head, int val){


Lista *p, *e;			
e=new Lista;
e->next=NULL;
e->data=val;
p=head;
if(p!=NULL){
	while(p->next)p=p->next;
	p->next=e;				//dodaje na nastepny element wskaznik e;
	
	return head;
}
else {
head=pushfront(head,val);	//dodaje z przodu listy
delete e;		//zwolnienei pamieci
delete p;
return head;
}
}

int  amountOfList(Lista*head){	//funkcja liczy ilosc elementow w liscie
	Lista * temp=head;
	int licznik=0;
	while(temp){		
			licznik++;		//inkrementacja licznika
		temp=temp->next;	//przejscie na nastepny element
	
	}
	delete temp;		//zwolnienie pamieci
	return licznik;
}
Lista * popInPlace(Lista *head){
	srand( time( NULL ) );
	
	int amo=amountOfList(head);		
	int index;
	if(amo>0)
		index= rand() % amo+1;	//losowanie liczby z przedzialu [1,amo]
	
	if(index<=amo&&index>0){
	
	Lista * p=head;
			if(index == 1){
			head=popfront(head);	//jesli index==1 usuwa glowe
  				}else
 			 {
		
		Lista * pprev, *pnext;
		while(index>=2){
			if(p->next!=NULL){
			pprev=p;		//szuka p i wczesniejszego wskaznika
			p=p->next;
		}
			index--;
		}
		
		pnext=p->next;		
		delete p;			// zwolnienie pamieci
		if(pprev!=NULL){				
			pprev->next=pnext;			//wskaznik pprev na nastepny element pokazuje na pnext
	}
		

}
		
	}else{
		cout<<"Nie ma takiego miejsca na liscie!\n";
	}
	
	return head;
}
Lista * pushInPlace(Lista *head,int val){
	srand( time( NULL ) );
	int index;
	int amo=amountOfList(head);		

	
	index= rand() % (amo+1)+1;			//losuje liczbe z przedzialu [1,amo+1]

	if(index==(amo+1)){
		head=pushback(head,val);	//dodaje z tylu jesli amo+1==index
	}else if(index==1){
		head=pushfront(head,val);		//dodaje z przodu jesli index==1
	}else {
	
		Lista * p=head;
		Lista *newAdd=new Lista;			//nowy wskaznik ktory dodajemy
	
		Lista * pprev, *pnext;
		while(index>=2){
			if(p->next!=NULL){
			pprev=p;
			p=p->next;
		}								//szuka wskaznika p i wczesniejszego
			index--;
		}
		newAdd->next=p;			//przypisanie nasteppnego wskaznika
		pprev->next=newAdd;		//przypisanie nastepnego wskaznika dla pprev
		newAdd->data=val;		//przypisanie wartosci dla nowego wskaznika
			
		}
	
	

	return head;
}

Lista * readFile(Lista * head){
	int ile;
clock_t start, stop;
double czas;
	string file_name;
		cout<<"Podaj nazwe pliku: ";
		cin>>file_name;
		string linia;
		ifstream plik;
		
	plik.open(file_name.c_str());		//nazwa pliku ktory zostanie wczytany
	if(plik.good()==true){
		getline(plik,linia);			//wczytuje dlugosc 
		int length=atoi(linia.c_str());
		
		
		Lista*newHead=NULL;
		int licznik=0;
	
			while(!plik.eof()){		//petla do konca pliku
		
			getline(plik,linia);
		
			newHead=newHead->pushfront(newHead,atoi(linia.c_str()));	//dodaje na koniec listy 
			
			licznik++;
      if(licznik>=length){
      	break;
	  }
		}


	
	
		return newHead;	
		plik.close();			//zamyka plik
	}else {
		cout<<"Niepoprawna nazwa pliku\n";
		return head;
	}
	
	
}
};

 class Tablica{
	public:
	int n=0;
	int * t=new int [n];

	
	void pushbackTab(int val){
	
	
		int * nowa = new int[ n + 1 ];
       
        						
        for( int i = 0; i < n; ++i ) //kopiowanie danych
			  nowa[ i ] = t[ i ];
       
        // Dodawanie  nowej wartoœci
      
   		nowa[ n] = val;
        // Usuwanjie starej tablicy
        delete[] t;
       
        				// Zaktualizowanie zmiennych
        t = nowa;
        n++;		//rozmiar++;
		
}
void pushInPlaceTab(int valAdd,int index){
	
	if(index>n+1||index<=0){
		cout<<"Nie ma takiego miejsca na tablicy\n";
}else{

	int * nowa = new int[ n + 1 ];
       
        // kopiowanie danych
         
        for( int i = 0; i < n; ++i ){
		if(i+1>=index){
		nowa[ i+1 ] = t[ i ];
	}else{
		
			  nowa[ i ] = t[ i ];
   
   }
}
        	// przypisanie nowej wartosci
      
   		nowa[index-1] = valAdd;
       			// Usuwanie starej tablicy
        delete[] t;
       
        // aktualizowanie zmienne
        t = nowa;
        n++;
	
}
	
	
}
void pushRandTab(int valAdd){
	srand( time( NULL ) );
	int index= rand() % (n)+1;		//losowanie numeru
	cout<<"index "<<index<<endl;
	pushInPlaceTab(valAdd,index);		//wywolanie funkcji dodawwania i przekazanie numeru wylosowanego
	
}
void popRandTab(){
	
	srand( time( NULL ) );
	int index= rand() % (n+1)+1;	//	losowanie numeru	

	popInPlaceTab(index);			//wywolanie funkcji dodawwania i przekazanie numeru wylosowanego
}


void pushfrontTab(int val){
	
	
		int * nowa = new int[ n + 1 ];
       
        					// kopiowanie danych
         
        for( int i = 0; i < n; ++i )
			  nowa[ i+1 ] = t[ i ];
       
        						// dodawanie nowej wartosci
      
   		nowa[0] = val;
        			// Usuwanie starej tablicy
        delete[] t;
       
        // aktualizowanie 
        t = nowa;
        n++;
        //rozmiar++;
		
}
void popfrontTab(){
	
	if(n>0){
	
		int * nowa = new int[ n - 1 ];
       
        // kopiowanie danych
         
        for( int i = 0; i < n; ++i )
			 
			 
			  nowa[ i ] = t[ i+1 ];	//przypisanie wartosci o miejsce wyzej i pominiecie pierwszego elementu
       
       
      
   		
        delete[] t;
       
         // aktualizowanie
        t = nowa;
        n--;	//rozmiar--
    }else cout<<"Tablica jest pusta\n";
       
		
}
void popValue(int val){
	bool inTab=false;
        
         
        	for(int i=0;i<n;i++){
		
			  if(t[i]==val){								//sprawdza czy wartosc jest w tablicy
			  	inTab=true;
			  	popInPlaceTab(i+1);
			  	break;	
			  }
   } if(!inTab){			
	   
			  		cout<<"Nie ma takiej wartosci w tablicy.\n";
			  		
			  }
}
void popbackTab(){
	
	if(n>0){
	
		int * nowa = new int[ n - 1 ];
       
        
         
        for( int i = 0; i < n-1; ++i )	//kopiowanie danych do momentu n-1, pominiecie ostatniego elementu
			 
			 
			  nowa[ i ] = t[ i ];
       
        
        // Usuwanie starej tablicy
        delete[] t;
       
        				// aktualizacja danych
        t = nowa;
        n--;	//dekrementacja rozmiaru
    }else cout<<"Tablica jest pusta\n";
        
		
}
	
	
void popInPlaceTab(int index){
	
	if(n>0&&index<=n){
	
		int * nowa = new int[ n - 1 ];
       
        
         
        for( int i = 0; i < n; ++i )
			 
			if(i>=index-1){					//jesli i =rowna sie index-1 to przypisuje wartosci o jedna wyzej ze starej tablicy 
				nowa[ i ] = t[ i+1 ];
			} else{
			
			
			  nowa[ i ] = t[ i ];			
   }
        
        delete[] t;
       
        
        t = nowa;	//przypisanie nowej tablicy
        n--;
    }else cout<<"Tablica jest pusta\n";
	
	
}
	void displayTab(){
		for(int i=0;i<n;i++){
			cout<<t[i]<<endl;			//wyswietlanie kolejnych elementow tablicy
		}
	}
	
	void readFileTab(){
		string file_name;
		cout<<"Podaj nazwe pliku: ";
		cin>>file_name;
		string linia;
		ifstream plik;
		
	plik.open(file_name.c_str());
	
	if(plik.good()==true){
	
		getline(plik,linia);
		int length=atoi(linia.c_str());
		
		n=0;		//wyzerowanie talicy
		int licznik=0;
		while(!plik.eof()){
		
        
        getline(plik,linia);
        
      pushbackTab(atoi(linia.c_str()));
      licznik++;
      if(licznik>=length){
      	break;
	  }
		}
	
		plik.close();		//zamkniecie pliku
	}
	else{cout<<"Nie znaleziono plikku\n";
	}
	}
void findInTab(int val){
	

       bool inTab=false;
        
         
        	for(int i=0;i<n;i++){
		
			  if(t[i]==val){								//sprawdza czy wartosc jest w tablicy
			  	cout<<"Podana wartosc znajduje sie na liscie.\n";
			  	inTab=true;
			  	break;	
			  }
   }
       if(!inTab){			
	   
			  		cout<<"Nie znaleziono wartosci w tablicy.\n";
			  		
			  }
}
	
};
class Kopiec{	//klasa kopca
	public: 
	
	int n=0;
	int *k=new int[n];         	//tablica kopca              
	
	void pushKop(int val){
			int * nowa = new int[ n + 1 ];
       
        // kopiowanie danych
         
        for( int i = 0; i < n; ++i )
			  nowa[ i ] = k[ i ];
       
        // dodawawnie nowej wqartosciæ
      
   		
   		int i,j;
		i=n;					
		j=(i-1)/2;						//indeks rodzica
		while(i > 0 && nowa[j] < val)
  	{	
    	nowa[i] = nowa[j];
    	i = j;							//sortowanie kopca
    	j = (i - 1) / 2;				
  	}
  	nowa[i]=val;					//przypisanie wartosci
        
        delete[] k;			//usuniecie starego
       
        			// aktualizacja zmiennych
        k = nowa;
        n++;
        			//rozmiar++;
        
	}
void popKop(int val){
		bool inKop=false;
     int index;
	 for(int i=0;i<n;i++){
	 	if(k[i]==val){
	 		inKop=true;
	 		index=i;
			 break;
	 		
		 }
	 }
	 if(inKop){
	 
    if(n--){
       
        
        
	int valLast = k[n];			//przypisanie wartosci ostatniego elementu
	
    int i = index;		//zmienne pomocnicze
    int j = 2*index+1;		
	
    while(j < n)
    {
      if(j + 1 < n && k[j + 1] > k[j]) 		//warunki inkrementacji
	  {
	  j++;						//inkrementacja obecnego
  }
	  if(valLast >= k[j]) break;	//jesli wartosc wieksza od wartosci potomka przerywa petle
      k[i] = k[j];			
      i = j;				//aktualny index
      j = 2 * j + 1;		//przejscie na potomka lewego
    }

    k[i] = valLast;			//przypisaie wartosci
}
}
else 
{	cout<<"Nie ma takiej wartosci w kopcu\n";
}
}
/*
void displayKop(){	//moja wersja
	int m=1;
		int licznik=0;
		int licznikT=0;
		int iloscTab=n/2;
		bool przejscie=true;
		for(int i=0;i<n;i++){
			
	
			cout<<k[i];
			licznik++;			//pokazywanie kopca
			cout<<"\t";
			if(m==licznik)	
			{	
				cout<<endl;			
				licznik=0;		//zmienne pomocnicze ktore pokazuja ile moze byc w danej linii elementow
			przejscie=true;
			cout<<endl;
				m=m*2;			
			}
			
			
		}
		cout<<endl;*/
void printBT(string sp, string sn, int v)//gotowe pokazywania kopca jak jest dozwolone
{
  string s;
	string cr,cl,cp;
	cr = cl = cp = "  ";
  cr[0] = 218; cr[1] = 196;
  cl[0] = 192; cl[1] = 196;
  cp[0] = 179;		
  if(v < n)
  {
    s = sp;
    if(sn == cr) s[s.length() - 2] = ' ';
    printBT(s + cp, cr, 2 * v + 2);

    s = s.substr(0,sp.length()-2);

    cout << s << sn << k[v] << endl;

    s = sp;
    if(sn == cl) s[s.length() - 2] = ' ';
    printBT(s + cp, cl, 2 * v + 1);
  }
}
	

	
	
	void findInKop(int val){
		
       bool inKop=false;		
        
         
        	for(int i=0;i<n;i++){
		
			  if(k[i]==val){								//sprawdza czy wartosc jest w tablicy
			  	cout<<"Podana wartosc znajduje sie na liscie.\n";
			  	inKop=true;
			  	break;	
			  }
   }
       if(!inKop){			
	   
			  		cout<<"Nie znaleziono wartosci w tablicy.\n";
			  		
			  }
	}
	void readFileKop(){
		string file_name;
		cout<<"Podaj nazwe pliku: ";
		cin>>file_name;
		string linia;
		ifstream plik;
		
	plik.open(file_name.c_str());
	if(plik.good()==true){
	
		getline(plik,linia);
		int length=atoi(linia.c_str());
		
		n=0;		//wyzerowanie tanlicy
		int licznik=0;
		while(!plik.eof()){
			int a;
			
			int * nowa = new int[ n+1];		//pomocnicza tablica
	
		for(int i=0;i<n;i++){
		
		 nowa[ i ] = k[ i ];		//przepisanie
   }
        
        getline(plik,linia);
        
        
        int i,j;
		i=n;
		j=(i-1)/2;
		while(i > 0 && nowa[j] < atoi(linia.c_str()))
  	{	
    	nowa[i] = nowa[j];
    	i = j;
    	j = (i - 1) / 2;
  	}
        
         nowa[i]=atoi(linia.c_str());	//przypisanie wartosci z pliku
      
        delete[] k;			//zwolnienie pamieci
       
        k = nowa;		//przypisanie tablicy
        n++;
		licznik++;
     	 if(licznik>=length){
      	break;
	  }
		}
		
			plik.close();		//zamkniecie pliku
	}
	else{cout<<"Nie znaleziono pliku\n";
	}
	}
	
	
};

string structuresOptions= "1. Lista \n2. Tablica \n3. Kopiec binarny \n4. Drzewo binarne \n0. Wyjscie\n";
string optionsMenu ="1. Zbuduj z pliku \n2. Usun\n3. Dodaj\n4. Znajdz\n5. Wyswietl\n0. Wyjscie\n";
string addMenu="1. Dodaj z przodu\n2. Dodaj na koncu\n3. Dodaj w losowym miejscu\n4. Dodaj konkretna wartosc.";
string addMenuTab="1. Dodaj z przodu\n2. Dodaj na koncu\n3. Dodaj w wybranym miejscu\n4. Dodaj konkretna wartosc w losowym miejscu.";
string diffrenceMenu="1. Usun z przodu\n2. Usun z koñca.\n3. Usun w losowym miejscu\n4. Usun konkretna wartosc.";
string diffrenceMenuTab="1. Usun z przodu\n2. Usun z koñca.\n3. Usun w wybranym miejscu\n4. Usun w losowym miejscu.\n5. Usun po wartosci.\n";
void structureMenu();
void operationMenu();

int main(){
	
	

	structureMenu();
	return 0;
}
void structureMenu(){			//menu aplikacji
	
	int a,x;

Lista *listka=NULL;
Lista *findHelp=NULL;
Tablica tabka;
Kopiec kopiec;
while(true){

	
	cout<<"------------------"<<endl;
	cout<<"MENU"<<endl;
	cout<<structuresOptions<<endl;
	cout<<"Wybierz strukture: ";		
	cin>>a;
	
	switch(a){
				
			
		case 1:		
		int lis;
		while(true){
		cout<<"------------------"<<endl;
		cout<<"MENU OPCJI"<<endl;
		cout<<optionsMenu;
		cout<<"Wybierz opcje: ";
		cin>>lis;
	switch(lis){
	
		case 1: 
		listka=listka->readFile(listka);
		break;
		case 2: 
		int bf;
		cout<<diffrenceMenu<<endl;
		int valDif;
		cout<<"Gdzie chcesz usunac liczbe: ";
		cin>>bf;
		switch(bf){
			
		case 1:
			
			
			listka=listka->popfront(listka);
					break;
		case 2: 
				
			listka=listka->popback(listka);
			break;	
			case 3: 
			listka=listka->popInPlace(listka);
			break;
			case 4: cout<<"Podaj wartosc ktora chcesz usunac: ";
			cin>>valDif;
			listka=listka->popvalue(listka, valDif);
			 break;
			default: structureMenu(); break;
				}
				
			break;
		case 3:
		int bs; 
		cout<<addMenu<<endl;
		int valAdd;
		cout<<"Gdzie chcesz dodac liczbe: ";
		cin>>bs;
		switch(bs){
			
		case 1:
			
			cout<<"Podaj wartosc do listy: ";
			cin>>valAdd;
			listka=listka->pushfront(listka,valAdd);
					break;
		case 2: 
				cout<<"Podaj wartosc do listy: ";
			cin>>valAdd;
		
			listka=listka->pushback(listka,valAdd);
			break;	
			case 3:
			cout<<"Podaj wartosc do listy: ";
			cin>>valAdd;
			listka=listka->pushInPlace(listka,valAdd);
			break;
			case 4: 
			int oldVal;
			cout<<"Podaj wartosc za ktora chcesz zamienic: ";
			cin>>oldVal;
			cout<<"Podaj nowa wartosc: ";
			cin>>valAdd;
			listka=listka->swapvalue(listka,oldVal,valAdd);
			break;
			default: structureMenu(); break;
				}
				break;
			case 4:
				
				int valFind;
				cout<<"Podaj wartosc jaka chcesz poszukac: ";
				cin>>valFind;
				findHelp=listka->find(listka,valFind);
				if(findHelp!=NULL){
					cout<<"Podana wartosc znajduje sie na liscie\n";
				}
				else{
					cout<<"Podana wartosc nie znajduje sie na liscie\n";
				}
				break;
			case 5:
			listka->display(listka);
			break;
			case 0: structureMenu(); break;
			default: cout<<"Wprowadzono niepoprawne dane, sprobuj jeszcze raz\n";
			structureMenu(); break;
		}
		}break;
	
	case 2:
		int b;
		while(true){
		cout<<"------------------"<<endl;
		cout<<"MENU OPCJI"<<endl;
		cout<<optionsMenu;
		cout<<"Wybierz opcje: ";
		cin>>b;
		switch(b){
		
		case 1: 
		tabka.readFileTab();
		break;
		case 2: 
		int bf;
		cout<<diffrenceMenuTab<<endl;
		int valDif;
		cout<<"Gdzie chcesz usunac liczbe: ";
		cin>>bf;
		switch(bf){
			
		case 1:
			
			tabka.popfrontTab();
		
					break;
		case 2: 
				
			tabka.popbackTab();
			break;	
			case 3: int index;
			cout<<"Podaj miejsce ktore chcesz usunac: ";
			cin>>index;
			tabka.popInPlaceTab(index);
			break;
			case 4: tabka.popRandTab();
			 break;
			 case 5: 
			 int valDif;
			cout<<"Podaj jaka wartosc chesz usunac: ";
			cin>>valDif;
			tabka.popValue(valDif);
			break;
			default: structureMenu(); break;
				}
				
			break;
		case 3:
		int bs; 
		cout<<addMenuTab<<endl;
		int valAdd;
		cout<<"Gdzie chcesz dodac liczbe: ";
		cin>>bs;
		switch(bs){
			
		case 1:
			
			cout<<"Podaj wartosc do tablicy: ";
			cin>>valAdd;
			tabka.pushfrontTab(valAdd);
		
					break;
		case 2: 
				cout<<"Podaj wartosc do listy: ";
			cin>>valAdd;
		tabka.pushbackTab(valAdd);
		
			break;	
			case 3:
			int index;
			cout<<"Podaj miejsce w ktorym chcesz dodac wartosc: ";
			cin>>index; 
			cout<<"Podaj wartosc: ";
			cin>>valAdd;
			tabka.pushInPlaceTab(valAdd,index);
			break;
			case 4: 
			
			cout<<"Podaj nowa wartosc: ";
			cin>>valAdd;
			tabka.pushRandTab(valAdd);
			break;
			default: structureMenu(); break;
				}
				break;
			case 4:
				
				int valFind;
				
				cout<<"Podaj wartosc jaka chcesz poszukac: ";
				cin>>valFind;
				tabka.findInTab(valFind);
			
		
				break;
			
			case 5:
			
			tabka.displayTab();
			break;
			case 0: structureMenu(); break;
			default: cout<<"Wprowadzono niepoprawne dane, sprobuj jeszcze raz\n";
			structureMenu(); break;
	}
}
	break;
	case 3:
		int c;
		while(true){
		cout<<"------------------"<<endl;
		cout<<"MENU OPCJI"<<endl;
		cout<<optionsMenu;
		cout<<"Wybierz opcje: ";
		cin>>c;
		switch(c){
		
		case 1: 
		
		kopiec.readFileKop();
		break;
		case 2: 
		int valDif;
		cout<<"Jaka liczbe chcesz usunac: ";
		cin>>valDif;
		kopiec.popKop(valDif);
		break;
		case 3:
	
		int valAdd;
		cout<<"Jaka liczbe chcesz dodac: ";
		cin>>valAdd;
		kopiec.pushKop(valAdd);
				break;
		case 4:
				
			int valFind;
				
				cout<<"Podaj wartosc jaka chcesz poszukac: ";
				cin>>valFind;
				kopiec.findInKop(valFind);
			
		
				break;
			
			case 5:
			
			kopiec.printBT("","",0);
			break;
			case 0: structureMenu(); break;
			default: cout<<"Wprowadzono niepoprawne dane, sprobuj jeszcze raz\n";
			structureMenu(); break;
	}
	}
	break;
	case 0: exit(123);break;
	}
}
	}
