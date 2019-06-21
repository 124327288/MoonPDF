#pragma once

// MoonPDF.h : MoonPDF.DLL ����ͷ�ļ�

#if !defined( __AFXCTL_H__ )
#error "�ڰ������ļ�֮ǰ������afxctl.h��"
#endif

#include "resource.h"       // ������


// CMoonPDFApp : �й�ʵ�ֵ���Ϣ������� MoonPDF.cpp��

class CMoonPDFApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//����mupdf��ؿ⣬ʹ�õĿ�汾Ϊ��mupdf-1.15.0
#ifdef DEBUG
#pragma comment(lib, "lib\\debug\\libmupdf.lib")
#pragma comment(lib, "lib\\debug\\libresources.lib")
#pragma comment(lib, "lib\\debug\\libthirdparty.lib")
#else
#pragma comment(lib, "lib\\release\\libmupdf.lib")
#pragma comment(lib, "lib\\release\\libresources.lib")
#pragma comment(lib, "lib\\release\\libthirdparty.lib")
#endif