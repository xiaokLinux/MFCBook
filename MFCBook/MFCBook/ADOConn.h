#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF","adoEOF") rename("BOF","adoBOF")
#if !defined(AFX_ADOCONN_H__C61F546E_CB79_494E_BA57_A7A10D10C067__INCLUDED_)
#define AFX_ADOCONN_H__C61F546E_CB79_494E_BA57_A7A10D10C067__INCLUDED_
#if _MSG_VER > 1000
#pragma once
//ADOConn.h:interface for the ADOConn class
#endif //_MSG_VER >1000
class CADOConn
{
public:
	CADOConn();
	~CADOConn();
public:
	void ExitConnect();
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	void OnInitADOConn();
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);	//执行查询
public:
	_ConnectionPtr m_pConnection;			//指向Connection对象的指针
	_RecordsetPtr  m_pRecordset;			//指向Recordset对象的指针
};
#endif//!defined(AFX_ADOCONN_H__C61F546E_CB79_494E_BA57_A7A10D10C067__INCLUDED_)
