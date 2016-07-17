#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")
#if !defined(AFX_ADOCONN_H__C71F546E_CB79_494E_BA67_A7A10D10C067__INCLUDED_)
#define AFX_ADOCONN_H__C71F546E_CB79_494E_BA67_A7A10D10C067__INCLUDED_
#include "ADOConn.h"
#if _MSG_VER > 1000
#pragma once
//ADOConn.h:interface for the ADOConn class
#endif //_MSG_VER >1000
// CDialogBorrowBookDlg 对话框

class CDialogBorrowBookDlg : public CDialog
{
	DECLARE_DYNAMIC(CDialogBorrowBookDlg)

public:
	CDialogBorrowBookDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogBorrowBookDlg();

// 对话框数据
	enum { IDD = IDD_BORROW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strRID;
	CString m_strBID;
	CString m_strRName;
	int m_nMaxNu;
	CString m_strType;
	int m_nHavaBorrow;
	CString m_strBName;
	CString m_strBAuthor;
	CString m_strBPress;
	CString m_strFlag;
	afx_msg void OnBnClickedOk();
	CADOConn m_ado;
};
#endif