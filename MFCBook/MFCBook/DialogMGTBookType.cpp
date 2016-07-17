// DialogMGTBookType.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCBook.h"
#include "DialogMGTBookType.h"
#include "afxdialogex.h"


// CDialogMGTBookType 对话框

IMPLEMENT_DYNAMIC(CDialogMGTBookType, CDialogEx)

CDialogMGTBookType::CDialogMGTBookType(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogMGTBookType::IDD, pParent)
	, m_strTID(_T(""))
	, m_strTname(_T(""))
	, m_nMaxNu(0)
{

}

CDialogMGTBookType::~CDialogMGTBookType()
{
}

void CDialogMGTBookType::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BOOKTYPELIST, m_list);
	DDX_Text(pDX, IDC_TYPEID, m_strTID);
	DDV_MaxChars(pDX, m_strTID, 20);
	DDX_Text(pDX, IDC_TYPENAME, m_strTname);
	DDV_MaxChars(pDX, m_strTname, 20);
	DDX_Text(pDX, IDC_NUOFBORROW, m_nMaxNu);
	DDV_MinMaxInt(pDX, m_nMaxNu, 0, 1000);

}


BEGIN_MESSAGE_MAP(CDialogMGTBookType, CDialogEx)
	ON_BN_CLICKED(IDC_ADDTYPE, &CDialogMGTBookType::OnBnClickedAddtype)
	ON_LBN_SELCHANGE(IDC_BOOKTYPELIST, &CDialogMGTBookType::OnLbnSelchangeBooktypelist)
END_MESSAGE_MAP()


// CDialogMGTBookType 消息处理程序


void CDialogMGTBookType::OnBnClickedAddtype()
{
	// TODO:  在此添加控件通知处理程序代码
}


BOOL CDialogMGTBookType::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_list.ResetContent();
	//m_list.AddString(L"test");
	/*
	m_list.DeleteAllItems();
	//m_list.DeleteColumn()
	m_list.InsertColumn(0, L"类型ID", LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, L"类型名称", LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, L"可借天数", LVCFMT_LEFT, 100);

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_list.SetBkColor(RGB(244, 200, 222));
	m_list.SetTextBkColor(RGB(244, 200, 222));
	m_list.SetTextColor(RGB(0, 00, 60));
*/
	m_ado.OnInitADOConn();
	CString str;
	str.Format(L"select * from Booktype");
	_bstr_t vSQL;
	vSQL = (_bstr_t)str;
	AfxMessageBox(str);
	try
	{
		m_ado.m_pRecordset = m_ado.GetRecordSet(vSQL);
		if (!m_ado.m_pRecordset->adoBOF)
		{
			m_ado.m_pRecordset->MoveFirst();
		}
		else
		{
			AfxMessageBox(L"打开书籍类型表出现不可预料的错误");
			return FALSE;
		}
		//显示列名
		/*for (int i = 0; i < m_ado.m_pRecordset->Fields->GetCount(); i++)
		{

		}*/
		CString str;
		while (!m_ado.m_pRecordset->adoEOF)
		{
			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("TypeName"))->Value));
			m_list.AddString(str);
		//	AfxMessageBox(L"找到一条记录");
			m_ado.m_pRecordset->MoveNext();
		}
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}

	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CDialogMGTBookType::OnLbnSelchangeBooktypelist()
{
	// TODO:  在此添加控件通知处理程序代码
	int n = m_list.GetCurSel();
	CString str;
	m_list.GetText(n, str);

	m_ado.OnInitADOConn();
	CString sql;
	sql.Format(L"select * from Booktype where TypeName='");
	sql += str;
	str.Format(L"'");
	sql =sql+ str;
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
			AfxMessageBox(L"打开书籍类型表出现不可预料的错误");
		}
		CString str;
		while (!m_ado.m_pRecordset->adoEOF)
		{
			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("TypeName"))->Value));
			m_strTname = str;
			long n = (m_ado.m_pRecordset->Fields->GetItem(_variant_t("BType"))->Value).lVal;
			str.Format(L"%d", n);
			m_strTID = str;
			n = (m_ado.m_pRecordset->Fields->GetItem(_variant_t("DaysCanBorrow"))->Value).lVal;
			m_nMaxNu = n;

			//AfxMessageBox(L"找到一条记录");
			m_ado.m_pRecordset->MoveNext();
		}
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}

	UpdateData(false);

	//AfxMessageBox(m_strTname);
}
