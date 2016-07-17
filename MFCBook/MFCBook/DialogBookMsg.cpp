// DialogBookMsg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCBook.h"
#include "DialogBookMsg.h"
#include "afxdialogex.h"


// CDialogBookMsg �Ի���

IMPLEMENT_DYNAMIC(CDialogBookMsg, CDialog)

CDialogBookMsg::CDialogBookMsg(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogBookMsg::IDD, pParent)
	, m_strBID(_T(""))
	, m_strBName(_T(""))
	, m_strBAuthor(_T(""))
	, m_fBPress(0)
	, m_strBPress(_T(""))
	, m_time(0)
	, m_strFlag(_T(""))
	, m_nMaxNu(0)
{
	/*//�����б�
	m_ctrList.InsertColumn(0, L"ͼ����");
	m_ctrList.InsertColumn(1, L"ͼ������");
	m_ctrList.InsertColumn(2, L"ͼ�����");
	m_ctrList.InsertColumn(3, L"����");
	m_ctrList.InsertColumn(4, L"������");
	m_ctrList.InsertColumn(5, L"ͼ��۸�");
	m_ctrList.InsertColumn(6, L"�Ǽ�����");
	m_ctrList.InsertColumn(7, L"��ע˵��");
	m_ctrList.SetColumnWidth(0, 60);
	m_ctrList.SetColumnWidth(1, 120);
	m_ctrList.SetColumnWidth(2, 80);
	m_ctrList.SetColumnWidth(3, 80);
	m_ctrList.SetColumnWidth(4, 80);
	m_ctrList.SetColumnWidth(5, 80);
	m_ctrList.SetColumnWidth(6, 80);
	m_ctrList.SetColumnWidth(7, 80);
	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);*/
}

CDialogBookMsg::~CDialogBookMsg()
{
}

void CDialogBookMsg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FINDLIST, m_ctrList);
	DDX_Text(pDX, IDC_ISBN, m_strBID);
	DDV_MaxChars(pDX, m_strBID, 20);
	DDX_Text(pDX, IDC_NAME, m_strBName);
	DDV_MaxChars(pDX, m_strBName, 20);
	DDX_Text(pDX, IDC_AUTHOR, m_strBAuthor);
	DDV_MaxChars(pDX, m_strBAuthor, 20);
	DDX_Text(pDX, IDC_PRICE, m_fBPress);
	DDV_MinMaxFloat(pDX, m_fBPress, 0, 9999);
	DDX_Control(pDX, IDC_TYPE, m_list);
	DDX_Text(pDX, IDC_PRESS, m_strBPress);
	DDV_MaxChars(pDX, m_strBPress, 40);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_time);
	DDX_Text(pDX, IDC_STATUS, m_strFlag);
	DDV_MaxChars(pDX, m_strFlag, 20);
	DDX_Text(pDX, IDC_HOWMANY, m_nMaxNu);
	DDV_MinMaxInt(pDX, m_nMaxNu, 0, 999);
}


BEGIN_MESSAGE_MAP(CDialogBookMsg, CDialog)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_FINDLIST, &CDialogBookMsg::OnLvnItemchangedFindlist)
	ON_BN_CLICKED(IDC_BOOKMSGPRINTALL, &CDialogBookMsg::OnBnClickedBookmsgprintall)
	ON_NOTIFY(NM_CLICK, IDC_FINDLIST, &CDialogBookMsg::OnNMClickFindlist)
	ON_BN_CLICKED(IDC_BOOKMSGCHANGE, &CDialogBookMsg::OnBnClickedBookmsgchange)
	ON_BN_CLICKED(IDC_BOOKMSGDEL, &CDialogBookMsg::OnBnClickedBookmsgdel)
	ON_BN_CLICKED(IDC_BOOKMSGADD, &CDialogBookMsg::OnBnClickedBookmsgadd)
END_MESSAGE_MAP()


// CDialogBookMsg ��Ϣ�������


void CDialogBookMsg::OnLvnItemchangedFindlist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
	*pResult = 0;
}


void CDialogBookMsg::OnBnClickedBookmsgprintall()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

}


BOOL CDialogBookMsg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_ctrList.DeleteAllItems();
	//m_list.DeleteColumn()
	m_ctrList.InsertColumn(0, L"ͼ��ID", LVCFMT_LEFT, 100);
	m_ctrList.InsertColumn(1, L"ͼ������", LVCFMT_LEFT, 100);
	m_ctrList.InsertColumn(2, L"����", LVCFMT_LEFT, 100);
	m_ctrList.InsertColumn(3, L"������", LVCFMT_LEFT, 100);
	m_ctrList.InsertColumn(4, L"ͼ������", LVCFMT_LEFT, 100);
	m_ctrList.InsertColumn(5, L"��������", LVCFMT_LEFT, 100);
	m_ctrList.InsertColumn(6, L"�۸�", LVCFMT_LEFT, 100);
	m_ctrList.InsertColumn(7, L"�ɽ�����", LVCFMT_LEFT, 100);
	m_ctrList.InsertColumn(8, L"״̬", LVCFMT_LEFT, 100);
	m_ctrList.InsertColumn(9, L"������Ϣ", LVCFMT_LEFT, 100);
	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_ctrList.SetBkColor(RGB(244, 200, 222));
	m_ctrList.SetTextBkColor(RGB(244, 200, 222));
	m_ctrList.SetTextColor(RGB(0, 00, 60));

	m_ado.OnInitADOConn();
	CString str;
	//str.Format(L"select BID,BName,BAuthor,BPress,BRress_date,BFlag_Borrow,BDesc,BPrice,t.Typename,DaysCanBorrow from  Book b,BookType t where b.BType=t.BType");
	str.Format(L"select BID,BName,BAuthor,BPress,BRress_date,BFlag_Borrow,BDesc,BPrice from  Book ");
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
			AfxMessageBox(L"��ͼ�����ֲ���Ԥ�ϵĴ���");
			return FALSE;
		}
		CString str;
		int i = 0;
		_variant_t var;
		while (!m_ado.m_pRecordset->adoEOF)
		{
			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("BID"))->Value));
			m_ctrList.InsertItem(i, str);
			//m_list.SetItemText(i, 1, str);
			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("BName"))->Value));
			m_ctrList.SetItemText(i, 1, str);

			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("BAuthor"))->Value));
			m_ctrList.SetItemText(i, 2, str);
			 
			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("BPress"))->Value));
			m_ctrList.SetItemText(i, 3, str);

			//var = (_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("Typename"))->Value);
			//if (var.vt != VT_NULL)   //ΪNULL
			//{
			//	str = var;
			//}
			//else
			//{
			//	str = L"";
			//}
			// m_ctrList.SetItemText(i, 4, str);

			//str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("BRress_date"))->Value));
			//m_ctrList.SetItemText(i, 5, str);

			//str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("BPrice"))->Value));
			//m_ctrList.SetItemText(i, 6, str);
			var = (_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("BPrice"))->Value);
			if (var.vt != VT_NULL)   //ΪNULL
			{
				str = var;
			}
			else
			{
				str = L"";
			}
			m_ctrList.SetItemText(i, 6, str);

			//var = (_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("DaysCanBorrow"))->Value);
			//long n;
			//if (var.vt != VT_NULL)   //ΪNULL
			//{
				//n = var.lVal;
			//	str = var;
			//}
			//else
			//{
			//	n = 0;
			//}
			//str.Format(L"%d", n);
		//	m_ctrList.SetItemText(i, 7, str);

			//long n = (m_ado.m_pRecordset->Fields->GetItem(_variant_t("DaysCanBorrow"))->Value).lVal;
			//str.Format(L"%d", n);
			//m_ctrList.SetItemText(i, 7, str);
			var = (_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("BFlag_Borrow"))->Value);
			if (var.vt != VT_NULL)   //ΪNULL
			{
				str = var;
			}
			else
			{
				str = L"";
			}
			m_ctrList.SetItemText(i, 8, str);
			//str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("BFlag_Borrow"))->Value));
			//m_ctrList.SetItemText(i, 8, str);
			var = (_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("BDesc"))->Value);
			if (var.vt != VT_NULL)   //ΪNULL
			{
				str = var;
			}
			else
			{
				str = L"";
			}
			m_ctrList.SetItemText(i, 9, str);

			//str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("BDesc"))->Value));
			//m_ctrList.SetItemText(i, 9, str);

			m_ado.m_pRecordset->MoveNext();
			AfxMessageBox(L"�ҵ�һ����¼");
			i++;
		}
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CDialogBookMsg::OnNMClickFindlist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;
	int nId;
	//���ȵõ������λ��
	POSITION pos = m_ctrList.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		AfxMessageBox(TEXT("������ѡ��һ��"));
		return;
	}
	//�õ��кţ�ͨ��POSITIONת��
	nId = (int)m_ctrList.GetNextSelectedItem(pos);
	//�õ����е����ݣ�0��ʾ��һ�У�ͬ��1,2,3...��ʾ�ڶ���������...�У�
	m_strBID = m_ctrList.GetItemText(nId, 0);
	m_strBName = m_ctrList.GetItemText(nId, 1);
	m_strBAuthor = m_ctrList.GetItemText(nId, 2);
	m_strBPress = m_ctrList.GetItemText(nId, 3);
	//m_strType= m_ctrList.GetItemText(nId, 4);
	//m_strBID = m_ctrList.GetItemText(nId, 5);
	//m_strBID = m_ctrList.GetItemText(nId, 6);
	//m_nMaxNU = m_ctrList.GetItemText(nId, 7);
	//m_strFlag = m_ctrList.GetItemText(nId, 8);
	// = m_ctrList.GetItemText(nId, 8);
	
	UpdateData(false);
	AfxMessageBox(str);
	/*
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
			AfxMessageBox(L"ɾ���ɹ�");
			this->OnInitDialog();
		}
		else
		{
			AfxMessageBox(L"�����ͼ�¼���ֲ���Ԥ�ϵĴ���");
		}
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}*/
	*pResult = 0;
}


void CDialogBookMsg::OnBnClickedBookmsgchange()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData();

	//CString str;
	int nId;
	//���ȵõ������λ��
	POSITION pos = m_ctrList.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		AfxMessageBox(TEXT("������ѡ��һ��"));
		return;
	}
	//�õ��кţ�ͨ��POSITIONת��
	nId = (int)m_ctrList.GetNextSelectedItem(pos);
	//�õ����е����ݣ�0��ʾ��һ�У�ͬ��1,2,3...��ʾ�ڶ���������...�У�
	CString str,sql;
	str.Format(L"update book set BName = '");
	sql = str + m_strBName + L"',BAuthor='" + m_strBAuthor + L"',BPress='" + m_strBPress + L"' where BID = '" + m_strBID+L"'";
	AfxMessageBox(sql);
	_bstr_t vSQL;
	vSQL = (_bstr_t)sql;
	try
	{
		if (m_ado.ExecuteSQL(vSQL))
		{
			AfxMessageBox(L"�޸ĳɹ�");
			this->OnInitDialog();
		}
		else
		{
			AfxMessageBox(L"�޸Ĺ��̳��ֲ���Ԥ�ϵĴ���");
		}
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}


void CDialogBookMsg::OnBnClickedBookmsgdel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int nId;
	//���ȵõ������λ��
	POSITION pos = m_ctrList.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		AfxMessageBox(TEXT("������ѡ��һ��"));
		return;
	}
	//�õ��кţ�ͨ��POSITIONת��
	nId = (int)m_ctrList.GetNextSelectedItem(pos);
	//�õ����е����ݣ�0��ʾ��һ�У�ͬ��1,2,3...��ʾ�ڶ���������...�У�
	CString str, sql;
	str.Format(L"delete from book where BID='");
	sql = str + m_strBID + L"'";
	AfxMessageBox(sql);
	_bstr_t vSQL;
	vSQL = (_bstr_t)sql;
	try
	{
		if (m_ado.ExecuteSQL(vSQL))
		{
			AfxMessageBox(L"ɾ���ɹ�");
			this->OnInitDialog();
		}
		else
		{
			AfxMessageBox(L"ɾ�����̳��ֲ���Ԥ�ϵĴ���");
		}
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}


void CDialogBookMsg::OnBnClickedBookmsgadd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	CString str, sql;
	str.Format(L"insert into book(BName,BAuthor,BPress,BID) values( '");
	sql = str + m_strBName + L"','" + m_strBAuthor + L"','" + m_strBPress + L"' , '" + m_strBID + L"')";
	AfxMessageBox(sql);
	_bstr_t vSQL;
	vSQL = (_bstr_t)sql;

	try
	{
		if (m_ado.ExecuteSQL(vSQL))
		{
			AfxMessageBox(L"��ӳɹ�");
			this->OnInitDialog();
		}
		else
		{
			AfxMessageBox(L"��ӹ��̳��ֲ���Ԥ�ϵĴ���");
		}
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}
