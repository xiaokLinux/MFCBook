// DialogAddAdmin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCBook.h"
#include "DialogAddAdmin.h"
#include "afxdialogex.h"


// CDialogAddAdmin �Ի���

IMPLEMENT_DYNAMIC(CDialogAddAdmin, CDialog)

CDialogAddAdmin::CDialogAddAdmin(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogAddAdmin::IDD, pParent)
	, m_strID(_T(""))
	, m_strName(_T(""))
	, m_strPWD(_T(""))
	, m_strPWDAgain(_T(""))
{

}

CDialogAddAdmin::~CDialogAddAdmin()
{
}

void CDialogAddAdmin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ADMINID, m_strID);
	DDV_MaxChars(pDX, m_strID, 10);
	DDX_Text(pDX, IDC_ADMINNAME, m_strName);
	DDV_MaxChars(pDX, m_strName, 20);
	DDX_Text(pDX, IDC_ADMINPSW, m_strPWD);
	DDV_MaxChars(pDX, m_strPWD, 20);
	DDX_Text(pDX, IDC_ADMINPSWAGIN, m_strPWDAgain);
	DDV_MaxChars(pDX, m_strPWDAgain, 20);
}


BEGIN_MESSAGE_MAP(CDialogAddAdmin, CDialog)
	ON_BN_CLICKED(IDOK, &CDialogAddAdmin::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialogAddAdmin ��Ϣ�������


void CDialogAddAdmin::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	if (m_strPWD.IsEmpty() || m_strName.IsEmpty())
	{
		AfxMessageBox(TEXT("��δ����"));
		return;
	}
	if (m_strPWD != m_strPWDAgain)
	{
		AfxMessageBox(TEXT("���벻һ��"));
		m_strPWDAgain.Format(TEXT(""));
		return;
	}
	else
	{
		m_ado.OnInitADOConn();
		CString str, sql;
		str.Format(L"select * from Admin where AID='");
		sql = str + m_strID;
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
				str.Format(L"insert into Admin values('");
				sql = str + m_strID;
				str.Format(L"','");
				sql += str+m_strPWD+str+m_strName;

				str.Format(L"')");
				sql += str;
				vSQL = (_bstr_t)sql;
				AfxMessageBox(sql);

				if (m_ado.ExecuteSQL(vSQL))
					AfxMessageBox(TEXT("add admin successed"));
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
