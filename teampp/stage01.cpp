#include "stdafx.h"
#include "stage01.h"
#include "npc.h"

stage01::stage01()
{
}

stage01::~stage01()
{
}

HRESULT stage01::init()
{
	
	// 스테이지 1 Rightdoor 잠긴 이미지 변경 선언

	_Stage1RightDoorLock._StageImage = IMAGEMANAGER->addImage("Door3_Stage1", "images/stage/UI_Locked_Door.bmp", 52, 76, true, RGB(255, 0, 255));

	//==================================================================================================================================================//

	// 스테이지 1 Rightdoor 이미지 변경 선언

	_Stage1RightDoorOpen._StageImage = IMAGEMANAGER->addImage("Door_Stage1", "images/stage/UI_UnLocked_Door11.bmp", 52, 76, true, RGB(255, 0, 255));

	_Stage1RightDoorOpen._x = WINSIZEX + 155;
	_Stage1RightDoorOpen._y = WINSIZEY / 2 - 125;

	_Stage1RightDoorOpen._rc.setCenterPos(_Stage1RightDoorOpen._x, _Stage1RightDoorOpen._y);

	//==================================================================================================================================================//

	// 스테이지 1 픽셀 배경 선언

	_Stage1PixelBackGround._pixelCollision = IMAGEMANAGER->addImage("stage1_pixel", "images/stage/stage01_pixel.bmp", 2016, 672, false, NULL);

	//==================================================================================================================================================//

	//스테이지 1 배경 선언

	IMAGEMANAGER->addImage("Test_Stage1", "images/stage/stage01.bmp", 2016, 672, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("desk", "images/stage/desk.bmp", 939, 162, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("desk2", "images/stage/desk2.bmp", 936, 138, true, RGB(255, 0, 255));

	//==================================================================================================================================================//

	//스테이지 1 RightDoor 선언

	_Stage1RightDoor._StageImage = IMAGEMANAGER->addImage("Door2_Stage1", "images/stage/UI_UnLocked_Door22.bmp", 52, 76, true, RGB(255, 0, 255));

	_Stage1RightDoor._x = WINSIZEX + 155;
	_Stage1RightDoor._y = WINSIZEY / 2 - 125;

	_Stage1RightDoor._rc.setCenterPos(_Stage1RightDoor._x, _Stage1RightDoor._y);



	return S_OK;
}

void stage01::release()
{
}

void stage01::update()
{
	

}

void stage01::render()
{
	IMAGEMANAGER->findImage("Test_Stage1")->render(getMemDC(), 0, 0);

	IMAGEMANAGER->findImage("Door2_Stage1")->render(getMemDC(), _Stage1RightDoor._x - 26, _Stage1RightDoor._y - 93);

	ZORDER->pushObject(getMemDC(), "desk", 2, 822, 0, 535);
	ZORDER->pushObject(getMemDC(), "desk2", 2, 663, 0, 672);

	_Stage1PixelBackGround._pixelCollision->render(getMemDC());
}

void stage01::Stage1RightDoorOpenDraw()	// 스테이지 1 오른쪽 door 접근 시 이미지 변경
{
	IMAGEMANAGER->findImage("Door_Stage1")->render(getMemDC(), _Stage1RightDoor._x - 26, _Stage1RightDoor._y - 93);
}

void stage01::Stage1RightDoorLockDraw()	// 스테이지 1 오른쪽 door 잠긴 이미지 변경 
{
	IMAGEMANAGER->findImage("Door3_Stage1")->render(getMemDC(), _Stage1RightDoor._x - 26, _Stage1RightDoor._y - 93);
}

