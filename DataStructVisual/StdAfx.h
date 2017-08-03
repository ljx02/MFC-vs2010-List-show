// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__B7AADD87_E49A_462D_98F6_E6CD0C25CFB2__INCLUDED_)
#define AFX_STDAFX_H__B7AADD87_E49A_462D_98F6_E6CD0C25CFB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls

#define  VIEW_SPLITTER1				1
#define  VIEW_SPLITTER2				2
#define  VIEW_SPLITTER_LINKLIST		11
#define  VIEW_SPLITTER_CIRCLEQUEUE	12 
#define  VIEW_SPLITTER_DEQUEUE		13
#define  VIEW_SPLITTER_BITREE		21
#define  VIEW_SPLITTER_AVLTREE		22
#define  VIEW_SPLITTER_B_TREE		23
#define  VIEW_SPLITTER_UDGRAPHDFS	311
#define  VIEW_SPLITTER_DIGGRAPHDIJ	321
#define  VIEW_SPLITTER_SORT			4

#define  WM_OPENGRAPH		(WM_USER+1)

#endif // _AFX_NO_AFXCMN_SUPPORT

void DrawArrow(CPoint vBeginPoint, CPoint vEndpoint, CDC *pDC);//»æÖÆ¼ýÍ·

int cmp(const void *vAVal,const void *vBVal);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__B7AADD87_E49A_462D_98F6_E6CD0C25CFB2__INCLUDED_)
