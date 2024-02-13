#pragma once
#include "SObject.h"
#include <easyx.h>
#include <string>//��ť�ϵ�����
//����Ŀؼ�����
class SAbstractWidget :public SObject
{
public:
	SAbstractWidget(SAbstractWidget* parent = nullptr);
	~SAbstractWidget();
	//��������
	void move(int x, int y);
	void setSize(int w, int h);
	void setColor(DWORD c);
	void setTitle(std::string title);
	//ÿһ�����඼Ҫʵ�ֵĹ���
	 virtual void show() = 0;  //���麯�������ܶ������
	 virtual void event(const ExMessage& msg);
	/* virtual void event2(const ExMessage& msg2);*/
	int m_x; //����
	int m_y;
	int m_w; //�ߴ�
	int m_h;
	DWORD m_color;  //��ɫ1
	
	

	std::string m_title; //����
	
	
};

