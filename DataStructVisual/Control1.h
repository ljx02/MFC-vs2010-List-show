#if !defined(AFX_CONTROL1_H__95EDCDEF_E2AD_414A_90E4_35CB62D05318__INCLUDED_)
#define AFX_CONTROL1_H__95EDCDEF_E2AD_414A_90E4_35CB62D05318__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Control1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CControl1 form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CControl1 : public CFormView
{
protected:
	CControl1();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CControl1)

// Form Data
public:
	//{{AFX_DATA(CControl1)
	enum { IDD = IDD_CONTROL1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControl1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CControl1();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CControl1)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CFont font;
	//CFont font1;
	virtual void OnInitialUpdate();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROL1_H__95EDCDEF_E2AD_414A_90E4_35CB62D05318__INCLUDED_)
