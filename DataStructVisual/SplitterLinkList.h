#if !defined(AFX_SPLITTERLINKLIST_H__77AF6AA9_20C0_44FB_A5FC_844CEEFA1DBA__INCLUDED_)
#define AFX_SPLITTERLINKLIST_H__77AF6AA9_20C0_44FB_A5FC_844CEEFA1DBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SplitterLinkList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSplitterLinkList view

class CSplitterLinkList : public CView
{
public:
	CSplitterLinkList();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSplitterLinkList)

// Attributes
public:
	CSplitterWnd m_WndLinkListSplitter;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplitterLinkList)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSplitterLinkList();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CSplitterLinkList)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITTERLINKLIST_H__77AF6AA9_20C0_44FB_A5FC_844CEEFA1DBA__INCLUDED_)
