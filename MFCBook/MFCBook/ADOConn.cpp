#include "stdafx.h"
#include "ADOConn.h"


CADOConn::CADOConn()
{
}


CADOConn::~CADOConn()
{
}
//关闭连接
void CADOConn::ExitConnect()
{
	//关闭记录集和连接
	if (m_pRecordset != NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
	//释放环境
	::CoUninitialize();
}
//执行SQL
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
	//初始化OLE/COM库环境
	::CoInitialize(NULL);
	try
	{
		//创建Connection连接对象
		m_pConnection.CreateInstance("ADODB.Connection");
		//设置连接字符串，必须是BSTR型或者_bstr_t类型
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
//执行查询，未测试
_RecordsetPtr& CADOConn::GetRecordSet(_bstr_t bstrSQL)
{
	try
	{
		//连接数据库,如果Connection对象为空，则重新连接数据库
		if (m_pConnection == NULL)
			OnInitADOConn();
		//创建记录集对象
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		//取得表中的记录
		m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch (_com_error e)
	{
		//显示错误信息
		AfxMessageBox(e.Description());
	}
	//返回记录集
	return m_pRecordset;
}
