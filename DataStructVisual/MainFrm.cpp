// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "DataStructVisual.h"

#include "MainFrm.h"
#include "LeftPane.h"
#include "RightSwitchFrame.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, 
		TBSTYLE_FLAT, 
		WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS 
		| CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	m_wndToolBar.ShowWindow(SW_HIDE);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
	{
		TRACE0("Failed to create splitter window\n");
		return FALSE;
	}

	CRect rect;
	GetClientRect(&rect);

	if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CLeftPane), CSize(rect.Width()*1/4,rect.Height()), pContext))
	{
		TRACE0("Failed to create left pane view\n");
		return FALSE;
	}
	if (!m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CRightSwitchFrame), CSize(0,0), pContext))
	{
		TRACE0("Failed to create right pane frame\n");
		return FALSE;
	}
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
	CLeftPane* pLeftPane     = (CLeftPane*)   m_wndSplitter.GetPane(0,0);
	pLeftPane->m_pRightSwitchFrame = (CRightSwitchFrame*) m_wndSplitter.GetPane(0,1);
	
	// Set the left pane as the active view
	SetActiveView((CView*) m_wndSplitter.GetPane(0, 0));

	return true;
}

void CMainFrame::ShowToolBar(bool vFlag)
{
	if(vFlag)
	{
		if(!m_wndToolBar.IsWindowVisible())
		{
			m_wndToolBar.ModifyStyle(0,WS_VISIBLE);
		}
	}else
	{
		if(m_wndToolBar.IsWindowVisible())
		{
			m_wndToolBar.ModifyStyle(WS_VISIBLE,0);
			
		}
	}
	SendMessage(WM_SIZE);
}


