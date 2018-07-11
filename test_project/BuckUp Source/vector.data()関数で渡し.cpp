#include <stdio.h>
#include <vector>

template<typename Type>
std::vector<Type> Fucntion(Type _value) {
	std::vector<Type> vector;
	vector.push_back(_value);

	return vector;
}

int main(void) {

	int* p = Fucntion<int>(1).data();

	return 0;
}