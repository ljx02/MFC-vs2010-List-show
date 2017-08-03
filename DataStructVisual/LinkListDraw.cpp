// LinkListDraw.cpp : implementation file
//

#include "stdafx.h"
#include "datastructvisual.h"
#include "LinkListDraw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinkListDraw

IMPLEMENT_DYNCREATE(CLinkListDraw, CFormView)

CLinkListDraw::CLinkListDraw()
	: CFormView(CLinkListDraw::IDD)
{
	//{{AFX_DATA_INIT(CLinkListDraw)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CLinkListDraw::~CLinkListDraw()
{
}

void CLinkListDraw::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLinkListDraw)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLinkListDraw, CFormView)
	//{{AFX_MSG_MAP(CLinkListDraw)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinkListDraw diagnostics

#ifdef _DEBUG
void CLinkListDraw::AssertValid() const
{
	CFormView::AssertValid();
}

void CLinkListDraw::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
CDataStructVisualDoc* CLinkListDraw::GetDocument()
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDataStructVisualDoc)));
	return (CDataStructVisualDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLinkListDraw message handlers

void CLinkListDraw::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	//m_LinkList = new CLinkList();
	m_pDoc = GetDocument();
	m_hEventLinkList=::CreateEvent(NULL,true,true,"LinkList");
	m_Flag=0;
}

DWORD WINAPI CLinkListDraw::LinkListproc(LPVOID lpParameter)
{

	CLinkListDraw *tPLinkListDraw = (CLinkListDraw*)lpParameter;
	CRect WinSize;
	CPoint CenterPoint;
	tPLinkListDraw->GetClientRect(WinSize);
	CDC *tPDC=tPLinkListDraw->GetDC();
	//CLinkList *tPLinkList = tPLinkListDraw->m_pLinkList;

	if(tPLinkListDraw->m_Flag == -1) 
	{ 
		tPLinkListDraw->DrawLinkList(tPDC); 
	} 
	if(tPLinkListDraw->m_Flag == 0)
	{
		tPLinkListDraw->m_Flag = -1;
		tPLinkListDraw->AddHeadToList(WinSize);
		tPLinkListDraw->DrawLinkList(tPDC);
	}
	if(tPLinkListDraw->m_Flag == 1)
	{

		tPLinkListDraw->m_Flag = -1;
		tPLinkListDraw->DrawLinkList(tPDC);
	}
	if(tPLinkListDraw->m_Flag == 2) 
	{ 
		tPLinkListDraw->m_Flag = -1;
		tPLinkListDraw->DrawLinkList(tPDC);
	    tPLinkListDraw->DrawSearchLinkListFlag(tPDC);
	}
	return 1;
}

void CLinkListDraw::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CLinkListDraw *tPLinkListDraw = this;
	m_hThreadLinkList=CreateThread(
		NULL,
		0,
		LinkListproc,
		(LPVOID)tPLinkListDraw,0,NULL
		);
	CloseHandle(m_hThreadLinkList);
	
	// Do not call CFormView::OnPaint() for painting messages
}

void CLinkListDraw::AddLinkListNode(CString vLNValue)
{
	
}
void CLinkListDraw::AddHeadToList(CRect vRect)
{
	//含有头指针
	CPoint tPoint;
	CString tLNValue=" ";
	tPoint.x=vRect.right;
	tPoint.y=vRect.bottom; 
	m_pDoc->m_CLinkList.AddTail(tPoint,tLNValue);
}

/*
void CLinkListDraw::AddLinkListNode(
*/


void CLinkListDraw::DrawLinkList(CDC* pDC)
{
	m_pDoc->m_CLinkList.DrawLinkList(pDC);
}

void CLinkListDraw::InsertLinkListNode(int vPos, CString vLNValue)
{
	CDataStructVisualDoc* pDoc = GetDocument();
	CPoint tCenterPoint;
	CRect WinSize;
	this->GetClientRect(WinSize);
	tCenterPoint.x=WinSize.right;
	tCenterPoint.y=WinSize.bottom; 
	pDoc->m_CLinkList.InsertNode(tCenterPoint,vPos,vLNValue);
	m_Flag = 1;
	this->Invalidate();

}
void CLinkListDraw::Clean()
{
	CDataStructVisualDoc* pDoc = GetDocument();
	CPoint CenterPoint;
	CRect WinSize;
	this->GetClientRect(WinSize);
	CenterPoint.x=WinSize.right;
	CenterPoint.y=WinSize.bottom;
	pDoc->m_CLinkList.CleanList(CenterPoint);
	//m_Flag = 1;
	this->Invalidate();
}

void CLinkListDraw::Sort()
{
	CDataStructVisualDoc* pDoc = GetDocument();
	CPoint CenterPoint;
	CRect WinSize;
	this->GetClientRect(WinSize);
	CenterPoint.x=WinSize.right;
	CenterPoint.y=WinSize.bottom;
	pDoc->m_CLinkList.Sort(CenterPoint);
	pDoc->m_CLinkList.TiaoZheng(CenterPoint);
	this->Invalidate();
}

void CLinkListDraw::Sort1()
{
	CDataStructVisualDoc* pDoc = GetDocument();
	CPoint CenterPoint;
	CRect WinSize;
	this->GetClientRect(WinSize);
	CenterPoint.x=WinSize.right;
	CenterPoint.y=WinSize.bottom;
	pDoc->m_CLinkList.Sort1(CenterPoint);
	pDoc->m_CLinkList.TiaoZheng(CenterPoint);
	this->Invalidate();
}

void CLinkListDraw::DeleteLinkListNode(int vPos)
{
	CDataStructVisualDoc* pDoc = GetDocument();
	CPoint CenterPoint;
	CRect WinSize;
	this->GetClientRect(WinSize);
	CenterPoint.x=WinSize.right;
	CenterPoint.y=WinSize.bottom; 
	pDoc->m_CLinkList.DeleteNode(CenterPoint,vPos);
	m_Flag = 1;
	this->Invalidate();
}
void CLinkListDraw::SearchLinkListNode(CString vLNValue)
{
	CDataStructVisualDoc* pDoc = GetDocument(); 
	
	if(pDoc->m_CLinkList.Search(vLNValue))//弹出对话框，然后执行下一句,但未画出箭头
	{
		m_Flag = 2; 
		this->Invalidate();
		::AfxMessageBox("是要找的结点，查找成功！");
	}
}


void CLinkListDraw::Searching(CString vString)
{
	//画箭头,调试
	CDataStructVisualDoc* pDoc = GetDocument();
	int tCount = 0,i;
	tCount = pDoc->m_CLinkList.CountNode();
	for(i=1;i<tCount;i++)
	{
     if(pDoc->m_CLinkList.Searching(vString,i))
	  {
		m_Flag = 2;
		this->Invalidate();//在循环中只显示最后一次的单链表，循环的速度太快。
		::AfxMessageBox("不是要找的结点值"+ vString);//鼠标点击触发下次运行
	  }
	 else
	 {
		SearchLinkListNode(vString);
		break;
	 }
	}	
	if(i == tCount)
	{
		SearchLinkListNode(vString);
	}
}


void CLinkListDraw::AddTailLinkListNode(CString vLNValue)
{
	CDataStructVisualDoc* tPDoc = GetDocument();
	CPoint tCenterPoint;
	CRect tWinSize;
	this->GetClientRect(tWinSize);
	tCenterPoint.x=tWinSize.right;
	tCenterPoint.y=tWinSize.bottom;

    tPDoc->m_CLinkList.TiaoZheng(tCenterPoint);//顺序调整但未换行

	tPDoc->m_CLinkList.AddTail(tCenterPoint,vLNValue);

	

	m_Flag = 1;
	this->Invalidate();
}


void CLinkListDraw::DrawSearchLinkListFlag(CDC *pDC)
{
	CDataStructVisualDoc* tPDoc = GetDocument();
	tPDoc->m_CLinkList.DrawSearchArrow(pDC);
}
