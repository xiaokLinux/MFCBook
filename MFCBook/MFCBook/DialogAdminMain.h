#pragma once


// CDialogAdminMain �Ի���

class CDialogAdminMain : public CDialog
{
	DECLARE_DYNAMIC(CDialogAdminMain)

public:
	CDialogAdminMain(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogAdminMain();

// �Ի�������
	enum { IDD = IDD_ADMINMAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBookmgt();
	afx_msg void OnBnClickedReadermgsmgt();
	afx_msg void OnBnClickedAdminmgt();
	afx_msg void OnBnClickedBorrowmgt();
	afx_msg void OnBnClickedReturnmgt();
	afx_msg void OnBnClickedBooktypemgt();
	afx_msg void OnBnClickedDeladmin();
	afx_msg void OnBnClickedDelreader();
};
