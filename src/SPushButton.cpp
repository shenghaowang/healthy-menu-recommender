#include "SPushButton.h"
#include <string.h>
SPushButton::SPushButton(SAbstractWidget* parent)
	:SAbstractWidget(parent)
{
	m_title;
	m_x;
	m_y;
	m_msg;
	m_w = 120;
	m_h= 40;
	
	m_color = RGB(230, 231, 232);
}

void SPushButton::show()
{
	//���ñ���ģʽΪ͸��
	setbkmode(TRANSPARENT);
	setfillcolor(m_color);
	
	//����һ������
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);
	
	//��������
	settextcolor(RED);
	//��ˮƽ�ʹ�ֱ���
	int vspace = (m_w - textwidth(m_title.c_str())) / 2;
	int hspace = (m_h - textheight(m_title.c_str())) / 2;

	
	outtextxy(m_x+vspace, m_y+hspace, m_title.c_str());
	
	
}

void SPushButton::event(const ExMessage& msg)
{
	m_msg= &msg;
}

//�ж�ĳ�����Ƿ���ĳ���������򱻵��
bool isIn(int x, int y, int left, int top, int w, int h)
{
	return x >= left && x <= left + w && y >= top && y <= top + h;
}

bool SPushButton::isClicked()
{
	//�������ĵ�����ж������û���ڰ�ť�ϵ�� m_msg��������
	if (m_msg->message == WM_LBUTTONDOWN && isIn(m_msg->x, m_msg->y, m_x, m_y, m_w, m_h))
	{
		return true;
	}
	return false;

}
