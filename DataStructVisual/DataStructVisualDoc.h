// DataStructVisualDoc.h : interface of the CDataStructVisualDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATASTRUCTVISUALDOC_H__7229D4C1_FFF8_4BA5_A190_AFE91A378F8C__INCLUDED_)
#define AFX_DATASTRUCTVISUALDOC_H__7229D4C1_FFF8_4BA5_A190_AFE91A378F8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LinkList.h"


class CDataStructVisualDoc : public CDocument
{
protected: // create from serialization only
	CDataStructVisualDoc();
	DECLARE_DYNCREATE(CDataStructVisualDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataStructVisualDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CLinkList		m_CLinkList;
	
	virtual ~CDataStructVisualDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDataStructVisualDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATASTRUCTVISUALDOC_H__7229D4C1_FFF8_4BA5_A190_AFE91A378F8C__INCLUDED_)
