#include <iostream>
#include <memory>

template <class T>
class Singleton {
private:
	typedef std::unique_ptr<T> singleton_pointer_type;
	inline static T *createInstance() {
		return new T();
	}
	inline static T &getReference(const singleton_pointer_type &ptr) {
		return *ptr;
	}

protected:
	Singleton() {}

public:
	static T& singleton() {
		static typename T::singleton_pointer_type s_singleton(T::createInstance());
		return getReference(s_singleton);
	}


private:
	Singleton(const Singleton &) = delete;
	Singleton& operator=(const Singleton &) = delete;
	Singleton(Singleton &&) = delete;
	Singleton& operator=(Singleton &&) = delete;
};

class Base :public Singleton<Base> {
protected:
	char *str;
	friend class Singleton<Base>;
	Base() { 
		std::cout << "Base()" << std::endl;
		str = "Base";
	}
public:
	virtual void Func();
};

void Base::Func() {
	std::cout << str << std::endl;
}

class Manager :public Base {
private:
	friend class Singleton<Manager>;
	Manager() {
		std::cout << "Manager()" << std::endl;
		str = "Manager";
	}
public:
	virtual void Func();
};

void Manager::Func() {
	
}



int main() {
	
	Base::singleton().Func();
	std::cout << "change class" << std::endl;
	Manager::singleton().Func();

	getchar();
	return 0;
}
