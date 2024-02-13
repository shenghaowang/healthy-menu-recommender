#pragma once
#include <vector>

class SObject
{
public:
	SObject(SObject* parent =nullptr);
	~SObject();

private:
	SObject* m_parent; //����ĸ�����ָ��
	std::vector<SObject*> m_children; //�Ӷ���ָ��
};

