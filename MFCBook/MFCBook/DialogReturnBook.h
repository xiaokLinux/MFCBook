#pragma once


// CDialogReturnBook 对话框

class CDialogReturnBook : public CDialog
{
	DECLARE_DYNAMIC(CDialogReturnBook)

public:
	CDialogReturnBook(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogReturnBook();

// 对话框数据
	enum { IDD = IDD_RETURN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
