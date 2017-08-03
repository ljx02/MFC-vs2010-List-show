#if !defined(AFX_SPLITTER1_H__C024DBC4_5DF7_49D0_A4F0_1C1406660EF7__INCLUDED_)
#define AFX_SPLITTER1_H__C024DBC4_5DF7_49D0_A4F0_1C1406660EF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Splitter1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSplitter1 view

class CSplitter1 : public CView
{
public:
	CSplitter1();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSplitter1)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplitter1)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSplitter1();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CSplitter1)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnCancelMode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CSplitterWnd m_wndSplitter1;
	CFont font;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITTER1_H__C024DBC4_5DF7_49D0_A4F0_1C1406660EF7__INCLUDED_)
