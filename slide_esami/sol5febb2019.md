2. Mostrate e commentate i possibili usi della parola riservata static
La dichiarazione statica, applicata ad una variabile o ad una funzione limita lo scope di quella variabile o funzione a tutto il file sorgente che viene compilato.
La dichiarazione static puo' essere applicata anche alle funzioni, le quali normalmente sono globali, visibili in ogni parte del programma. Se la funzione e' dichiarata static allora il suo nome e' invisibile al di fuori del file dove viene dichiarata.
Static puo' essere dichiarata anche internamente a variabili locali di una particolare funzione, le quali a differenza delle normali variabili automatiche(che vanno e vengono ogni volta che la funzione e' chiamata e termina), rimangono in esistenza fino al termine del programma. Questo significa che variabili statiche danno spazio privato e permanente a una singola funzione.

3. Considerate la struttura 
```c
struct nodo{int i; struct nodo* next;}
```
 e scrivete una funzione deleteList che accetta in ingresso una lista (nota attraverso un puntatore al primo nodo) e la cancella. Il puntatore passato come parametro dovra' al termine risultare nullo.

```c
void delete_lista(struct nodo **l){
	if(l == NULL || *l) return;
	struct nodo *head, *tmp;
	head = *l;
	while(head != NULL){
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
	*l = NULL;
}
```

4. qual e' la differenza tra binding dinamico e binding statico
Il binding in un linguaggio a programmazione ad oggetti consiste nell'associare al selettore di un messaggio il metodo che lo implementa
Si differenzia in:
binding statico: il binding viene eseguito durante la fase di compilazione e linking
binding dinamico: il binding viene eseguito durante la fase di esecuzione, i suoi vantaggi sono: overloading di operazioni, estendibilita', compattezza del codice e comprensibilita'
Overloading  permette ad operazioni con lo stesso nome ma diversa semantica,vengano adoperate per oggetti di tipo differente
Il c++ supporta il binding dinamico attraverso il meccanismo delle funzioni virtuli

5. Quali sono i principali problemi legati all'ereditarieta' multipla? Quali strumenti mette a disposizione il c++ per la loro risoluzione
Un problema legato all'ambiguita' e' la scelta del metodo da eseguire:
Si ha un classe Impiegato, che viene ereditata 2 sottoclassi Venditore e Manager, le quali a loro volta sono ereditate da una sottoclasse Manager_vendinte
Se si vuole eseguire
```c++
Manager_Vendite boss;
char *str = boss.getNome();
```
Il compilatore non sa quale metodo eseguire tra quello Venditore.getNome() oppure Manager.getNome();
C++ risolve cosi'
```c++
str = boss.Manager::getNome();
```
Altro problema di ambiguita' sorge quando 2 o piu' classi base definiscono un membro con lo stesso nome
```c++
impiegato *imp_ptr;
Manager_Vendite *boss_ptr;
imp_ptr = boss_ptr; // ambiguo
```
Si ricorre quindi alla conversione esplicita
```c++
imp_ptr = (Manager *) boss_ptr;
```
Per evitare le duplicazioni si usa una classe base virtuale
```c++
class Impiegato{};
class Venditore: virtual public Impiegato{};
class Manager: virtual public Impiegato{}
class Manager_vendite: public Venditore, public Manager{};
```

6. Modificate la classe
```c++
class Persona{char *nome; char *cognome; int matricola;};
```
in modo che se p e' un oggetto della classe Persona e rappresenta lo studente Fabio Rossi con matricola 75643, l’espressione 
```c++
std::cout << p
``` 
produca il seguente output
Nome:Fabio
Cognome:Rossi
Matricola:75643
```c++
friend std::ostream& operator<<(ostream& os, Persona p){
	os << "Nome:" << p.nome << "\nCognome:" << p.cognome << "\nMatricola"
		<< p.matricola << "\n";
	return os;
}
```
