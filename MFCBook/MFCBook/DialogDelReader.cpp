// DialogDelReader.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCBook.h"
#include "DialogDelReader.h"
#include "afxdialogex.h"


// CDialogDelReader 对话框

IMPLEMENT_DYNAMIC(CDialogDelReader, CDialogEx)

CDialogDelReader::CDialogDelReader(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogDelReader::IDD, pParent)
{

}

CDialogDelReader::~CDialogDelReader()
{
}

void CDialogDelReader::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_READERLIST, m_List);
	DDX_Control(pDX, IDC_READERLIST, m_list);
}


BEGIN_MESSAGE_MAP(CDialogDelReader, CDialogEx)
	ON_BN_CLICKED(IDC_DELREADER, &CDialogDelReader::OnBnClickedDelreader)
END_MESSAGE_MAP()


// CDialogDelReader 消息处理程序


void CDialogDelReader::OnBnClickedDelreader()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str;
	int nId;
	//首先得到点击的位置
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		AfxMessageBox(TEXT("请至少选择一项"));
		return;
	}
	//得到行号，通过POSITION转化
	nId = (int)m_list.GetNextSelectedItem(pos);
	//得到列中的内容（0表示第一列，同理1,2,3...表示第二，三，四...列）
	str = m_list.GetItemText(nId, 0);

	CString sql;
	sql.Format(L"delete from reader where RID = '");
	sql += str;
	str.Format(L"'");
	sql += str;
	_bstr_t vSQL;
	vSQL = (_bstr_t)sql;
	AfxMessageBox(sql);

	try
	{
		if (m_ado.ExecuteSQL(vSQL))
		{
			AfxMessageBox(L"删除成功");
			this->OnInitDialog();
		}
		else
		{
			AfxMessageBox(L"打开类型记录出现不可预料的错误");
		}
		//显示列名
		/*for (int i = 0; i < m_ado.m_pRecordset->Fields->GetCount(); i++)
		{

		}*/
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}


BOOL CDialogDelReader::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_list.DeleteAllItems();
	//m_list.DeleteColumn()
	m_list.InsertColumn(0, L"读者ID", LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, L"读者姓名", LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, L"读者类型", LVCFMT_LEFT, 100);
	m_list.InsertColumn(3, L"可借天数", LVCFMT_LEFT, 100);
	m_list.InsertColumn(4, L"附加消息", LVCFMT_LEFT, 100);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_list.SetBkColor(RGB(244, 200, 222));
	m_list.SetTextBkColor(RGB(244, 200, 222));
	m_list.SetTextColor(RGB(0, 00, 60));

	m_ado.OnInitADOConn();
	CString str;
	str.Format(L"select * from  reader");
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
			AfxMessageBox(L"打开读者表出现不可预料的错误");
			return FALSE;
		}
		//显示列名
		/*for (int i = 0; i < m_ado.m_pRecordset->Fields->GetCount(); i++)
		{

		}*/
		CString str;
		int i = 0;
		while (!m_ado.m_pRecordset->adoEOF)
		{
			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("RID"))->Value));
			m_list.InsertItem(i, str);
			//m_list.SetItemText(i, 1, str);
			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("RName"))->Value));
			m_list.SetItemText(i, 1, str);

			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("RType"))->Value));
			m_list.SetItemText(i, 2, str);

			long n=(m_ado.m_pRecordset->Fields->GetItem(_variant_t("RMaxNum_Can_borrow"))->Value).lVal;
			str.Format(L"%d", n);
			m_list.SetItemText(i, 3, str);

			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("RFlag_Borrow"))->Value));
			m_list.SetItemText(i, 4, str);
			m_ado.m_pRecordset->MoveNext();
			//AfxMessageBox(L"找到一条记录");
			i++;
		}
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
