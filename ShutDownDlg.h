// TestDlg.h : header file
//

#if !defined(AFX_TESTDLG_H__AA022D8D_E397_4E38_9844_FBDC25FC8BF6__INCLUDED_)
#define AFX_TESTDLG_H__AA022D8D_E397_4E38_9844_FBDC25FC8BF6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShutDownDlg dialog

class CShutDownDlg : public CDialog
{
// Construction
public:
	void ProcessCommand(const unsigned char cmd);
	void MakeEditTimeEnabled(const boolean bValue);
	void UpdateSaveList();
	CShutDownDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShutDownDlg)
	enum { IDD = IDD_TEST_DIALOG };
	CEdit	m_ctrlEditSecond;
	CEdit	m_ctrlEditHour;
	CEdit	m_ctrlEditMinute;
	CComboBox	m_ctrlSaveList;
	CSpinButtonCtrl	m_ctrSpinHour;
	CSpinButtonCtrl	m_ctrSpinMin;
	CSpinButtonCtrl	m_ctrSpinSec;
	CEdit	m_ctrTime;
	CString	m_strTime;
	CString	m_strHour;
	CString	m_strMinute;
	CString	m_strOutput;
	CString	m_strSecond;
	CString	m_strEndTime;
	CString	m_strStartTime;
	CString	m_strCurrTime;
	CString	m_strAction;
	BOOL	m_force_shutdown;
	short	m_EditHours;
	short	m_EditMinute;
	short	m_EditSeconds;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShutDownDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShutDownDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnLogoff();
	afx_msg void OnShutdown();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnRestart();
	afx_msg void OnAboutbox();
	afx_msg void OnAddtolist();
	afx_msg void OnRemfromlist();
	afx_msg void OnSelchangeSaveList();
	afx_msg void OnEscape();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLG_H__AA022D8D_E397_4E38_9844_FBDC25FC8BF6__INCLUDED_)
