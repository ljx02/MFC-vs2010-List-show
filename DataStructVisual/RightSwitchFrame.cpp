// RightSwitchFrame.cpp : implementation file
//

#include "stdafx.h"
#include "datastructvisual.h"
#include "RightSwitchFrame.h"
#include "Draw1.h"
#include "Draw2.h"
#include "Control1.h"
#include "Control2.h"
#include "LinkListDraw.h"
#include "LinkListCrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRightSwitchFrame

IMPLEMENT_DYNCREATE(CRightSwitchFrame, CFrameWnd)

CRightSwitchFrame::CRightSwitchFrame()
{
}

CRightSwitchFrame::~CRightSwitchFrame()
{
}


BEGIN_MESSAGE_MAP(CRightSwitchFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CRightSwitchFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRightSwitchFrame message handlers

BOOL CRightSwitchFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	m_pSplitter1=new CSplitter1;
	m_pSplitter1->Create(NULL, NULL, 0L, CFrameWnd::rectDefault, this, VIEW_SPLITTER1, pContext);
	m_pSplitter1->ShowWindow(SW_SHOW);
	m_pSplitter1->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	m_nCurrentViewID = VIEW_SPLITTER1;
	SetActiveView(m_pSplitter1);

	m_pSplitter2 = new CSplitter2;
	((CView*) m_pSplitter2)->Create(NULL, NULL, 0L, CFrameWnd::rectDefault, this, VIEW_SPLITTER2, pContext);
	m_pSplitter2->ShowWindow(SW_HIDE);
	m_pSplitter2->SetDlgCtrlID(VIEW_SPLITTER1);

	m_pSplitterLinkList = new CSplitterLinkList;
	((CView*) m_pSplitterLinkList)->Create(
		NULL, 
		NULL, 
		0L, 
		CFrameWnd::rectDefault, this, 
		VIEW_SPLITTER_LINKLIST, 
		pContext);
	m_pSplitterLinkList->ShowWindow(SW_HIDE);
	m_pSplitterLinkList->SetDlgCtrlID(VIEW_SPLITTER_LINKLIST);


	RecalcLayout();
	
	return TRUE;
}
void CRightSwitchFrame::SwitchToView(UINT nView)
{
	m_nView=nView;
	CView* pOldActiveView = GetActiveView();
	CView* pNewActiveView = NULL;
	if(pOldActiveView->IsKindOf(RUNTIME_CLASS(CDraw1))||pOldActiveView->IsKindOf(RUNTIME_CLASS(CControl1))){
		pOldActiveView=(CView*) m_pSplitter1;
	}
	if(pOldActiveView->IsKindOf(RUNTIME_CLASS(CDraw2))||pOldActiveView->IsKindOf(RUNTIME_CLASS(CControl2))){
		pOldActiveView=(CView*) m_pSplitter2;
	}
	if(pOldActiveView->IsKindOf(RUNTIME_CLASS(CLinkListDraw))
		||pOldActiveView->IsKindOf(RUNTIME_CLASS(CLinkListCrl))){
		pOldActiveView=(CView*) m_pSplitterLinkList;
	}


	switch (nView)
	{
	case	VIEW_SPLITTER1:
				pNewActiveView = (CView*) m_pSplitter1;
				break;
	case	VIEW_SPLITTER2:
				pNewActiveView = (CView*) m_pSplitter2;
				break;
	case    VIEW_SPLITTER_LINKLIST:
				pNewActiveView = (CView*) m_pSplitterLinkList;
				break;
	}

	if (pNewActiveView)
	{
		// don't switch when views are the same
		if (pOldActiveView == pNewActiveView) return;

		SetActiveView(pNewActiveView);
		pNewActiveView->ShowWindow(SW_SHOW);
		pNewActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
		pOldActiveView->ShowWindow(SW_HIDE);
		pOldActiveView->SetDlgCtrlID(m_nCurrentViewID);
		m_nCurrentViewID = nView;

		RecalcLayout();
	}
}

