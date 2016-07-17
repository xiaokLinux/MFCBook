// DialogReturnBook.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCBook.h"
#include "DialogReturnBook.h"
#include "afxdialogex.h"


// CDialogReturnBook 对话框

IMPLEMENT_DYNAMIC(CDialogReturnBook, CDialog)

CDialogReturnBook::CDialogReturnBook(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogReturnBook::IDD, pParent)
{

}

CDialogReturnBook::~CDialogReturnBook()
{
}

void CDialogReturnBook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogReturnBook, CDialog)
END_MESSAGE_MAP()


// CDialogReturnBook 消息处理程序
