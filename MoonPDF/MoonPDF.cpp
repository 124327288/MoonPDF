// MoonPDF.cpp : CMoonPDFApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "MoonPDF.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMoonPDFApp theApp;

const GUID CDECL _tlid = { 0xCD40F6A, 0x42E2, 0x41DE, { 0x95, 0xA4, 0xF7, 0x4D, 0xC7, 0xF2, 0x71, 0x2C } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMoonPDFApp::InitInstance - DLL ��ʼ��

BOOL CMoonPDFApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CMoonPDFApp::ExitInstance - DLL ��ֹ

int CMoonPDFApp::ExitInstance()
{
	// TODO:  �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
