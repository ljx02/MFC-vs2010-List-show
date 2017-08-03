#if !defined(AFX_RIGHTSWITCHFRAME_H__7272A49C_327E_48B1_B707_1A739AFA6A44__INCLUDED_)
#define AFX_RIGHTSWITCHFRAME_H__7272A49C_327E_48B1_B707_1A739AFA6A44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RightSwitchFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRightSwitchFrame frame
#include "Splitter1.h"
#include "Splitter2.h"
#include "SplitterLinkList.h"

class CRightSwitchFrame : public CFrameWnd
{
	DECLARE_DYNCREATE(CRightSwitchFrame)
protected:
	CRightSwitchFrame();           // protected constructor used by dynamic creation

// Attributes
public:
	UINT           m_nCurrentViewID;
	int m_nView;
	CSplitter1* m_pSplitter1;
	CSplitter2* m_pSplitter2;
	CView* m_pNewActiveView;
// Operations
public:
	CSplitterLinkList* m_pSplitterLinkList;

	void SwitchToView(UINT nView);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRightSwitchFrame)
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CRightSwitchFrame();

	// Generated message map functions
	//{{AFX_MSG(CRightSwitchFrame)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RIGHTSWITCHFRAME_H__7272A49C_327E_48B1_B707_1A739AFA6A44__INCLUDED_)
