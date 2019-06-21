#pragma once
#include <afxdialogex.h>
#include <functional>
/*******************************************************************************************
 * ˵�������ڼ���pdf�ĶԻ����࣬���е�pdf����ҵ���ɸ���ʵ�֣�pdf�����ʵ���ǲ��ÿ�Դ��
 *		 mupdf��ܡ�
 * ���ߣ�����Ȼ
 * ʱ�䣺2019-5-26 16:41
 ******************************************************************************************/
//�ص��¼��Ķ���
typedef std::function<void(LONG)> PdfCurrentPageIndexChanged;//pdf��ǰ��ʾҳ�����ı�Ļص���������

//PDF�Ի�����
class CMoonPDFDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMoonPDFDialog)

public:
	CMoonPDFDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMoonPDFDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public://�¼�
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	BOOL m_bVisiableMenu;//�Ƿ���ʾ�˵�
	BOOL m_bEnableScrollToZoom;//�Ƿ�ʹ�ܰ�סctrl����������
	BOOL m_bEnableScrollToPage;//�Ƿ�ʹ�ܹ�����ҳ
	PdfCurrentPageIndexChanged m_funcPdfCurrentPageIndexChanged;//pdf��ǰҳ�����ı�
	LONG m_lCurrentPageIndex;//��ǰ��ʾ��ҳ����
private:
	//pdf���Ƶ�������
	void WinBlit();
	//��������¼�
	void HandleMouse(int x, int y, int btn, int state);
	//���������˵�
	void CreatePopMenu();
	//���ļ�ѡ����Ҵ�pdf�ļ�
	void OpenFileSlectWndAndOpenPdf();
//�ⲿ����
public:
	//��ȡ������
	HWND GetHWnd();
	//��ȡCDC
	HDC GetHdc();
	//�򿪱���pdf
	void OpenLocalPdf(CString pdfPath);
	//���ÿؼ��Ҽ��˵���ʾ����
	void SetPopMenuVisiable(BOOL bVisiable);
	//��ȡpdfҳ������
	UINT GetPdfPageCount();
	//��ת�������ҳ
	void GotoPage(UINT number);
	//�Ƿ�ʹ�ܰ�סctrl����������
	void EnableScrollToZoom(BOOL bEnable);
	//�Ƿ�ʹ�ܹ�����ҳ
	void EnableScrollToPage(BOOL bEnable);
	//��ȡ��ǰpdfҳ����
	LONG GetCurrentPageIndex();

public:
	//ע�ᵱǰҳ�ı��¼�
	void RegistCurrentPageChangeEvent(PdfCurrentPageIndexChanged funcPdfCurrentPageIndexChanged);
};
