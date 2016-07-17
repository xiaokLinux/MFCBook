#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")
#if !defined(AFX_ADOCONN_H__C71F546E_CB79_494E_BA57_A7A10D10C067__INCLUDED_)
#define AFX_ADOCONN_H__C71F546E_CB79_494E_BA57_A7A10D10C067__INCLUDED_
#include "ADOConn.h"
#if _MSG_VER > 1000
#pragma once
//ADOConn.h:interface for the ADOConn class
#endif //_MSG_VER >1000
// CDialogAddAdmin 对话框

class CDialogAddAdmin : public CDialog
{
	DECLARE_DYNAMIC(CDialogAddAdmin)

public:
	CDialogAddAdmin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogAddAdmin();

// 对话框数据
	enum { IDD = IDD_ADDANMIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_strID;
	CString m_strName;
	CString m_strPWD;
	CString m_strPWDAgain;
	CADOConn m_ado;
};
#endif