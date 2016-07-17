// DialogAdminMain.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCBook.h"
#include "DialogAdminMain.h"
#include "afxdialogex.h"
#define WM_AdminMain_MGTBOOK WM_USER+102
#define WM_AdminMain_MGTREADER WM_USER+103
#define WM_AdminMain_MGTADMIN WM_USER+104
#define WM_AdminMain_MGTBORROW WM_USER+105
#define WM_AdminMain_MGTRETURN WM_USER+106
#define WM_AdminMain_MGTBOOKTYPR WM_USER+107
#define WM_AdminMain_DELADMIN WM_USER+108
#define WM_AdminMain_DELREADER WM_USER+109
// CDialogAdminMain �Ի���

IMPLEMENT_DYNAMIC(CDialogAdminMain, CDialog)

CDialogAdminMain::CDialogAdminMain(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogAdminMain::IDD, pParent)
{

}

CDialogAdminMain::~CDialogAdminMain()
{
}

void CDialogAdminMain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogAdminMain, CDialog)
	ON_BN_CLICKED(IDC_BOOKMGT, &CDialogAdminMain::OnBnClickedBookmgt)
	ON_BN_CLICKED(IDC_READERMGSMGT, &CDialogAdminMain::OnBnClickedReadermgsmgt)
	ON_BN_CLICKED(IDC_ADMINMGT, &CDialogAdminMain::OnBnClickedAdminmgt)
	ON_BN_CLICKED(IDC_BORROWMGT, &CDialogAdminMain::OnBnClickedBorrowmgt)
	ON_BN_CLICKED(IDC_RETURNMGT, &CDialogAdminMain::OnBnClickedReturnmgt)
	ON_BN_CLICKED(IDC_BOOKTYPEMGT, &CDialogAdminMain::OnBnClickedBooktypemgt)
	ON_BN_CLICKED(IDC_DELADMIN, &CDialogAdminMain::OnBnClickedDeladmin)
	ON_BN_CLICKED(IDC_DELREADER, &CDialogAdminMain::OnBnClickedDelreader)
END_MESSAGE_MAP()


// CDialogAdminMain ��Ϣ�������


void CDialogAdminMain::OnBnClickedBookmgt()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_AdminMain_MGTBOOK, 0, 0);
}


void CDialogAdminMain::OnBnClickedReadermgsmgt()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_AdminMain_MGTREADER, 0, 0);
}


void CDialogAdminMain::OnBnClickedAdminmgt()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_AdminMain_MGTADMIN, 0, 0);
}


void CDialogAdminMain::OnBnClickedBorrowmgt()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_AdminMain_MGTBORROW, 0, 0);

}


void CDialogAdminMain::OnBnClickedReturnmgt()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_AdminMain_MGTRETURN, 0, 0);
}


void CDialogAdminMain::OnBnClickedBooktypemgt()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_AdminMain_MGTBOOKTYPR, 0, 0);
	
}


void CDialogAdminMain::OnBnClickedDeladmin()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_AdminMain_DELADMIN, 0, 0);
}


void CDialogAdminMain::OnBnClickedDelreader()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_AdminMain_DELREADER, 0, 0);
}
