// DataStructVisualView.h : interface of the CDataStructVisualView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATASTRUCTVISUALVIEW_H__46E16D19_4C14_467C_9EC5_BC179888EF61__INCLUDED_)
#define AFX_DATASTRUCTVISUALVIEW_H__46E16D19_4C14_467C_9EC5_BC179888EF61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDataStructVisualView : public CView
{
protected: // create from serialization only
	CDataStructVisualView();
	DECLARE_DYNCREATE(CDataStructVisualView)

// Attributes
public:
	CDataStructVisualDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataStructVisualView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDataStructVisualView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDataStructVisualView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DataStructVisualView.cpp
inline CDataStructVisualDoc* CDataStructVisualView::GetDocument()
   { return (CDataStructVisualDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATASTRUCTVISUALVIEW_H__46E16D19_4C14_467C_9EC5_BC179888EF61__INCLUDED_)
