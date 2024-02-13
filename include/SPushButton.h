#pragma once
#include "SAbstractWidget.h"
#include <string.h>

class SPushButton :
    public SAbstractWidget
{
public:
    SPushButton(SAbstractWidget* parent = nullptr);
    std::string title;
    void show();
    void event(const ExMessage& msg);
    
    bool isClicked();
private:
    const ExMessage* m_msg;
   
  
};

