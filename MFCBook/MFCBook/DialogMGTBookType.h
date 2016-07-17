#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")
#if !defined(AFX_ADOCONN_H__C71F546E_CB79_494E_BA57_A7A10D10C666__INCLUDED_)
#define AFX_ADOCONN_H__C71F546E_CB79_494E_BA57_A7A10D10C666__INCLUDED_
#include "ADOConn.h"
#if _MSG_VER > 1000
#pragma once
//ADOConn.h:interface for the ADOConn class
// CDialogMGTBookType 对话框
#endif//_MSG_VER >1000
class CDialogMGTBookType : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogMGTBookType)

public:
	CDialogMGTBookType(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogMGTBookType();

// 对话框数据
	enum { IDD = IDD_MGTBOOKTYPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_list;
	CString m_strTID;
	CString m_strTname;
	int m_nMaxNu;
	afx_msg void OnBnClickedAddtype();
	virtual BOOL OnInitDialog();
	CADOConn m_ado;
	afx_msg void OnLbnSelchangeBooktypelist();
};
#endif