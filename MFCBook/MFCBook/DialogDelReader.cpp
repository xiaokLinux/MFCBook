// DialogDelReader.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCBook.h"
#include "DialogDelReader.h"
#include "afxdialogex.h"


// CDialogDelReader �Ի���

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


// CDialogDelReader ��Ϣ�������


void CDialogDelReader::OnBnClickedDelreader()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;
	int nId;
	//���ȵõ������λ��
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		AfxMessageBox(TEXT("������ѡ��һ��"));
		return;
	}
	//�õ��кţ�ͨ��POSITIONת��
	nId = (int)m_list.GetNextSelectedItem(pos);
	//�õ����е����ݣ�0��ʾ��һ�У�ͬ��1,2,3...��ʾ�ڶ���������...�У�
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
			AfxMessageBox(L"ɾ���ɹ�");
			this->OnInitDialog();
		}
		else
		{
			AfxMessageBox(L"�����ͼ�¼���ֲ���Ԥ�ϵĴ���");
		}
		//��ʾ����
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_list.DeleteAllItems();
	//m_list.DeleteColumn()
	m_list.InsertColumn(0, L"����ID", LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, L"��������", LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, L"��������", LVCFMT_LEFT, 100);
	m_list.InsertColumn(3, L"�ɽ�����", LVCFMT_LEFT, 100);
	m_list.InsertColumn(4, L"������Ϣ", LVCFMT_LEFT, 100);
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
			AfxMessageBox(L"�򿪶��߱���ֲ���Ԥ�ϵĴ���");
			return FALSE;
		}
		//��ʾ����
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
			//AfxMessageBox(L"�ҵ�һ����¼");
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
