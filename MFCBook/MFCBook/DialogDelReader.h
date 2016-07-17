#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")
#if !defined(AFX_ADOCONN_H__C71F546E_DB79_494E_BA57_A7A10D10C067__INCLUDEE_)
#define AFX_ADOCONN_H__C71F546E_DB79_494E_BA57_A7A10D10C067__INCLUDEE_
#include "ADOConn.h"
#include "afxcmn.h"
#if _MSG_VER > 1000
#pragma once
//ADOConn.h:interface for the ADOConn class
#endif //_MSG_VER >1000
// CDialogDelReader 对话框

class CDialogDelReader : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogDelReader)

public:
	CDialogDelReader(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogDelReader();

// 对话框数据
	enum { IDD = IDD_DELREADER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	CListCtrl m_List;
	afx_msg void OnBnClickedDelreader();
	virtual BOOL OnInitDialog();
	CADOConn m_ado;
	CListCtrl m_list;
};
#endif
