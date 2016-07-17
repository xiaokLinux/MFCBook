// DialogLogin.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCBook.h"
#include "DialogLogin.h"
#include "afxdialogex.h"

#define WM_LOGIN_MAIN WM_USER+101

// CDialogLogin 对话框

IMPLEMENT_DYNAMIC(CDialogLogin, CDialog)

CDialogLogin::CDialogLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogLogin::IDD, pParent)
	, m_strUserName(_T(""))
	, m_strPassword(_T(""))
{

}

CDialogLogin::~CDialogLogin()
{
}

void CDialogLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_UserName, m_strUserName);
	DDV_MaxChars(pDX, m_strUserName, 10);
	DDX_Text(pDX, IDC_PASSWORD, m_strPassword);
	DDV_MaxChars(pDX, m_strPassword, 15);
}


BEGIN_MESSAGE_MAP(CDialogLogin, CDialog)
	ON_BN_CLICKED(IDOK, &CDialogLogin::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialogLogin 消息处理程序


void CDialogLogin::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData();
	m_ADO.OnInitADOConn();
	_bstr_t vSQL;
	CString sql;
	CString buffer;
	sql.Format(TEXT("select * from Admin where AName='"));
	sql = sql + m_strUserName;
	buffer.Format(TEXT("' and APassword='"));
	sql =sql+ buffer + m_strPassword;
	buffer.Format(TEXT(" '"));
	sql = sql + buffer;
	AfxMessageBox(sql);
//	return;
	vSQL = (_bstr_t)sql;
	try
	{
		m_ADO.m_pRecordset = m_ADO.GetRecordSet(vSQL);
		if (!m_ADO.m_pRecordset->adoBOF)
		{
			AfxMessageBox(TEXT("Login successed!"));
			::PostMessage(GetParent()->GetSafeHwnd(), WM_LOGIN_MAIN, 0, 0);
			//CDialogAdminMain dlg;
			//dlg.DoModal();
			m_ADO.m_pRecordset->MoveFirst();
		}
		else
		{
			AfxMessageBox(TEXT("Login filed!"));
			return;
		}
		m_ADO.ExitConnect();
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}


	CDialog::OnOK();
}
