// DataStructVisualView.cpp : implementation of the CDataStructVisualView class
//

#include "stdafx.h"
#include "DataStructVisual.h"

#include "DataStructVisualDoc.h"
#include "DataStructVisualView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataStructVisualView

IMPLEMENT_DYNCREATE(CDataStructVisualView, CView)

BEGIN_MESSAGE_MAP(CDataStructVisualView, CView)
	//{{AFX_MSG_MAP(CDataStructVisualView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataStructVisualView construction/destruction

CDataStructVisualView::CDataStructVisualView()
{
	// TODO: add construction code here

}

CDataStructVisualView::~CDataStructVisualView()
{
}

BOOL CDataStructVisualView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDataStructVisualView drawing

void CDataStructVisualView::OnDraw(CDC* pDC)
{
	CDataStructVisualDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDataStructVisualView printing

BOOL CDataStructVisualView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDataStructVisualView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDataStructVisualView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDataStructVisualView diagnostics

#ifdef _DEBUG
void CDataStructVisualView::AssertValid() const
{
	CView::AssertValid();
}

void CDataStructVisualView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDataStructVisualDoc* CDataStructVisualView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDataStructVisualDoc)));
	return (CDataStructVisualDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDataStructVisualView message handlers
