#pragma once
#include "image.h"

static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX * 3, WINSIZEY * 3);

class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;		//�Ŵ����� �ʱ�ȭ�Ҳ���

public:
	gameNode();
	virtual ~gameNode();

	//HRESULT�� ����ũ�μ���Ʈ ���� ����� ��ȯ�� �ε�
	//S_OK, E_FAIL, SUCCDED ������ ���â�� 
	//����� �ʱ�ȭ�� �ߵƴ��� �ƴ����� �����ش�
	virtual HRESULT init();			//�ʱ�ȭ ���� �Լ�
	virtual HRESULT init(bool managerInit);
	virtual void release();			//�޸� ���� ����
	virtual void update();			//���� ����
	virtual void render();			//�׸��� ����

	//����� DC�޸� ������
	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }

	int getMemDCWidth() { return _backBuffer->getWidth(); }
	int getMemDCHeight() { return _backBuffer->getHeight(); }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);
};
