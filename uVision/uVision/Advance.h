// Advance.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//
//#include <afxwin.h>
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

// CCGUSBDemoApp:
// �йش����ʵ�֣������ CGUSBDemo.cpp
//

class CAdvanceApp : public CWinApp
{
public:
	CAdvanceApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAdvanceApp theApp;