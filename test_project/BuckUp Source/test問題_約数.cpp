#include <DirectXMath.h>
#include <vector>
#include <iostream>

std::vector<int> g_vector;

void test(int _value) {
	int maxValue = _value;
	for (int i = 0; i <= maxValue; ++i) {
		if (0 != i) {
			int culValue = _value % i;
			if (0 == culValue) {
				g_vector.push_back(i);
			}
		}
	}
}

void Print(std::vector<int> _vec) {
	for (int i = 0; i < _vec.size(); ++i) {
		if (0 == i) {
			std::cout << "–ñ”‚Í" << std::ends;
		}
		std::cout << _vec[i] << std::ends;
	}
}

int main() {
	test(12);

	Print(g_vector);

	getchar();
	return 0;
}