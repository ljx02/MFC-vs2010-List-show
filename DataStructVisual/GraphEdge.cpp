// GraphEdge.cpp: implementation of the CGraphEdge class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "datastructvisual.h"
#include "GraphEdge.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#include "GraphVertex.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGraphEdge::CGraphEdge()
{
	m_color = RGB(0,0,0);	
}

CGraphEdge::~CGraphEdge()
{

}
bool CGraphEdge::EdgeDraw(CGraphVertex* pBeginVex,CDC *pDC)
{
	CPen *poldPen,CurBPen;
	CString str;
	CurBPen.CreatePen(PS_SOLID,2,RGB(0,0,255));
	poldPen=pDC->SelectObject(&CurBPen);
	CPoint tPointHead,tpointTail;
	tPointHead = pBeginVex->m_point;
	pDC->MoveTo(tPointHead);
	tpointTail = m_pAdjVertex->m_point;
	pDC->LineTo(tpointTail);
	str.Format("%d", m_weight);
	pDC->TextOut((tPointHead.x + tpointTail.x)/2,
				(tPointHead.y + tpointTail.y)/2, str);	

	return true;
}