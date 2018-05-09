#include <iostream>
#include <string.h>

#define STR_MAX 31
#define _CRT_SECURE_NO_WARNINGS

#pragma warning (disable:4996)

class classA {
public:
	classA(void) { strcpy(strings, "クラスA"); }
	~classA(){ }

protected:
	char* get(void);

private:
	char strings[STR_MAX + 1];
};

class classB :public classA {
public:
	classB(void) { strcpy(strings, "クラスB"); }
	~classB(){}
	void disp(char*);
	void disp(void);
private:
	char strings[STR_MAX + 1];
};

char* classA::get(void) { return strings; }
void classB::disp(char* pStr) { std::cout << pStr << std::endl; }
void classB::disp(void) { std::cout << classA::get() << std::endl;
std::cout << classB::get() << std::endl;
}

int main(void) {
	classB* pClass;
	pClass = new classB;
	pClass->disp();
	pClass->disp("クラス外");
	delete pClass;

	getchar();
	return 0;
}