#pragma once


// CDialogReturnBook �Ի���

class CDialogReturnBook : public CDialog
{
	DECLARE_DYNAMIC(CDialogReturnBook)

public:
	CDialogReturnBook(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogReturnBook();

// �Ի�������
	enum { IDD = IDD_RETURN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
