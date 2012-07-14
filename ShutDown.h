// ShutDown.h : main header file for the TEST application
//

#if !defined(AFX_TEST_H__001B1148_7E47_4661_9CE8_272BC76C8F0F__INCLUDED_)
#define AFX_TEST_H__001B1148_7E47_4661_9CE8_272BC76C8F0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestApp:
// See ShutDown.cpp for the implementation of this class
//

class CShutDownApp : public CWinApp
{
public:
	CShutDownApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_H__001B1148_7E47_4661_9CE8_272BC76C8F0F__INCLUDED_)
