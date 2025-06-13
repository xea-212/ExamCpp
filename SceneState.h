#pragma once

enum State
{
	TITLE,
	PLAY,
	RESULT,
	MAX_NUM
};
State state;


void ChangeScene(int& scenename) { scenename = GetState(); }

int GetState() { return state; }