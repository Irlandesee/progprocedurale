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
Si hanno 3 parole chiave per il controllo della visibilità:

private -> se un membro è private allora il è visibile solamente all'interno della classe. Se A è una classe privata base, B una classe derivata da A. I membri pubblici e protected di A possono essere usati dalle funzioni membro di B. Solo gli amici e membri di D possono convertire un B* a A*

public -> se un membro è public allora è visibile ovunque, anche all'esterno della classe. Se A è classe pubblica allora i suoi membri e funzioni public possono essere usate ovunque. Inoltre i suoi membri protetti possono essere usati da membri e amici di B e membri e amici delle classi derivate da B. Qualsiasi funzione può convertire un B* a A*

protected -> se A è un classe protected, i suoi memrbi public e protected opssono essere usati solo da funzioni e membri derivati di B. Solo amici e mebtri di B e amici delle classi derivate da B possono convertire da B* a A*


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
```c++
A objA; // 4 byte -  ha un solo int, f non è virtuale
B objB; // 24 byte - 4 byte occupati da A::el, 4 da B::el,
		//4 da B::m, 4 da B::objA, 8 per il puntatore associato alla funzione virtuale f
C objC; // 12 byte - 4 da C::el, 4 da C::objA, 4 da A::el
D objD; //48 byte 
```
