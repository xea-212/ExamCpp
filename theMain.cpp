#include "DxLib.h"
#include "Player.h"
#include "globals.h"
#include "Input.h"
#include "Enemy.h"
#include <vector>
#include "Stage.h"

namespace
{
	const int BGCOLOR[3] = { 0, 0, 0 };//�w�i�F
	int crrTime;
	int prevTime;
}

std::vector<GameObject*> gameObjects; //�Q�[���I�u�W�F�N�g�̃x�N�^�[
std::vector<GameObject*> newObjects;


float gDeltaTime = 0.0f;//�t���[���Ԃ̎��ԍ�

void DxInit()
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(BGCOLOR[0], BGCOLOR[1], BGCOLOR[2]);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	SetDrawScreen(DX_SCREEN_BACK);
}

void MyGame()
{

	DrawFormatString(100, 100, GetColor(0, 0, 0), "�E�B���h�E�̃e�X�g");
	static int timer = 0;
	timer++;
	DrawFormatString(100, 150, GetColor(0, 0, 0), "%010d", timer);
}



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	DxInit();
	crrTime = GetNowCount();
	prevTime = GetNowCount();

	Stage* stage = new Stage();

	while (true)
	{
		ClearDrawScreen();
		Input::KeyStateUpdate();

		crrTime = GetNowCount();//���݂̎��Ԃ��擾
		//�O��̎��Ԃ̍������v�Z
		float deltaTime = (crrTime - prevTime) / 1000.0f;
		gDeltaTime = deltaTime;

		//�����ɂ�肽�������������i��������j
		//�Q�[���I�u�W�F�N�g�̒ǉ�
		if (newObjects.size() > 0)
		{
			for (auto& obj : newObjects)
			{
				gameObjects.push_back(obj);
			}
			newObjects.clear();
		}
		
		//gameObject�̍X�V
		for (auto& obj : gameObjects)
		{
			obj->Update(); //�Q�[���I�u�W�F�N�g�̍X�V
		}
		//gameObject�̕`��
		for (auto& obj : gameObjects)
		{
			obj->Draw(); //�Q�[���I�u�W�F�N�g�̕`��
		}

		for (auto it = gameObjects.begin(); it != gameObjects.end();)
		{
			if (!(*it)->IsAlive())
			{
				delete* it; //�Q�[���I�u�W�F�N�g���폜
				it = gameObjects.erase(it); //�x�N�^�[����폜
			}
			else
			{
				++it; //���̗v�f��
			}
		}
		//�����ɂ�肽�������������i�����܂Łj

		//����ʂ̕`��
		ScreenFlip();
		WaitTimer(16);

		prevTime = crrTime;//���݂̎�����O��̎��ԂƂ��ĕۑ�

		if (ProcessMessage() == -1)
			break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}

	DxLib_End();
	return 0;
}