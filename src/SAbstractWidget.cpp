#include "SAbstractWidget.h"

SAbstractWidget::SAbstractWidget(SAbstractWidget* parent)
	:SObject(parent)	//���ø���Ĺ��캯��
	,m_x(150),m_y(0),m_w(150),m_h(255),m_color(0) //��ʼ��
	,m_title("SAbstractWidget1")
	
	
{
}

SAbstractWidget::~SAbstractWidget()
{
}

void SAbstractWidget::move(int x, int y)
{
	m_x= x;
	m_y= y;

	
}

void SAbstractWidget::setSize(int w, int h)
{
	m_w = w;
	m_h = h;
	
}

void SAbstractWidget::setColor(DWORD c)
{
	m_color = c;

}

void SAbstractWidget::setTitle(std::string title)
{
	m_title = title;
}


void SAbstractWidget::event(const ExMessage& msg)
{

}
