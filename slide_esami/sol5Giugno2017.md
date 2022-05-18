1. Presentate le principali funzioni per la gestione della memoria dinamica in C
```c
void *calloc (size_t nobj, size_t size)
```
-> Calloc ritorna un puntatore a spazio per un array di nobj oggetti, tutti di grandezza size, oppure NULL se la richiesta non puo' essere soddisfatta. Lo spazio e' inizializzato a 0.
---
```c
void *malloc(size_t size)
```
-> Malloc ritorna un puntatore a spazio per un oggetto di grandezza size, oppure NULL se la richiesta non puo' essere soddisfatta. Lo spazio e' inizializzato.
---
```c
void free(void *p)
```
-> Free dealloca lo spazio puntato dal puntatore p, se p e' NULL non fa niente. P deve essere spazio allocato precedentemente da calloc, malloc o realloc.

2. Definite una macro scambio(a,b) da utilizzare per scambiare il contenuto di 2 variabili a e b di tipo int
```c
#define scambio(a,b) {int tmp = a; a = b; b = tmp;}
```
3. Definte una funzione che riceve in ingresso una stringa(vettore di caratteri) e restituisce la somma delle lunghezze di tutte le stringhe su cui e' stata chiamata
```c
int conta(char *s){
	static int count = 0;
	while(*s != '\0') {count++; s++;}
	return count;
}
```

4. Data la seguente dichiarazione(punti a coordinate intere in uno spazio n-dimensionale)
```c++
class nDPoint{
	int *p;
	int dim;
public:
	nDPoint(int n){p = new int[n]; dim = n;}
	~nDPoint(){delete[] p;}
};
```
Effettuate l'overloading di << in modo che se punto corrisponde a (a1, a2, ..., a_n) l'istruzione
```c++
std::cout punto;
```
stampi "[a1, a2, ...,a_n]"

```c++
friend ostream& operator<<(ostream& os, const nDPoint& c);

ostream& operator<<(ostream& os, const nDPoint& c){
	os << "[";
	for(int i = 0; i < c.dim; i++)
		os << c.p[i] << ", ";
	os << "]";
	return os;
}
```

5. Date le 4 classi seguenti
```c++
class A{
public:
	virtual void f(){std::cout << "f di A\n";};
	virtual void g(){std::cout << "g di A\n";};
};
class B: virtual public A{
public:
	 virtual void f(){std::cout << "f di B\n";};
};
class C: virtual public A{
public:
	virtual void g(){
		std::cout << "g di C\n";
	}
};
class D: public B, protected C{
public:
	virtual void f(){std::cout << "f di D\n";}
};
A *pA;
C *pC;
A a;
C c;
D d;
```
Spiegate quale sarebbe l'effetto dell'esecuzione delle seguenti istruzioni:
```c++
pA = &d;
pA->f();
pA->g();
```
D eredita in maniera pubblica da B, che a sua volta eredita in maniera pubblica da A. Di conseguenza si puo' assegnare l'indirizzo della classe D a un puntatore di classe A.
viene eseguita la f() della classe D perche' riscritta nella classe D
viene eseguito la g() della classe C perche' D eredita in maniera protetta la classe C
---
```c++
pC = &d;
pC->f();
```
D non rispetta l'interfaccia di C(eredita in modalita' protetta), si ha errore di compilazione
---
```c++
d.g();
```
D eredita C in maniera protetta, d.g() causa errore di compilazione perche' g() e' protetta in D: la versione presente in A non e' piu' accessibile

6. Illustrate l'ordine in cui vengono chiamati i costruttori coinvolti nella creazione di un oggetto di una classe C che eredita da una classe B, la quale eredita da una classe  A.
A()->B()->C()










