#include <memory>
#include <iostream>
#include <string>

extern class SceneManager;

class Scene {
protected:
	std::string mstr_word;
	SceneManager* mptr_scene_manager;
public:
	Scene() = default;

	void SetManagerRef(SceneManager* _ptr);
	inline Scene* ReturnScenePtr() {
		return this;
	}

	void PrintString();
};

void Scene::SetManagerRef(SceneManager* _ptr) {
	mptr_scene_manager = _ptr;
}

void Scene::PrintString() {
	std::cout << mstr_word << std::endl;
}

class Title :public Scene {
public:
	Title();
};

Title::Title() {
	mstr_word = "Title";
}

class Game :public Scene {
public:
	Game();
};

Game::Game() {
	mstr_word = "Game";
}

class SceneManager {
private:
	std::shared_ptr<Scene> mshared_ptr_scene;

public:
	SceneManager();

	void ChangeScene(std::shared_ptr<Scene> _change_scene);

	void PrintString();
};

SceneManager::SceneManager() {
	mshared_ptr_scene = std::make_shared<Title>();
	mshared_ptr_scene->SetManagerRef(this);
}

void SceneManager::ChangeScene(std::shared_ptr<Scene> _change_scene) {
	mshared_ptr_scene = _change_scene;
	mshared_ptr_scene->SetManagerRef(this);
}

void SceneManager::PrintString() {
	mshared_ptr_scene->PrintString();
}

int main() {
	SceneManager *scenemanager = new SceneManager;

	scenemanager->PrintString();

	scenemanager->ChangeScene(std::make_shared<Game>());

	scenemanager->PrintString();

	getchar();

	delete scenemanager;

	return 0;
}



