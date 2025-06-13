#include "SceneState.h"

void ChangeScene(int& scenestate)
{
	switch (scenestate)
	{
	case State::TITLE:
		scenestate = State::PLAY;
		break;
	case State::PLAY:
		scenestate = State::RESULT;
		break;
	case State::RESULT:
		scenestate = State::TITLE;
		break;
	default:
		break;
	}
}
