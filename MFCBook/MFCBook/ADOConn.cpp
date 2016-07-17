#include "stdafx.h"
#include "ADOConn.h"


CADOConn::CADOConn()
{
}


CADOConn::~CADOConn()
{
}
//�ر�����
void CADOConn::ExitConnect()
{
	//�رռ�¼��������
	if (m_pRecordset != NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
	//�ͷŻ���
	::CoUninitialize();
}
//ִ��SQL
BOOL CADOConn::ExecuteSQL(_bstr_t bstrSQL)
{
	try {
		if (m_pConnection == NULL)
			OnInitADOConn();
		m_pConnection->Execute(bstrSQL, NULL, adCmdText);
		return true;
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
		return false;
	}

}
//
void CADOConn::OnInitADOConn()
{
//	AfxMessageBox(L"Begin");
	//��ʼ��OLE/COM�⻷��
	::CoInitialize(NULL);
	try
	{
		//����Connection���Ӷ���
		m_pConnection.CreateInstance("ADODB.Connection");
		//���������ַ�����������BSTR�ͻ���_bstr_t����
		_bstr_t strConnect = "Driver={sql server};server=.;uid=sa;pwd=sa;database=Libray";  //SQLSERVER
		//_bstr_t strConnect = "DSN={sql server};server=(local);uid=sa;pwd="sa";database=Library";  //SQLSERVER
		//m_pConnection->Open("Provider={sql server}; Server=.;Database=Library; uid=sa; pwd=sa;", "", "", adModeUnknown);
		m_pConnection->Open(strConnect, "", "", NULL);
	}
	catch (_com_error e)
	{
		AfxMessageBox(e.Description());
	}
//	AfxMessageBox(L"End");
}
//ִ�в�ѯ��δ����
_RecordsetPtr& CADOConn::GetRecordSet(_bstr_t bstrSQL)
{
	try
	{
		//�������ݿ�,���Connection����Ϊ�գ��������������ݿ�
		if (m_pConnection == NULL)
			OnInitADOConn();
		//������¼������
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		//ȡ�ñ��еļ�¼
		m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch (_com_error e)
	{
		//��ʾ������Ϣ
		AfxMessageBox(e.Description());
	}
	//���ؼ�¼��
	return m_pRecordset;
}
