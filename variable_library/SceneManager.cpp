#include "SceneManager.h"

using namespace variableNS;

void SceneManager::ScenePlay(Scene *scene){
	m_currentScene = scene;
	scene->OnEnter();
}

void SceneManager::SceneUpdate() {
	m_currentScene->OnUpdate();
}

void SceneManager::SceneReLoad() {

}

void SceneManager::SceneEnd() {
	m_currentScene->OnExit();
	delete m_currentScene;
}

void SceneManager::SceneTransition(Scene* scene) {
	SceneEnd();
	ScenePlay(scene);
}

Scene& SceneManager::GetCurrentScene() {
	return *m_currentScene;
}