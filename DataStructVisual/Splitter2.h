#if !defined(AFX_SPLITTER2_H__2C411C3C_2F99_4251_B1E4_1305ABD82D0F__INCLUDED_)
#define AFX_SPLITTER2_H__2C411C3C_2F99_4251_B1E4_1305ABD82D0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Splitter2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSplitter2 view

class CSplitter2 : public CView
{
public:
	CSplitter2();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CSplitter2)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplitter2)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSplitter2();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CSplitter2)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnCancelMode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CSplitterWnd m_wndSplitter2;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITTER2_H__2C411C3C_2F99_4251_B1E4_1305ABD82D0F__INCLUDED_)
