#include <algorithm>
#include "SObject.h"

SObject::SObject(SObject* parent)
	:m_parent(parent) //ָ�򴫽����ĸ�����
{ //�ѱ�����ŵ�������ĺ�����������
	if (m_parent)
		m_parent->m_children.push_back(this);
}

SObject::~SObject()
{
	//�ͷź���
	for(auto& child : m_children)
	{
		delete child;
		child = nullptr;
	}
	//����Ӷ�������
	if(!m_children.empty())                                                                                              
			m_children.clear();

	//������û�д������Ӹ�����ĺ��������У��ѱ������Ƶ�
	if (m_parent)
	{
		//�ҵ��Լ�����vetor�������ҵ�->ɾ���Լ�
		auto it = std::find(m_parent->m_children.begin(), m_parent->m_children.end(), this);
		if (it != m_parent->m_children.end())
		{
			m_parent->m_children.erase(it); //���it�ҵ���
		}
	}

}
