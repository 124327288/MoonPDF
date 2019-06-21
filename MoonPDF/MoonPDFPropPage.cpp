// MoonPDFPropPage.cpp : CMoonPDFPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "MoonPDF.h"
#include "MoonPDFPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMoonPDFPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CMoonPDFPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CMoonPDFPropPage, "MOONPDF.MoonPDFPropPage.1",
	0x3936d858, 0x49ff, 0x462e, 0x8b, 0xd8, 0x80, 0x37, 0x48, 0x64, 0xb2, 0xe3)

// CMoonPDFPropPage::CMoonPDFPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CMoonPDFPropPage ��ϵͳע�����

BOOL CMoonPDFPropPage::CMoonPDFPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MOONPDF_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CMoonPDFPropPage::CMoonPDFPropPage - ���캯��

CMoonPDFPropPage::CMoonPDFPropPage() :
	COlePropertyPage(IDD, IDS_MOONPDF_PPG_CAPTION)
{
}

// CMoonPDFPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CMoonPDFPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CMoonPDFPropPage ��Ϣ�������
