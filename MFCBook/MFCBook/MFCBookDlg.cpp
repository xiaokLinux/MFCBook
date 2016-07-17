
// MFCBookDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCBook.h"
#include "MFCBookDlg.h"
#include "afxdialogex.h"
#include "DialogLogin.h"
#include "DialogAdminMain.h"
#include "DialogBookMsg.h"
#include "DialogBorrowBookDlg.h"
#include "DialogReturnBook.h"
#include "DialogAddReader.h"
#include "DialogDelReader.h"
#include "DialogAddAdmin.h"
#include "DialogDelAdmin.h"
#include "DialogMGTBookType.h"

//ȫ�ֵ��˳�ϵͳ����
int exitSys = 0;

//��Ϣģ��
//����Ա���
#define WM_LOGIN_MAIN WM_USER+101
#define WM_AdminMain_MGTBOOK WM_USER+102	//ͼ�����
#define WM_AdminMain_MGTREADER WM_USER+103	//���߹���
#define WM_AdminMain_MGTADMIN WM_USER+104	//��ӹ���Ա
#define WM_AdminMain_MGTBORROW WM_USER+105	//�������
#define WM_AdminMain_MGTRETURN WM_USER+106	//�������
#define WM_AdminMain_MGTBOOKTYPR WM_USER+107	//�鼮������
#define WM_AdminMain_DELADMIN WM_USER+108	//ɾ������Ա
#define WM_AdminMain_DELREADER WM_USER+109	//ɾ������
//test
//�鼮������ģ��
#define TESTBOOKMSGDLG		//����
//����Ա��ģ��
#define TESTBOOKBORROW		//����
#define TESTBOOKRETURN		//����
#define TESTBOOKRENEW		//����
#define TESTBOOKFINE		//����
#define TESTBOOKLOSE		//����Ǽ�

//������ģ��
#define TESTADDREADER		//��ӽ�����
#define TESTDELREADER		//ɾ��������
#define TESTADDADMIN		//��ӹ���Ա
//#define TESTDELADMIN		//ɾ������Ա
//δ����ģ��
//#define TESTMGTBOOKTYPE		//ͼ�����������


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCBookDlg �Ի���



CMFCBookDlg::CMFCBookDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCBookDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCBookDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_LOGIN_MAIN, OnCreateAdminMain)
	ON_MESSAGE(WM_AdminMain_MGTBOOK, OnCreateMgtBook)
	ON_MESSAGE(WM_AdminMain_MGTREADER, OnCreateMgtReader)
	ON_MESSAGE(WM_AdminMain_MGTADMIN, OnCreateMgtAdmin)
	ON_MESSAGE(WM_AdminMain_MGTBORROW, OnCreateMgtBorrow)
	ON_MESSAGE(WM_AdminMain_MGTRETURN, OnCreateMgtReturn)
	ON_MESSAGE(WM_AdminMain_MGTBOOKTYPR, OnCreateBookType)
	ON_MESSAGE(WM_AdminMain_DELADMIN, OnDelAdmin)
	ON_MESSAGE(WM_AdminMain_DELREADER, OnDelReader)
END_MESSAGE_MAP()


// CMFCBookDlg ��Ϣ�������
LRESULT CMFCBookDlg::OnDelReader(WPARAM wParam, LPARAM lParam)
{
	AfxMessageBox(TEXT("will be created delreader"));
	CDialogDelReader dlg;
	dlg.DoModal();
	return 0;
}
LRESULT CMFCBookDlg::OnDelAdmin(WPARAM wParam, LPARAM lParam)
{
	AfxMessageBox(TEXT("will be created"));
	CDialogDelAdmin dlg;
	dlg.DoModal();
	return 0;
}
LRESULT CMFCBookDlg::OnCreateBookType(WPARAM wParam, LPARAM lParam)
{
	CDialogMGTBookType dlg;
	dlg.DoModal();
	return 0;
}
LRESULT CMFCBookDlg::OnCreateMgtReturn(WPARAM wParam, LPARAM lParam)
{
	CDialogReturnBook dlg;
	dlg.DoModal();
	return 0;
}
LRESULT CMFCBookDlg::OnCreateMgtBorrow(WPARAM wParam, LPARAM lParam)
{
	CDialogBorrowBookDlg dlg;
	dlg.DoModal();
	return 0;
}
LRESULT CMFCBookDlg::OnCreateMgtAdmin(WPARAM wParam, LPARAM lParam)
{
	CDialogAddAdmin dlg;
	dlg.DoModal();
	return 0;
}
LRESULT CMFCBookDlg::OnCreateMgtReader(WPARAM wParam, LPARAM lParam)
{
	CDialogAddReader dlg;
	dlg.DoModal();
	return 0;
}
LRESULT CMFCBookDlg::OnCreateMgtBook(WPARAM wParam, LPARAM lParam)
{
	CDialogBookMsg dlg;
	dlg.DoModal();
	return 0;
}
LRESULT CMFCBookDlg::OnCreateAdminMain(WPARAM wParam, LPARAM lParam)
{
	CDialogAdminMain dlg;
	dlg.DoModal();
	exitSys = 1;
	return 0;
}

BOOL CMFCBookDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	CDialogLogin dlg;
	dlg.m_strUserName = ("�������û���");
	dlg.m_strPassword = ("����������");
	int ret = dlg.DoModal();
	TRACE("DOModle return =%d \n", ret);
	if (exitSys)
		return TRUE;
#if _DEBUG
#ifdef TESTMGTBOOKTYPE
	CDialogMGTBookType MGTBookTypeDlg;
	MGTBookTypeDlg.DoModal();
	return TRUE;
#endif
#ifdef TESTDELADMIN
	CDialogDelAdmin deladminDlg;
	deladminDlg.DoModal();
	return TRUE;
#endif
#ifdef TESTADDADMIN
	CDialogAddAdmin addadminDlg;
	addadminDlg.DoModal();
	return TRUE;
#endif
#ifdef TESTDELREADER
	CDialogDelReader delreaderDlg;
	delreaderDlg.DoModal();
	return TRUE;
#endif
#ifdef TESTADDREADER
	CDialogAddReader addreaderDlg;
	addreaderDlg.DoModal();
#endif
	if (ret = 1)//α����
	{
		CDialogAdminMain adminDlg;
		int cmd = adminDlg.DoModal();
	}
#endif
#ifdef TESTBOOKMSGDLG
	CDialogBookMsg bookmsgDlg;
	bookmsgDlg.DoModal();
#endif
#ifdef TESTBOOKBORROW
	CDialogBorrowBookDlg bookborrowDlg;
	bookborrowDlg.DoModal();
#endif
#ifdef TESTBOOKRETURN
	CDialogReturnBook bookreturnDlg;
	bookreturnDlg.DoModal();
#endif

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCBookDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCBookDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

