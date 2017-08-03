// LinkList.h: interface for the CLinkList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINKLIST_H__D17E4BC7_E140_42A1_83B9_C2DD47E34755__INCLUDED_)
#define AFX_LINKLIST_H__D17E4BC7_E140_42A1_83B9_C2DD47E34755__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "math.h"
#include <afxtempl.h>
#include <afxwin.h>
#include <afxext.h>
#include "ListNode.h"

class CLinkList  
{
public:
	CLinkList();//构造函数
	virtual ~CLinkList();//析构函数
	void AddTail(CPoint vPoint,CString vString);//尾插法建立单链表
	void InsertNode(CPoint vPoint,int vPos,CString vString);//单链表中插入结点
	void DeleteNode(CPoint vPoint,int vPos);//单链表删除结点

	//删除链表只保留头指针
	void CleanList(CPoint vPoint);

	BOOL Search(CString vString);//按值查找,添加了一个CDC

	bool Searching(CString vString,int vPos);//将箭头移动
	int CountNode();

	void DrawArrow(CPoint vBeginPoint, CPoint vEndpoint, CDC *pDC);//绘制箭头
	bool DrawLinkNode(CListNode *vPListNode, CDC *pDC);//绘制结点
	bool DrawLinkList(CDC *pDC);//绘制单链表
	void DrawPolyLine(CPoint curpoint, CPoint nextpoint, CDC *pDC);//绘制折线
	void DrawSearchArrow(CDC *pDC);//绘制查找结果箭头
	void ClearSearchArrow(CDC *pDC);
	void TiaoZheng(CPoint vPoint);

	void Sort(CPoint vPoint);
	void Sort1(CPoint vPoint);
	//void Daozhi();

public:

	CTypedPtrList <CObList,CListNode*>   m_LinkList; //单向链表容器
private:
	CListNode* m_pCurLNode;//结点指示器
	CListNode* n_pCurLNode;//结点指示器
};

#endif // !defined(AFX_LINKLIST_H__D17E4BC7_E140_42A1_83B9_C2DD47E34755__INCLUDED_)
