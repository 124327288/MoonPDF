#pragma once

// MoonPDFPropPage.h : CMoonPDFPropPage ����ҳ���������


// CMoonPDFPropPage : �й�ʵ�ֵ���Ϣ������� MoonPDFPropPage.cpp��

class CMoonPDFPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMoonPDFPropPage)
	DECLARE_OLECREATE_EX(CMoonPDFPropPage)

// ���캯��
public:
	CMoonPDFPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_MOONPDF };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

