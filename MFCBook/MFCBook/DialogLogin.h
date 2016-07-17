#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")
#if !defined(AFX_ADOCONN_H__D61F546E_CB79_494E_BA57_A7A10D10C067__INCLUDED_)
#define AFX_ADOCONN_H__D61F546E_CB79_494E_BA57_A7A10D10C067__INCLUDED_
#include "ADOConn.h"
#if _MSG_VER > 1000
#pragma once
//ADOConn.h:interface for the ADOConn class
#endif //_MSG_VER >1000

// CDialogLogin 对话框
class CDialogLogin : public CDialog
{
	DECLARE_DYNAMIC(CDialogLogin)

public:
	CDialogLogin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogLogin();
	
// 对话框数据
	enum { IDD = IDD_LOGIN };
	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strUserName;
	CString m_strPassword;
	CADOConn m_ADO;
	afx_msg void OnBnClickedOk();
};
#endif