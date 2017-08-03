// DataStructVisualDoc.cpp : implementation of the CDataStructVisualDoc class
//

#include "stdafx.h"
#include "DataStructVisual.h"
#include "DataStructVisualDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataStructVisualDoc

IMPLEMENT_DYNCREATE(CDataStructVisualDoc, CDocument)

BEGIN_MESSAGE_MAP(CDataStructVisualDoc, CDocument)
	//{{AFX_MSG_MAP(CDataStructVisualDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataStructVisualDoc construction/destruction

CDataStructVisualDoc::CDataStructVisualDoc()
{
	// TODO: add one-time construction code here

}

CDataStructVisualDoc::~CDataStructVisualDoc()
{
}

BOOL CDataStructVisualDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDataStructVisualDoc serialization

void CDataStructVisualDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDataStructVisualDoc diagnostics

#ifdef _DEBUG
void CDataStructVisualDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDataStructVisualDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDataStructVisualDoc commands
