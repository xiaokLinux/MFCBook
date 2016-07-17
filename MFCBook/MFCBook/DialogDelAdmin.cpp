// DialogDelAdmin.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCBook.h"
#include "DialogDelAdmin.h"
#include "afxdialogex.h"


// CDialogDelAdmin 对话框

IMPLEMENT_DYNAMIC(CDialogDelAdmin, CDialogEx)

CDialogDelAdmin::CDialogDelAdmin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogDelAdmin::IDD, pParent)
{

}

CDialogDelAdmin::~CDialogDelAdmin()
{
}

void CDialogDelAdmin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ADMINLIST, m_list);

	/*
	m_ado.OnInitADOConn();
	CString str;
	str.Format(L"select * from  admin");
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
			AfxMessageBox(L"打开管理员表出现不可预料的错误");
		}
		CString str;
		int i = 0;
		while (!m_ado.m_pRecordset->adoEOF)
		{
			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("AID"))->Value));
			m_list.InsertItem(i, str);
			//m_list.SetItemText(i, 1, str);
			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("AName"))->Value));
			m_list.SetItemText(i, 1, str);

			m_ado.m_pRecordset->MoveNext();
			//AfxMessageBox(L"找到一条记录");
			i++;
		}
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}
*/
}


BEGIN_MESSAGE_MAP(CDialogDelAdmin, CDialogEx)
	ON_BN_CLICKED(IDC_DEL, &CDialogDelAdmin::OnBnClickedDel)
END_MESSAGE_MAP()


// CDialogDelAdmin 消息处理程序


BOOL CDialogDelAdmin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_list.DeleteAllItems();
	//m_list.DeleteColumn()
	m_list.InsertColumn(0, L"管理员ID", LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, L"管理员登录名", LVCFMT_LEFT, 100);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_list.SetBkColor(RGB(244, 200, 222));
	m_list.SetTextBkColor(RGB(244, 200, 222));
	m_list.SetTextColor(RGB(0, 00, 60));
	
	m_ado.OnInitADOConn();
	CString str;
	str.Format(L"select * from  admin");
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
			AfxMessageBox(L"打开管理员表出现不可预料的错误");
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
			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("AID"))->Value));
			m_list.InsertItem(i, str);	
			//m_list.SetItemText(i, 1, str);
			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("AName"))->Value));	
			m_list.SetItemText(i, 1, str);

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


void CDialogDelAdmin::OnBnClickedDel()
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
	sql.Format(L"delete from admin where AID = '");
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
