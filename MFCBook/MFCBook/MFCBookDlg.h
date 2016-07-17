
// MFCBookDlg.h : ͷ�ļ�
//

#pragma once


// CMFCBookDlg �Ի���
class CMFCBookDlg : public CDialogEx
{
// ����
public:
	CMFCBookDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCBOOK_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
