#if !defined(AFX_LINKLISTDRAW_H__D8985D25_F49C_43EF_84E8_B80F4690F5B8__INCLUDED_)
#define AFX_LINKLISTDRAW_H__D8985D25_F49C_43EF_84E8_B80F4690F5B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LinkListDraw.h : header file
//
#include "LinkList.h"
#include "DataStructVisualDoc.h"
/////////////////////////////////////////////////////////////////////////////
// CLinkListDraw form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CLinkListDraw : public CFormView
{
protected:
	CLinkListDraw();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLinkListDraw)

// Form Data
public:
	//{{AFX_DATA(CLinkListDraw)
	enum { IDD = IDD_LINKLISTDRAW_FORMVIEW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	
// Operations
public:
	void DrawSearchLinkListFlag(CDC *pDC);
	void AddTailLinkListNode(CString vLNValue);
	void DeleteLinkListNode(int vPos);
	void InsertLinkListNode(int vPos,CString vLNValue);
	void DrawLinkList(CDC* pDC);
	void AddHeadToList(CRect vRect);
	void SearchLinkListNode(CString vString);

	void Searching(CString vString);//让箭头移动
	void Sort();
	void Sort1();
	void Clean();

	CDataStructVisualDoc* GetDocument();
	CDataStructVisualDoc* m_pDoc;
	void AddLinkListNode(CString vLNValue);
	int m_Flag;//0:空链表；1：插入节点
	static DWORD WINAPI LinkListproc(LPVOID lpParameter);
	HANDLE m_hEventLinkList;
	HANDLE m_hThreadLinkList;
//	CLinkList* m_pLinkList;
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkListDraw)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLinkListDraw();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CLinkListDraw)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in graphView.cpp
/*
inline CDataStructVisualDoc* CLinkListDraw::GetDocument()
   { return (CDataStructVisualDoc*)m_pDocument; }*/
#endif
 
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKLISTDRAW_H__D8985D25_F49C_43EF_84E8_B80F4690F5B8__INCLUDED_)
