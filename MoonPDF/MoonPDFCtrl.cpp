// MoonPDFCtrl.cpp : CMoonPDFCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "MoonPDF.h"
#include "MoonPDFCtrl.h"
#include "MoonPDFPropPage.h"
#include "afxdialogex.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMoonPDFCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CMoonPDFCtrl, COleControl)
	ON_MESSAGE(OCM_COMMAND, &CMoonPDFCtrl::OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_EDIT, OnEdit)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CMoonPDFCtrl, COleControl)
	DISP_FUNCTION_ID(CMoonPDFCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CMoonPDFCtrl, "OpenLocalPdf", dispidOpenLocalPdf, OpenLocalPdf, VT_EMPTY, VTS_BSTR)
	DISP_FUNCTION_ID(CMoonPDFCtrl, "SetPopMenuVisiable", dispidSetPopMenuVisiable, SetPopMenuVisiable, VT_EMPTY, VTS_BOOL)
	DISP_FUNCTION_ID(CMoonPDFCtrl, "GetPdfPageCount", dispidGetPdfPageCount, GetPdfPageCount, VT_UI4, VTS_NONE)
	DISP_FUNCTION_ID(CMoonPDFCtrl, "GotoPage", dispidGotoPage, GotoPage, VT_EMPTY, VTS_UI4)
	DISP_FUNCTION_ID(CMoonPDFCtrl, "EnableScrollToZoom", dispidEnableScrollToZoom, EnableScrollToZoom, VT_EMPTY, VTS_BOOL)
	DISP_FUNCTION_ID(CMoonPDFCtrl, "EnableScrollToPage", dispidEnableScrollToPage, EnableScrollToPage, VT_EMPTY, VTS_BOOL)
	DISP_FUNCTION_ID(CMoonPDFCtrl, "GetCurrentPageIndex", dispidGetCurrentPageIndex, GetCurrentPageIndex, VT_I4, VTS_NONE)
	DISP_FUNCTION_ID(CMoonPDFCtrl, "ExtractPageToSave", dispidExtractPageToSave, ExtractPageToSave, VT_I2, VTS_I4 VTS_BSTR)
	DISP_FUNCTION_ID(CMoonPDFCtrl, "PdfZoomIn", dispidPdfZoomIn, PdfZoomIn, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CMoonPDFCtrl, "PdfZoomOut", dispidPdfZoomOut, PdfZoomOut, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CMoonPDFCtrl, "PdfClockwiseRotation", dispidPdfClockwiseRotation, PdfClockwiseRotation, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CMoonPDFCtrl, "PdfContrarotate", dispidPdfContrarotate, PdfContrarotate, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CMoonPDFCtrl, COleControl)
	EVENT_CUSTOM_ID("OnCurrentPageChanged", eventidOnCurrentPageChanged, OnCurrentPageChanged, VTS_I4)
END_EVENT_MAP()

// ����ҳ

// TODO: ������Ҫ��Ӹ�������ҳ�����ס���Ӽ���!
BEGIN_PROPPAGEIDS(CMoonPDFCtrl, 1)
	PROPPAGEID(CMoonPDFPropPage::guid)
END_PROPPAGEIDS(CMoonPDFCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CMoonPDFCtrl, "MOONPDF.MoonPDFCtrl.1",
	0x8c99f46d, 0x8421, 0x478e, 0x97, 0x87, 0x5d, 0x42, 0x4d, 0x21, 0x5a, 0x2f)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CMoonPDFCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DMoonPDF = { 0x50FEEB59, 0x40AA, 0x4376, { 0xA6, 0x25, 0xB7, 0xE1, 0xCE, 0xAD, 0xC4, 0xD8 } };
const IID IID_DMoonPDFEvents = { 0x91A28D6A, 0x936C, 0x4DEF, { 0x81, 0x2D, 0x2F, 0x6E, 0x83, 0x10, 0x86, 0x17 } };

// �ؼ�������Ϣ

static const DWORD _dwMoonPDFOleMisc =
	OLEMISC_SIMPLEFRAME |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMoonPDFCtrl, IDS_MOONPDF, _dwMoonPDFOleMisc)

// CMoonPDFCtrl::CMoonPDFCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CMoonPDFCtrl ��ϵͳע�����

BOOL CMoonPDFCtrl::CMoonPDFCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegInsertable | afxRegApartmentThreading ��Ϊ afxRegInsertable��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MOONPDF,
			IDB_MOONPDF,
			afxRegInsertable | afxRegApartmentThreading,
			_dwMoonPDFOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CMoonPDFCtrl::CMoonPDFCtrl - ���캯��

CMoonPDFCtrl::CMoonPDFCtrl()
{
	InitializeIIDs(&IID_DMoonPDF, &IID_DMoonPDFEvents);

	EnableSimpleFrame();
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�

	m_pMoonPDFDialog = NULL;
}

// CMoonPDFCtrl::~CMoonPDFCtrl - ��������

CMoonPDFCtrl::~CMoonPDFCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�

	//�ͷ�PDF�Ի�����
	if (m_pMoonPDFDialog != NULL)
	{
		delete m_pMoonPDFDialog;
	}
}

// CMoonPDFCtrl::OnDraw - ��ͼ����

void CMoonPDFCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	DoSuperclassPaint(pdc, rcBounds);
	m_pMoonPDFDialog->MoveWindow(rcBounds, TRUE);//�Ի�����ʾ���ؼ���rcBoundsȫ��Χ��
}

// CMoonPDFCtrl::DoPropExchange - �־���֧��

void CMoonPDFCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CMoonPDFCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CMoonPDFCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// CMoonPDFCtrl::AboutBox - ���û���ʾ�����ڡ���

void CMoonPDFCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_MOONPDF);
	dlgAbout.DoModal();
}


// CMoonPDFCtrl::PreCreateWindow - �޸� CreateWindowEx �Ĳ���

BOOL CMoonPDFCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("STATIC");
	BOOL bRet = COleControl::PreCreateWindow(cs);
	cs.hMenu = NULL;
	return bRet;
}

// CMoonPDFCtrl::IsSubclassedControl - ����һ������ؼ�

BOOL CMoonPDFCtrl::IsSubclassedControl()
{
	return TRUE;
}

// CMoonPDFCtrl::OnOcmCommand - ����������Ϣ

LRESULT CMoonPDFCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
	WORD wNotifyCode = HIWORD(wParam);

	// TODO:  �ڴ˽�ͨ wNotifyCode��

	return 0;
}


// CMoonPDFCtrl ��Ϣ�������


int CMoonPDFCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	//����PDF�Ի�����
	m_pMoonPDFDialog = new CMoonPDFDialog();
	m_pMoonPDFDialog->Create(IDD_MAIN_DIALOG, this);
	m_pMoonPDFDialog->ShowWindow(SW_SHOW);

	//ע��ص��¼�
	RegistCallbackEvent();
	return 0;
}

void CMoonPDFCtrl::RegistCallbackEvent()//ע��ص��¼�
{
	PdfCurrentPageIndexChanged funcPdfCurrentPageIndexChanged = std::bind(&CMoonPDFCtrl::OnCurrentPageChanged, this, std::placeholders::_1);
	m_pMoonPDFDialog->RegistCurrentPageChangeEvent(funcPdfCurrentPageIndexChanged);
}


void CMoonPDFCtrl::OpenLocalPdf(LPCTSTR pdfPathName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	this->m_pMoonPDFDialog->OpenLocalPdf(pdfPathName);
}


void CMoonPDFCtrl::SetPopMenuVisiable(VARIANT_BOOL bVisiable)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	this->m_pMoonPDFDialog->SetPopMenuVisiable(bVisiable);
}


LONG CMoonPDFCtrl::GetPdfPageCount()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	return this->m_pMoonPDFDialog->GetPdfPageCount();
}


void CMoonPDFCtrl::GotoPage(LONG number)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	this->m_pMoonPDFDialog->GotoPage(number);
}


void CMoonPDFCtrl::EnableScrollToZoom(VARIANT_BOOL bEnable)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	this->m_pMoonPDFDialog->EnableScrollToZoom(bEnable);
}


void CMoonPDFCtrl::EnableScrollToPage(VARIANT_BOOL bEnable)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	this->m_pMoonPDFDialog->EnableScrollToPage(bEnable);
}


LONG CMoonPDFCtrl::GetCurrentPageIndex()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	return this->m_pMoonPDFDialog->GetCurrentPageIndex();
}


SHORT CMoonPDFCtrl::ExtractPageToSave(LONG pageIndex, LPCTSTR newPdfPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	if (this->m_pMoonPDFDialog->ExtractPageToSave(pageIndex, newPdfPath))
		return 0;
	else
		return -1;
}


void CMoonPDFCtrl::PdfZoomIn()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	this->m_pMoonPDFDialog->PdfZoomIn();
}


void CMoonPDFCtrl::PdfZoomOut()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	this->m_pMoonPDFDialog->PdfZoomOut();
}


void CMoonPDFCtrl::PdfClockwiseRotation()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	this->m_pMoonPDFDialog->PdfClockwiseRotation();
}


void CMoonPDFCtrl::PdfContrarotate()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	this->m_pMoonPDFDialog->PdfContrarotate();
}
