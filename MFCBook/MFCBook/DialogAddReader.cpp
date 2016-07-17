// DialogAddReader.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCBook.h"
#include "DialogAddReader.h"
#include "afxdialogex.h"
#include <vector>


// CDialogAddReader �Ի���

IMPLEMENT_DYNAMIC(CDialogAddReader, CDialog)

CDialogAddReader::CDialogAddReader(CWnd* pParent /*=NULL*/)
: CDialog(CDialogAddReader::IDD, pParent)
, m_strRID(_T(""))
, m_strRName(_T(""))
, m_nMaxNUm(0)
{
}

CDialogAddReader::~CDialogAddReader()
{
}

void CDialogAddReader::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ADDREADERID, m_strRID);
	DDV_MaxChars(pDX, m_strRID, 20);
	DDX_Text(pDX, IDC_ADDREADERNAME, m_strRName);
	DDV_MaxChars(pDX, m_strRName, 20);
	DDX_Text(pDX, IDC_READERMANY, m_nMaxNUm);
	DDV_MinMaxInt(pDX, m_nMaxNUm, 0, 1000);
	DDX_Control(pDX, IDC_READERTYPE, m_dropList);


}


BEGIN_MESSAGE_MAP(CDialogAddReader, CDialog)
	ON_BN_CLICKED(IDOK, &CDialogAddReader::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_READERTYPE, &CDialogAddReader::OnCbnSelchangeReadertype)
END_MESSAGE_MAP()


// CDialogAddReader ��Ϣ�������


void CDialogAddReader::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData();
	if (m_strRID.IsEmpty() || m_strRName.IsEmpty() || m_dropList.GetCurSel()==-1)
	{
		AfxMessageBox(TEXT("��δ����"));
		return;
	}
	else
	{
		m_ado.OnInitADOConn();
		CString str, sql;
		str.Format(L"select * from reader where RID='");
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
				AfxMessageBox(TEXT("�����ظ���ID,����������"));
				//m_ado.m_pRecordset->MoveFirst();
			}
			else
			{
				str.Format(L"insert into Reader values('");
				sql = str + m_strRID;
				str.Format(L"','");
				CString x;
				m_dropList.GetLBText(m_dropList.GetCurSel(),x);
				
				sql += str + m_strRName + str + x;
				str.Format(L"',%d,'", m_nMaxNUm);
				sql+=str;

				str.Format(L"')");
				sql += str;
				vSQL = (_bstr_t)sql;
				AfxMessageBox(sql);

				if (m_ado.ExecuteSQL(vSQL))
					AfxMessageBox(TEXT("add reader successed"));
				else
				{
					AfxMessageBox(TEXT("����ǰ��δ�еĴ���"));
				}
				return;
			}
			m_ado.ExitConnect();
		}
		catch (_com_error e)
		{
			AfxMessageBox(e.Description());
		}
	}



	CDialog::OnOK();
}


void CDialogAddReader::OnCbnSelchangeReadertype()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


BOOL CDialogAddReader::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	/*
	m_ado.OnInitADOConn();
	CString sql;
	sql.Format(L"select * from Booktype");
	_bstr_t vSQL;
	vSQL = (_bstr_t)sql;

	try
	{
		m_ado.m_pRecordset = m_ado.GetRecordSet(vSQL);
		if (!m_ado.m_pRecordset->adoBOF)
		{
			m_ado.m_pRecordset->MoveFirst();
		}
		else
		{
			AfxMessageBox(L"�����ͼ�¼���ֲ���Ԥ�ϵĴ���");
			return FALSE;
		}
		//��ʾ����
		/*for (int i = 0; i < m_ado.m_pRecordset->Fields->GetCount(); i++)
		{

		}*//*
		CString str;
		while (!m_ado.m_pRecordset->adoEOF)
		{
			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("TypeName"))->Value));
			m_dropList.AddString(str);
			m_ado.m_pRecordset->MoveNext();
			//	AfxMessageBox(L"�ҵ�һ����¼");
		}
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}
	*/
	m_dropList.AddString(L"ѧ��");
	m_dropList.AddString(L"��ʦ");
	m_dropList.AddString(L"��Ա");
	m_dropList.AddString(L"�о���");
	m_dropList.AddString(L"�߼���Ա");
	m_dropList.AddString(L"����Ա");
	//AfxMessageBox(L"stop");
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
