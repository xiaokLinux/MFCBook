#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")
#if !defined(AFX_ADOCONN_H__C71F5466_CB79_494E_BA57_A7A10D10C067__INCLUDED_)
#define AFX_ADOCONN_H__C71F5466_CB79_494E_BA57_A7A10D10C067__INCLUDED_
#include "ADOConn.h"
#if _MSG_VER > 1000
#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "atltime.h"
//ADOConn.h:interface for the ADOConn class
#endif //_MSG_VER >1000



// CDialogBookMsg 对话框

class CDialogBookMsg : public CDialog
{
	DECLARE_DYNAMIC(CDialogBookMsg)

public:
	CDialogBookMsg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogBookMsg();

// 对话框数据
	enum { IDD = IDD_BOOKMSG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedFindlist(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_ctrList;
	CString m_strBID;
	CString m_strBName;
	CString m_strBAuthor;
	float m_fBPress;
	CComboBox m_list;
	CString m_strBPress;
	CTime m_time;
	CString m_strFlag;
	int m_nMaxNu;
	afx_msg void OnBnClickedBookmsgprintall();
	CADOConn m_ado;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMClickFindlist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBookmsgchange();
	afx_msg void OnBnClickedBookmsgdel();
	afx_msg void OnBnClickedBookmsgadd();
};
#endif