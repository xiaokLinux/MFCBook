#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")
#if !defined(AFX_ADOCONN_H__C71F546E_DB79_494E_BA57_A7A10D10C067__INCLUDED_)
#define AFX_ADOCONN_H__C71F546E_DB79_494E_BA57_A7A10D10C067__INCLUDED_
#include "ADOConn.h"
#if _MSG_VER > 1000
#pragma once
//ADOConn.h:interface for the ADOConn class
#endif //_MSG_VER >1000
// CDialogDelAdmin 对话框

class CDialogDelAdmin : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogDelAdmin)

public:
	CDialogDelAdmin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogDelAdmin();

// 对话框数据
	enum { IDD = IDD_DELADMIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_list;
	afx_msg void OnBnClickedDel();
	CADOConn m_ado;
};
#endif