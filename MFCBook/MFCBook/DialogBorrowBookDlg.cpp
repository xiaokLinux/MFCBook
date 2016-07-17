// DialogBorrowBookDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCBook.h"
#include "DialogBorrowBookDlg.h"
#include "afxdialogex.h"


// CDialogBorrowBookDlg 对话框

IMPLEMENT_DYNAMIC(CDialogBorrowBookDlg, CDialog)

CDialogBorrowBookDlg::CDialogBorrowBookDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogBorrowBookDlg::IDD, pParent)
	, m_strRID(_T(""))
	, m_strBID(_T(""))
	, m_strRName(_T(""))
	, m_nMaxNu(0)
	, m_strType(_T(""))
	, m_nHavaBorrow(0)
	, m_strBName(_T(""))
	, m_strBAuthor(_T(""))
	, m_strBPress(_T(""))
	, m_strFlag(_T(""))
{

}

CDialogBorrowBookDlg::~CDialogBorrowBookDlg()
{
}

void CDialogBorrowBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_BORROWREADERID, m_strRID);
	DDX_Text(pDX, IDC_BORROWBOOKISBN, m_strBID);
	DDX_Text(pDX, IDC_BORROWREADERNAE, m_strRName);
	DDV_MaxChars(pDX, m_strRName, 20);
	DDX_Text(pDX, IDC_BORROWMAXNU, m_nMaxNu);
	DDV_MinMaxInt(pDX, m_nMaxNu, 0, 999);
	DDX_Text(pDX, IDC_BORROWTYPE, m_strType);
	DDV_MaxChars(pDX, m_strType, 20);
	DDX_Text(pDX, IDC_BORROWVCOUNTNU, m_nHavaBorrow);
	DDV_MinMaxInt(pDX, m_nHavaBorrow, 0, 999);
	DDX_Text(pDX, IDC_BORROWBOOKNAME, m_strBName);
	DDV_MaxChars(pDX, m_strBName, 20);
	DDX_Text(pDX, IDC_BORROWBOOKAUTHOR, m_strBAuthor);
	DDV_MaxChars(pDX, m_strBAuthor, 20);
	DDX_Text(pDX, IDC_BORROWBOOKPRESS, m_strBPress);
	DDV_MaxChars(pDX, m_strBPress, 20);
	DDX_Text(pDX, IDC_BORROWBOOKSTATUS, m_strFlag);
	DDV_MaxChars(pDX, m_strFlag, 20);
}


BEGIN_MESSAGE_MAP(CDialogBorrowBookDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CDialogBorrowBookDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialogBorrowBookDlg 消息处理程序


void CDialogBorrowBookDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	if (m_strBID.IsEmpty() || m_strRID.IsEmpty())
	{
		AfxMessageBox(L"书号或者借书号为空");
		return;
	}
	m_ado.OnInitADOConn();
	CString str,sql;
	str.Format(L"select * from  reader where RID='");
	sql = str + m_strRID;
	str.Format(L"'");
	sql += str;
	_bstr_t vSQL;
	vSQL = (_bstr_t)sql;
	AfxMessageBox(sql);
	try
	{
		m_ado.m_pRecordset = m_ado.GetRecordSet(vSQL);
		if (!m_ado.m_pRecordset->adoBOF)
		{
			m_ado.m_pRecordset->MoveFirst();
		}
		else
		{
			AfxMessageBox(L"打开读者表出现不可预料的错误");
			return ;
		}
		CString buf;
		int i = 0;
		while (!m_ado.m_pRecordset->adoEOF)
		{
			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("RID"))->Value));
			

			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("RName"))->Value));


			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("RType"))->Value));


			long n = (m_ado.m_pRecordset->Fields->GetItem(_variant_t("RMaxNum_Can_borrow"))->Value).lVal;


			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("RFlag_Borrow"))->Value));

			m_ado.m_pRecordset->MoveNext();
			//AfxMessageBox(L"找到一条记录");
			i++;
		}
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}
	CDialog::OnOK();
}
