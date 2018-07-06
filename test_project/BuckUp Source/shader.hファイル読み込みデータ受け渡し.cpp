#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <d3d11.h>

#include "VertexShader.h"
#include <vector>



enum ArraySize {
	VertexShader,
	Copy,
	Max
};

class Test {
public:
	Test(std::string _fileName);

	FILE* m_pFile;
	unsigned char byte;
	//BYTE *m_testArray;
	std::vector<BYTE> m_testArray;
	
};

size_t array_size[ArraySize::Max];

Test::Test(std::string _filename) {
	m_pFile = NULL;
	m_pFile = fopen(_filename.c_str(), "r");
	if (m_pFile != NULL) {
		std::cout << _filename.c_str() << " can open" << std::endl;
	}
	byte = 0;
	char buf[256];
	int n = 0;

	do {
		if (n > NULL) {
			static int _array = 0;
			if (0 == strcmp(buf, "const")) {
				std::cout << buf << std::endl;

				do {
					fscanf(m_pFile, "%s", buf);
				} while (0 != strcmp(buf, "{"));

				
				for (int f = 0; f != strcmp(buf, "}"); f = fscanf(m_pFile, "%s", &buf)) {
					fscanf(m_pFile, "%d", &byte);
	//				m_testArray[_array] = (BYTE)byte;
	//				printf("m_testArry[%d]:%d\n", _array, m_testArray[_array]);
					m_testArray.push_back((BYTE)byte);
					printf("m_testArry[%d]:%d\n", _array, m_testArray[_array]);
					++_array;
				}
			}			
		}
		n = fscanf(m_pFile, "%s", buf);
	} while (n > NULL);

	rewind(m_pFile);
	fclose(m_pFile);
	std::cout << "file close" << std::endl;
}


int main() {
	array_size[ArraySize::VertexShader] = ARRAYSIZE(g_vs_main);


	Test* p = new Test("VertexShader.h");

	size_t size = p->m_testArray.size();

	std::cout << "VertexShader's size = " << size << std::endl;
	for (int y = 0; y < array_size[ArraySize::VertexShader] / 6; ++y) {
		for (int x = 0; x < 6; ++x) {
			printf("%d, ", p->m_testArray[6 * y + x]);
		}
		std::cout << std::endl;
	}

	delete p;
	getchar();
	return 0;
}