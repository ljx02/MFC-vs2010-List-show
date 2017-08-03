// SplitterLinkList.cpp : implementation file
//

#include "stdafx.h"
#include "datastructvisual.h"
#include "SplitterLinkList.h"
#include "LinkListDraw.h"
#include "LinkListCrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplitterLinkList

IMPLEMENT_DYNCREATE(CSplitterLinkList, CView)

CSplitterLinkList::CSplitterLinkList()
{
}

CSplitterLinkList::~CSplitterLinkList()
{
}


BEGIN_MESSAGE_MAP(CSplitterLinkList, CView)
	//{{AFX_MSG_MAP(CSplitterLinkList)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSplitterLinkList drawing

void CSplitterLinkList::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CSplitterLinkList diagnostics

#ifdef _DEBUG
void CSplitterLinkList::AssertValid() const
{
	CView::AssertValid();
}

void CSplitterLinkList::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSplitterLinkList message handlers

int CSplitterLinkList::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CRect rect;
	GetClientRect(&rect);
	m_WndLinkListSplitter.CreateStatic(this, 2, 1);
	CCreateContext *pContext = (CCreateContext*) lpCreateStruct->lpCreateParams;
	m_WndLinkListSplitter.CreateView(0,0,RUNTIME_CLASS(CLinkListDraw),
		CSize(rect.Width(),rect.Height()/2), pContext);
	m_WndLinkListSplitter.CreateView(1,0,RUNTIME_CLASS(CLinkListCrl), 
		CSize(rect.Width(),rect.Height()/2), pContext);
	return 0;
}

void CSplitterLinkList::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here                                                                                                                                                                                                                
	m_WndLinkListSplitter.MoveWindow(0,0,cx,cy);
	m_WndLinkListSplitter.SetRowInfo(0, cy-(cy/4), 0);
	m_WndLinkListSplitter.SetRowInfo(1, cy/4, 20);
	m_WndLinkListSplitter.RecalcLayout();
}
