
// MFCBookDlg.h : 头文件
//

#pragma once


// CMFCBookDlg 对话框
class CMFCBookDlg : public CDialogEx
{
// 构造
public:
	CMFCBookDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCBOOK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnCreateAdminMain(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnCreateMgtBook(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnCreateMgtReader(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnCreateMgtAdmin(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnCreateMgtBorrow(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnCreateMgtReturn(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnCreateBookType(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDelAdmin(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDelReader(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
