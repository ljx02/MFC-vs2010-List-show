// Control1.cpp : implementation file
//

#include "stdafx.h"
#include "DataStructVisual.h"
#include "Control1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CControl1

IMPLEMENT_DYNCREATE(CControl1, CFormView)

CControl1::CControl1()
	: CFormView(CControl1::IDD)
{
	//{{AFX_DATA_INIT(CControl1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CControl1::~CControl1()
{
}

void CControl1::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CControl1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	
}


BEGIN_MESSAGE_MAP(CControl1, CFormView)
	//{{AFX_MSG_MAP(CControl1)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControl1 diagnostics

#ifdef _DEBUG
void CControl1::AssertValid() const
{
	CFormView::AssertValid();
}

void CControl1::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CControl1 message handlers

HBRUSH CControl1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if(pWnd->GetDlgCtrlID() == IDC_STATIC1)
	{
		pDC->SetTextColor(RGB(0,0,225));
	}

	return hbr;
}


void CControl1::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	font.CreatePointFont(400,_T("����"));
	GetDlgItem(IDC_STATIC1)->SetFont(&font);
	//font1.CreatePointFont(50,_T("����"));
	GetDlgItem(IDC_STATIC2)->SetFont(&font);
}
