#pragma once
#include "MoonPDFDialog.h"
// MoonPDFCtrl.h : CMoonPDFCtrl ActiveX �ؼ����������


// CMoonPDFCtrl : �й�ʵ�ֵ���Ϣ������� MoonPDFCtrl.cpp��

class CMoonPDFCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMoonPDFCtrl)

// ���캯��
public:
	CMoonPDFCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CMoonPDFCtrl();

	DECLARE_OLECREATE_EX(CMoonPDFCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CMoonPDFCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMoonPDFCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CMoonPDFCtrl)		// �������ƺ�����״̬

	// ����ؼ�֧��
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
		dispidGetCurrentPageIndex = 7L,
		eventidOnCurrentPageChanged = 1L,
		dispidEnableScrollToPage = 6L,
		dispidEnableScrollToZoom = 5L,
		dispidGotoPage = 4L,
		dispidGetPdfPageCount = 3L,
		dispidSetPopMenuVisiable = 2L,
		dispidOpenLocalPdf = 1L
	};

//��Ա����
private:
	CMoonPDFDialog *m_pMoonPDFDialog;//PDF�Ի�����

private:
	void RegistCallbackEvent();//ע��ص��¼�
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
protected:
	//���ⲿ�ӿڣ��򿪱���pdf�ļ�
	void OpenLocalPdf(LPCTSTR pdfPathName);
	//���ÿؼ��Ҽ��˵���ʾ����
	void SetPopMenuVisiable(VARIANT_BOOL bVisiable);
	//��ȡpdfҳ������
	LONG GetPdfPageCount();
	//��ת�������ҳ
	void GotoPage(LONG number);
	//�Ƿ�ʹ�ܰ�סctrl����������
	void EnableScrollToZoom(VARIANT_BOOL bEnable);
	//�Ƿ�ʹ�ܹ�����ҳ
	void EnableScrollToPage(VARIANT_BOOL bEnable);
	//��ȡ��ǰpdfҳ����
	LONG GetCurrentPageIndex();

	//��ǰҳ�����ı��¼�
	void OnCurrentPageChanged(LONG lCurrentPageIndex)
	{
		FireEvent(eventidOnCurrentPageChanged, EVENT_PARAM(VTS_I4), lCurrentPageIndex);
	}
	
};

