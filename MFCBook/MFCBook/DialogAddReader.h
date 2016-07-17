#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")
#if !defined(AFX_ADOCONN_H1__C71F546E_CB79_494E_BA57_A7A10D10C067__INCLUDED_)
#define AFX_ADOCONN_H1__C71F546E_CB79_494E_BA57_A7A10D10C067__INCLUDED_
#include "ADOConn.h"
#if _MSG_VER > 1000
#pragma once
//ADOConn.h:interface for the ADOConn class
// CDialogAddReader 对话框
#endif
class CDialogAddReader : public CDialog
{
	DECLARE_DYNAMIC(CDialogAddReader)

public:
	CDialogAddReader(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogAddReader();

// 对话框数据
	enum { IDD = IDD_ADDREADER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strRID;
	CString m_strRName;
	int m_nMaxNUm;
	CComboBox m_dropList;
	afx_msg void OnBnClickedOk();
	CADOConn m_ado;
	afx_msg void OnCbnSelchangeReadertype();
	virtual BOOL OnInitDialog();
};
#endif