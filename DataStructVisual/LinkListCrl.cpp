// LinkListCrl.cpp : implementation file
//

#include "stdafx.h"
#include "datastructvisual.h"
#include "LinkListCrl.h"
#include "LinkListDraw.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinkListCrl

IMPLEMENT_DYNCREATE(CLinkListCrl, CFormView)

CLinkListCrl::CLinkListCrl()
	: CFormView(CLinkListCrl::IDD)
{
	//{{AFX_DATA_INIT(CLinkListCrl)
	m_LinkNodeValue = _T("");
	m_LinkNodePos = _T("");
	//}}AFX_DATA_INIT
}

CLinkListCrl::~CLinkListCrl()
{
}

void CLinkListCrl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLinkListCrl)
	DDX_Text(pDX, IDC_EDIT_LINKNODE_DATA, m_LinkNodeValue);
	DDX_Text(pDX, IDC_EDIT_LINKNODE_POS, m_LinkNodePos);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLinkListCrl, CFormView)
	//{{AFX_MSG_MAP(CLinkListCrl)
	ON_BN_CLICKED(IDC_BUTTON_ADDLISTNODE, OnButtonAddlistnode)
	ON_BN_CLICKED(IDC_BUTTON_INSERTLISTNODE, OnButtonInsertlistnode)
	ON_BN_CLICKED(IDC_BUTTON_DELETELISTNODE, OnButtonDeletelistnode)
	ON_BN_CLICKED(IDC_BUTTON_SEARCHLISTNODE, OnButtonSearchlistnode)
	ON_BN_CLICKED(IDC_BUTTON_HEADADD,OnButtonHeadadd)
	ON_BN_CLICKED(IDC_BUTTON_CLEAN,OnButtonClean)
	ON_BN_CLICKED(IDC_BUTTON_SORT1,OnButtonSort)
	ON_BN_CLICKED(IDC_BUTTON_SORT2,OnButtonSort1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinkListCrl diagnostics

#ifdef _DEBUG
void CLinkListCrl::AssertValid() const
{
	CFormView::AssertValid();
}

void CLinkListCrl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
void CLinkListCrl::OnButtonAddlistnode() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_LinkNodeValue.IsEmpty()){
		::AfxMessageBox("请输入插入结点值.");
		return;
	}
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CLinkListDraw*)(pWnd->GetPane(0, 0)))->AddTailLinkListNode(m_LinkNodeValue);

	GetDlgItem(IDC_BUTTON_INSERTLISTNODE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_DELETELISTNODE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SEARCHLISTNODE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SORT1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SORT2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_HEADADD)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_CLEAN)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_LINKNODE_DATA)->SetWindowTextA(_T(""));
	GetDlgItem(IDC_EDIT_LINKNODE_POS)->SetWindowTextA(_T(""));
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLinkListCrl message handlers


void CLinkListCrl::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	GetDlgItem(IDC_BUTTON_INSERTLISTNODE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_DELETELISTNODE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SEARCHLISTNODE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SORT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SORT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_HEADADD)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_CLEAN)->EnableWindow(FALSE);
}

void CLinkListCrl::OnButtonClean()
{
	UpdateData(TRUE);
	//重新创建单链表
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CLinkListDraw*)(pWnd->GetPane(0, 0)))->Clean();
}

void CLinkListCrl::OnButtonInsertlistnode() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_LinkNodePos.IsEmpty()){
		::AfxMessageBox("请输入插入位置.");
		return;
	}
	if(m_LinkNodeValue.IsEmpty()){
		::AfxMessageBox("请输入插入结点值.");
		return;
	}
	int tLinkNodePos=atoi(m_LinkNodePos);
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CLinkListDraw*)(pWnd->GetPane(0, 0)))->InsertLinkListNode(tLinkNodePos,m_LinkNodeValue);

	GetDlgItem(IDC_EDIT_LINKNODE_DATA)->SetWindowTextA(_T(""));
	GetDlgItem(IDC_EDIT_LINKNODE_POS)->SetWindowTextA(_T(""));
}

void CLinkListCrl::OnButtonHeadadd()
{
	UpdateData(TRUE);
	if(m_LinkNodeValue.IsEmpty()){
		::AfxMessageBox("请输入插入结点值.");
		return;
	}
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CLinkListDraw*)(pWnd->GetPane(0, 0)))->InsertLinkListNode(1,m_LinkNodeValue);

	GetDlgItem(IDC_BUTTON_INSERTLISTNODE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_DELETELISTNODE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SEARCHLISTNODE)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SORT1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_SORT2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_LINKNODE_DATA)->SetWindowTextA(_T(""));
	GetDlgItem(IDC_EDIT_LINKNODE_POS)->SetWindowTextA(_T(""));
}

void CLinkListCrl::OnButtonDeletelistnode() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_LinkNodePos.IsEmpty()){
		::AfxMessageBox("请输入删除位置.");
		return;
	}
	int tLinkNodePos=atoi(m_LinkNodePos);
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CLinkListDraw*)(pWnd->GetPane(0, 0)))->DeleteLinkListNode(tLinkNodePos);
	GetDlgItem(IDC_EDIT_LINKNODE_DATA)->SetWindowTextA(_T(""));
	GetDlgItem(IDC_EDIT_LINKNODE_POS)->SetWindowTextA(_T(""));
}

void CLinkListCrl::OnButtonSearchlistnode() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE); 
	if(m_LinkNodeValue.IsEmpty())
	{ 
		::AfxMessageBox("请输入查找数据.");
		return; 
	} 
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent(); 

	((CLinkListDraw*)(pWnd->GetPane(0, 0)))->Searching(m_LinkNodeValue);
	//GetDlgItem(IDC_NEXTBUTTON)-> EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_LINKNODE_DATA)->SetWindowTextA(_T(""));
	GetDlgItem(IDC_EDIT_LINKNODE_POS)->SetWindowTextA(_T(""));
}

void CLinkListCrl::OnButtonSort()
{
	UpdateData(TRUE);
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CLinkListDraw*)(pWnd->GetPane(0, 0)))->Sort();
}

void CLinkListCrl::OnButtonSort1()
{
	UpdateData(TRUE);
	CSplitterWnd* pWnd = (CSplitterWnd*)GetParent();
	((CLinkListDraw*)(pWnd->GetPane(0, 0)))->Sort1();
}