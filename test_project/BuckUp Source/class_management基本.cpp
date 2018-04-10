#include <vector>
#include <stdio.h>
#include <iostream>


enum class Class_Management :unsigned char {
	GameObject,
	Character,
	Enemy
};

#define CLASS_GAMEOBJECT (1 << static_cast<char>(Class_Management::GameObject))
#define CLASS_CHARACTER (1 << static_cast<char>(Class_Management::Character))
#define CLASS_ENEMY (1 << static_cast<char>(Class_Management::Enemy))

class GameObject {
protected:
	char mc_class_management;

public:
	GameObject();
	inline char GetClassManagement() const {
		return mc_class_management;
	}
};

GameObject::GameObject() {
	mc_class_management = CLASS_GAMEOBJECT;
}

class Character :public GameObject {

public:
	Character();
};

Character::Character() {
	mc_class_management |= CLASS_CHARACTER;
}

void DisplayBitClassManagement(const char _class_management) {
	std::vector<char> display_management;
	for (char c = sizeof(char) * 8; c > 0; --c) {
		if (true == (_class_management >> (1 << c))) {
			display_management.push_back(1);
		}
		else display_management.push_back(0);
	}

	for (char c = display_management.size() - 1; c >= 0; --c) {
		if (true == display_management[c]) {
			printf("1");
		}
		else {
			printf("0");
		}
	}
}

void DisplayManagement(const char _class_management) {
	if (_class_management & CLASS_GAMEOBJECT) {
		printf("このクラスはGameObjectクラスを継承しています。\n");
	}
	if (_class_management == CLASS_GAMEOBJECT) {
		printf("このクラスはGameObjectクラスです。\n");
	}
	
	if (_class_management & CLASS_CHARACTER) {
		printf("このクラスはCharacterクラスです。\n");
	}
}

int main() {
	GameObject *gameobject = new GameObject;

	DisplayBitClassManagement(gameobject->GetClassManagement());
	DisplayManagement(gameobject->GetClassManagement());

	printf("\n");

	Character *character = new Character;

	DisplayBitClassManagement(character->GetClassManagement());
	DisplayManagement(character->GetClassManagement());

	getchar();
	return 0;
}





