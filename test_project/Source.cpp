#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <memory>
#include <list>

class Base {
protected:
	std::string m_str;

public:
	Base();
	~Base();
	inline Base* GetRef() {
		std::cout << "GetRef():" << this << std::endl;
		return this;
	}
	inline void DisplayRef() {
		std::cout << "DisplayRef():" << this << std::endl;
	}
};

class Manager {
private:
	std::list<Base*> mlis_objects;
	unsigned char* muc_ptr;

public:
	Manager();
	~Manager();
	inline void AddObject(Base* _object) {
		mlis_objects.push_back(_object);
	}

	void Update();

	int Deleter();
};

class Manager g_manager;

Manager::Manager() {

}

Manager::~Manager() {
	std::list<Base*>::iterator iter = mlis_objects.begin();
	while (iter != mlis_objects.end()) {
		delete *iter;
		++iter;
	}
}

void Manager::Update() {
	std::list<Base*>::iterator iter_objects = mlis_objects.begin();
	while (iter_objects != mlis_objects.end()) {
		Base* object = *iter_objects;
		object->DisplayRef();
		++iter_objects;
	}
}

int Manager::Deleter() {
	std::list<Base*>::iterator iter = mlis_objects.begin();
	while (iter != mlis_objects.end()){
		if (!*iter) { return -1; }
		iter = mlis_objects.erase(iter);
	}

	return 0;
}



Base::Base(){
	m_str = "Base():";
	std::cout << m_str << this << std::endl;
	g_manager.AddObject(this);
}

Base::~Base(){ }

class Object :public Base {
public:
	Object();
	~Object();
};

Object::Object() {
	m_str = "Object():";
	std::cout << m_str << this << std::endl;
}

Object::~Object() {

}




void main() {

	while (1){
		if ('a' == _getch()) {
			break;
		}

 		if (' ' == _getch()) {
			Object* object = new Object;
		}

		g_manager.Update();
	}

	g_manager.Deleter();
}