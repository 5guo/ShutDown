// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShutDown.h"
#include "ShutDownDlg.h"
#include "shut.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include <afx.h>

//my include files
#include "FileSave.h"

CFileSave m_FileSave;

static CTime curTime,startTime,endTime;
CTimeSpan remTime,spanTime;
CString m_strOut;

unsigned char Action;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShutDownDlg dialog

CShutDownDlg::CShutDownDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShutDownDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShutDownDlg)
	m_strTime = _T("");
	m_strOutput = _T("");
	m_strEndTime = _T("");
	m_strStartTime = _T("");
	m_strCurrTime = _T("");
	m_strAction = _T("");
	m_force_shutdown = FALSE;
	m_EditHours = 0;
	m_EditMinute = 0;
	m_EditSeconds = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShutDownDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShutDownDlg)
	DDX_Control(pDX, IDC_EDITSEC, m_ctrlEditSecond);
	DDX_Control(pDX, IDC_EDITHOUR, m_ctrlEditHour);
	DDX_Control(pDX, IDC_EDITMIN, m_ctrlEditMinute);
	DDX_Control(pDX, IDC_SAVE_LIST, m_ctrlSaveList);
	DDX_Control(pDX, IDC_SPINHOUR, m_ctrSpinHour);
	DDX_Control(pDX, IDC_SPINMIN, m_ctrSpinMin);
	DDX_Control(pDX, IDC_SPINSEC, m_ctrSpinSec);
	DDX_Text(pDX, IDC_OUTPUT, m_strOutput);
	DDX_Text(pDX, IDC_ENDTIME, m_strEndTime);
	DDX_Text(pDX, IDC_STARTTIME, m_strStartTime);
	DDX_Text(pDX, IDC_CURRTIME, m_strCurrTime);
	DDX_Text(pDX, IDC_ACTION, m_strAction);
	DDX_Check(pDX, IDC_FORCE_SHTDOWN, m_force_shutdown);
	DDX_Text(pDX, IDC_EDITHOUR, m_EditHours);
	DDV_MinMaxInt(pDX, m_EditHours, 0, 24);
	DDX_Text(pDX, IDC_EDITMIN, m_EditMinute);
	DDV_MinMaxInt(pDX, m_EditMinute, 0, 59);
	DDX_Text(pDX, IDC_EDITSEC, m_EditSeconds);
	DDV_MinMaxInt(pDX, m_EditSeconds, 0, 59);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShutDownDlg, CDialog)
	//{{AFX_MSG_MAP(CShutDownDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOGOFF, OnLogoff)
	ON_BN_CLICKED(IDC_SHUTDOWN, OnShutdown)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RESTART, OnRestart)
	ON_COMMAND(ID_ABOUTBOX, OnAboutbox)
	ON_BN_CLICKED(IDC_ADDTOLIST, OnAddtolist)
	ON_BN_CLICKED(IDC_REMFROMLIST, OnRemfromlist)
	ON_CBN_SELCHANGE(IDC_SAVE_LIST, OnSelchangeSaveList)
	ON_BN_CLICKED(IDC_ESCAPE, OnEscape)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShutDownDlg message handlers

BOOL CShutDownDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_ctrSpinHour.SetBase(10);
	m_ctrSpinHour.SetRange(0,24);
	m_ctrSpinHour.SetPos(0);

	m_ctrSpinMin.SetBase(10);
	m_ctrSpinMin.SetRange(0,59);
	m_ctrSpinMin.SetPos(0);
	
	m_ctrSpinSec.SetBase(10);
	m_ctrSpinSec.SetRange(0,59);
	m_ctrSpinSec.SetPos(0);

	int res=shut();

	UpdateSaveList();

	m_ctrlSaveList.SetCurSel(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShutDownDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShutDownDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShutDownDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CShutDownDlg::OnOK() 
{
	// TODO: Add extra validation here
	OnShutdown();
	//CDialog::OnOK();
}

void CShutDownDlg::OnShutdown() 
{
	// TODO: Add your control notification handler code here
	if(!UpdateData()) return;
	
	if(m_force_shutdown == 1) ProcessCommand(EWX_POWEROFF|EWX_FORCE);
	else ProcessCommand(EWX_POWEROFF);

	UpdateData(false);
}

void CShutDownDlg::OnLogoff() 
{
	// TODO: Add your control notification handler code here
	if(!UpdateData(true)) return;

	if(m_force_shutdown == 1) ProcessCommand(EWX_LOGOFF|EWX_FORCE);
	else ProcessCommand(EWX_LOGOFF);

	UpdateData(false);
}

void CShutDownDlg::OnRestart() 
{
	// TODO: Add your control notification handler code here
	if(!UpdateData(true)) return;
	
	if(m_force_shutdown == 1) ProcessCommand(EWX_REBOOT|EWX_FORCE);
	else ProcessCommand(EWX_REBOOT);

	UpdateData(false);
}
void CShutDownDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	UpdateData();
	switch(nIDEvent)
	{
	case 3:{

		curTime=CTime::GetCurrentTime();
		remTime=endTime-curTime;
		m_strCurrTime=curTime.Format("%H:%M:%S");
		
		SetTimer(3,1000,NULL);
		if(remTime<=0){
			ExitWindowsEx(Action,0);
			m_strOutput="";

			//exit application
			exit(0);
		}//if remTime==0
		m_strOutput=remTime.Format("%H:%M:%S");
		UpdateData(false);
		}
	
	}//switch
	CDialog::OnTimer(nIDEvent);

}

void CShutDownDlg::OnAboutbox() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CShutDownDlg::OnAddtolist() 
{
	// TODO: Add your control notification handler code here
	UpdateData();

	FILE_DATA_STR data;

	data.usHours = m_EditHours;
	data.usMinutes = m_EditMinute;
	data.usSeconds = m_EditSeconds;

	//check for 0 values for all fields
	if(data.usHours == 0 && data.usMinutes == 0 && data.usSeconds == 0) return;

	m_FileSave.AddDataToFile(data);

	UpdateSaveList();

	m_ctrlSaveList.SetCurSel(m_ctrlSaveList.GetCount()-1);
	UpdateData(false);
}

void CShutDownDlg::OnRemfromlist() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	unsigned char ucSel = m_ctrlSaveList.GetCurSel();
	if(ucSel <= 0) return;
	
	m_FileSave.RemoveDataByIndex(ucSel);

	UpdateSaveList();

	if(m_ctrlSaveList.GetCount() <= ucSel)
		m_ctrlSaveList.SetCurSel(m_ctrlSaveList.GetCount()-1);
	else m_ctrlSaveList.SetCurSel(ucSel);

	UpdateData(false);
}

void CShutDownDlg::UpdateSaveList()
{
	//read file data
	m_FileSave.ReadData();
	CString str;
	//add read data to drop down control
	m_ctrlSaveList.ResetContent();
	//add element with name "No Selection"
	m_ctrlSaveList.AddString("No Selection");

	for(int i = 0; i < m_FileSave.GetDataCount(); i++) {
		//compose element string
		str.Format("%d hour %d min %d sec", m_FileSave.GetDataByIndex(i).usHours, m_FileSave.GetDataByIndex(i).usMinutes, m_FileSave.GetDataByIndex(i).usSeconds);

		//add element to string
		m_ctrlSaveList.AddString(str);
	}
}

void CShutDownDlg::OnSelchangeSaveList() 
{
	// TODO: Add your control notification handler code here
	UpdateData();

	if(m_ctrlSaveList.GetCurSel() > 0 ) {
		//clear edif field for hours minute and seconds
		m_EditHours = 0;
		m_EditMinute = 0;
		m_EditSeconds = 0;
		
		//edit and spin controls
		MakeEditTimeEnabled(false);
		UpdateData(false);
	}
	else MakeEditTimeEnabled(true);
	
}

void CShutDownDlg::MakeEditTimeEnabled(const boolean bValue)
{
	m_ctrlEditHour.EnableWindow(bValue);
	m_ctrSpinHour.EnableWindow(bValue);

	m_ctrlEditMinute.EnableWindow(bValue);
	m_ctrSpinMin.EnableWindow(bValue);

	m_ctrlEditSecond.EnableWindow(bValue);
	m_ctrSpinSec.EnableWindow(bValue);
}

void CShutDownDlg::OnEscape() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData();

	if(m_ctrlSaveList.GetCurSel() <= 0 ) {
		//enable edit and spin controls
		MakeEditTimeEnabled(true);
	}

	//clear display data
	m_strEndTime = "";
	m_strStartTime = "";
	m_strAction = "";
	m_strCurrTime = "";
	m_strOutput = "";
	//stop timer
	KillTimer(3);

	UpdateData(false);
}

void CShutDownDlg::ProcessCommand(const unsigned char cmd)
{
	CTimeSpan spanTime;
	unsigned char ucSel = m_ctrlSaveList.GetCurSel();

	//if drop down menu selection is not == 0 ("No Selection") -> set span according to saved data
	if(m_ctrlSaveList.GetCurSel() > 0) 
		spanTime = CTimeSpan(0,m_FileSave.GetDataByIndex(ucSel-1).usHours,
		m_FileSave.GetDataByIndex(ucSel-1).usMinutes,
		m_FileSave.GetDataByIndex(ucSel-1).usSeconds);
	else 
		spanTime = CTimeSpan(0,m_EditHours,m_EditMinute,m_EditSeconds);
	
	if(spanTime>0){
		//disable edit and spin controls
		MakeEditTimeEnabled(false);

		startTime=CTime::GetCurrentTime();
		endTime=startTime+spanTime;
		m_strOutput = spanTime.Format("%H:%M:%S");
		m_strCurrTime = startTime.Format("%H:%M:%S");
		m_strEndTime = endTime.Format("%H:%M:%S");
		m_strStartTime = startTime.Format("%H:%M:%S");
		
		//if(cmd & EWX_FORCE ) 
		//compose strin action command
		CString strAction;

		if(cmd & EWX_POWEROFF)
			strAction = "Shut Down Computer\n";
	
		else if(cmd & EWX_REBOOT)
			strAction = "Reboot Computer\n";
		
		else //  EWX_LOGOFF ==  0x00000000
			strAction = "Log Off Computer\n";

		//add force string
		if(cmd & EWX_FORCE ) strAction = strAction+"Force";

		m_strAction = strAction;
		SetTimer(3,500,NULL);

		//set action according to input value
		Action = cmd;
	}
}
