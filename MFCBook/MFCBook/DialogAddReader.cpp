// DialogAddReader.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCBook.h"
#include "DialogAddReader.h"
#include "afxdialogex.h"
#include <vector>


// CDialogAddReader 对话框

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


// CDialogAddReader 消息处理程序


void CDialogAddReader::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码

	UpdateData();
	if (m_strRID.IsEmpty() || m_strRName.IsEmpty() || m_dropList.GetCurSel()==-1)
	{
		AfxMessageBox(TEXT("有未填项"));
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
				AfxMessageBox(TEXT("存在重复的ID,请重新输入"));
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
					AfxMessageBox(TEXT("遇到前所未有的错误"));
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
	// TODO:  在此添加控件通知处理程序代码
}


BOOL CDialogAddReader::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
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
			AfxMessageBox(L"打开类型记录出现不可预料的错误");
			return FALSE;
		}
		//显示列名
		/*for (int i = 0; i < m_ado.m_pRecordset->Fields->GetCount(); i++)
		{

		}*//*
		CString str;
		while (!m_ado.m_pRecordset->adoEOF)
		{
			str.Format((_bstr_t)(m_ado.m_pRecordset->Fields->GetItem(_variant_t("TypeName"))->Value));
			m_dropList.AddString(str);
			m_ado.m_pRecordset->MoveNext();
			//	AfxMessageBox(L"找到一条记录");
		}
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}
	*/
	m_dropList.AddString(L"学生");
	m_dropList.AddString(L"教师");
	m_dropList.AddString(L"会员");
	m_dropList.AddString(L"研究生");
	m_dropList.AddString(L"高级会员");
	m_dropList.AddString(L"管理员");
	//AfxMessageBox(L"stop");
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
