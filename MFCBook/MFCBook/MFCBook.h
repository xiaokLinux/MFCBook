
// MFCBook.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCBookApp: 
// �йش����ʵ�֣������ MFCBook.cpp
//

class CMFCBookApp : public CWinApp
{
public:
	CMFCBookApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCBookApp theApp;