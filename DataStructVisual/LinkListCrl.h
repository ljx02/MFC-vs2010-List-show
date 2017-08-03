#if !defined(AFX_LINKLISTCRL_H__8B33C0E4_6C11_465B_A9AC_81CCE827B312__INCLUDED_)
#define AFX_LINKLISTCRL_H__8B33C0E4_6C11_465B_A9AC_81CCE827B312__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LinkListCrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLinkListCrl form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CLinkListCrl : public CFormView
{
protected:
	CLinkListCrl();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLinkListCrl)

// Form Data
public:
	//{{AFX_DATA(CLinkListCrl)
	enum { IDD = IDD_LINKLISTCRL_FORMVIEW };
	CString	m_LinkNodeValue;
	CString	m_LinkNodePos;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkListCrl)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLinkListCrl();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CLinkListCrl)
	afx_msg void OnButtonAddlistnode();
	afx_msg void OnButtonInsertlistnode();
	afx_msg void OnButtonDeletelistnode();
	afx_msg void OnButtonSearchlistnode();
	afx_msg void OnButtonHeadadd();
	afx_msg void OnButtonClean();
	afx_msg void OnButtonSort();//从小到大排序
	afx_msg void OnButtonSort1();//从大到小排序

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKLISTCRL_H__8B33C0E4_6C11_465B_A9AC_81CCE827B312__INCLUDED_)
