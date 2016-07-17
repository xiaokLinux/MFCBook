
// MFCBookDlg.cpp : 实现文件
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

//全局的退出系统命令
int exitSys = 0;

//消息模块
//管理员相关
#define WM_LOGIN_MAIN WM_USER+101
#define WM_AdminMain_MGTBOOK WM_USER+102	//图书管理
#define WM_AdminMain_MGTREADER WM_USER+103	//读者管理
#define WM_AdminMain_MGTADMIN WM_USER+104	//添加管理员
#define WM_AdminMain_MGTBORROW WM_USER+105	//借书管理
#define WM_AdminMain_MGTRETURN WM_USER+106	//还书管理
#define WM_AdminMain_MGTBOOKTYPR WM_USER+107	//书籍类别管理
#define WM_AdminMain_DELADMIN WM_USER+108	//删除管理员
#define WM_AdminMain_DELREADER WM_USER+109	//删除读者
//test
//书籍管理子模块
#define TESTBOOKMSGDLG		//找书
//管理员子模块
#define TESTBOOKBORROW		//借书
#define TESTBOOKRETURN		//还书
#define TESTBOOKRENEW		//续借
#define TESTBOOKFINE		//罚金
#define TESTBOOKLOSE		//丢书登记

//读者子模块
#define TESTADDREADER		//添加借阅者
#define TESTDELREADER		//删除借阅者
#define TESTADDADMIN		//添加管理员
//#define TESTDELADMIN		//删除管理员
//未分类模块
//#define TESTMGTBOOKTYPE		//图书类别管理界面


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCBookDlg 对话框



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


// CMFCBookDlg 消息处理程序
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	CDialogLogin dlg;
	dlg.m_strUserName = ("请输入用户名");
	dlg.m_strPassword = ("请输入密码");
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
	if (ret = 1)//伪条件
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCBookDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCBookDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

