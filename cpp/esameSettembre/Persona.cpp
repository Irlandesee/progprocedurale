//
// Created by Mattia Lunardi on 04/09/22.
//

class Persona{
    char *nome;
    char *cognome;
    static int count;
public:
    static int in_vita(){return count;}

    Persona(char *n, char *c){
       char *p1 = n;
       char *p2 = c;
       int n_length = 0;
       int c_length = 0;
       while(*p1 != '\0'){
           p1++;
           n_length++;
       }
       while(*p2 != '\0'){
           p2++;
           c_length++;
       }

       nome = new char[n_length + 1];
       cognome = new char[c_length + 1];
       int i = 0;

       while(*n != '\0'){
           nome[i] = *n;
           n++;
           i++;
       }
       nome[i + 1] = '\0';
       i = 0;
       while(*c != '\0'){
           cognome[i] = *c;
           c++;
           i++;
       }
       cognome[i + 1] = '\0';
       count++;
    }

    ~Persona(){
        delete[] nome;
        delete[] cognome;
        count--;
    }
};

int Persona::count = 0;