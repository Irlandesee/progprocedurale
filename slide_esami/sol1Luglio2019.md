1. Presentate le principali funzioni per l'accesso ai file in C
5.
```c++
class Complex{
	double re; double im;
public:
	friend std::ostream& operator<<(std::ostream& os, Complex& n);
}


std::ostream& operator<<(std::ostream& os, Complex& n){
	os << "(" << n.re << "," << n.im << ")";
	return os;
}

```

6. Date le 4 classi seguenti
```c++
class A{
public:
	void f(){
		std::cout << "f di A\n";
		g();
	}
	virtual void g(){
		std::cout < "g di A\n";
	}
};
class B: virtual public A{
public:
	void f(){
		std::cout << "f di B\n";
		g();
	}
};
class C: virtual public A{
public:
	virtual void g(){
		std::cout << "g di C\n";
	}
};
class D: public B, public C{
public:
	virtual void g(){
		std::cout << "g di D\n";
	}
};


A *pA;
C *pC;
D d;
```
```c++
pA = &d;
pA->f();
pA->g();
```
```c++
pC = &d;
pC->f();
```
```c++
d.f();
```
