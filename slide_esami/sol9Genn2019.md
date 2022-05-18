1. Presentate le principali funzioni che il C offre per la gestione dei file.

---
2. Cosa fa il preprocessore? Mostrate e commentate le direttive che ritenete piu significative.
Il c fornisce alcune feature attraverso il preprocessore, che non e' nient'altro che un primo step nella compilazione.
Le 2 direttive piu' frequentemente usate sono #include e #define

#include: viene usata per includere i contenuti di un file durante la compilazione
esempio:
```c
#include <stdio.h>
//include la libreria stdio.h che e' la responsabile della gestione dell
//input e dell'output
```

#define: viene usato per per rimpiazzre un token con una arbitraria sequenza di caratteri
```c
#define MAX 100
int numbers[MAX];
int x = MAX;
//ogni volta che compare MAX verra' sostituita nella prima fase di compialazione da 100
```
---
3. Scrivete una funzione miamal che assegna un blocco di un KB di memoria dinamica al puntatore costituente l’unico parametro, e che restituisce un intero che rappresenta il numero di KB allocati fino a quel momento. La funzione deve permettere al massimo l’allocazione di 100 blocchi (alla richiesta del 101-esimo blocco il puntatore risultera nullo).

```c
#include <stdlib.h>
#define KB 1024

int miamal(int *ptr){
	static size_t count = 0;
	if(count < 100){
		ptr = (int *) malloc(sizeof(int) * KB);
		count++;
	}else{
		ptr = NULL;
	}
	return count;
}
```
---
4. Cosa si intende per conflitto in una gerarchia di classi? Esiste una tecnica automatica per la risoluzione dei conflitti? Come si comporta C++ al riguardo?

5. Quali sono le parole chiave utilizzate per il controllo della visibilita degli elementi di una classe? Costruite una tabella che presenti tutte le combinazioni (e il loro significato) in abbinamento con le diverse modalita di derivazione.

6. Assumete che un int occupi 4 byte e un puntatore 8. Considerate il seguente programma e mostrate la sequenza di messaggi stampati in esecuzione. Motivate i valori stampati.
```c++
#include <iostream>
class A {public: int el; int f(void){return 2;};};
class B: public A{protected: int el,m; A objA; virtual int f(void){return 1;};};
class C:  public A{public: int el; A objA;};
class D:  public B, public C{public: int el,el1; A objA;};
 
int main(int argc, const char * argv[]) {
    A objA; B objB; C objC; D objD;
    std::cout<<"Dimensione oggetto A :"<<sizeof(objA)<<’\n’;
    std::cout<<"Dimensione oggetto B :"<<sizeof(objB)<<’\n’;
    std::cout<<"Dimensione oggetto C :"<<sizeof(objC)<<’\n’;
    std::cout<<"Dimensione oggetto D :"<<sizeof(objD)<<’\n’;
    return 0;}
```