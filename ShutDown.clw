; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CShutDownDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "shutdown.h"
LastPage=0

ClassCount=3
Class1=CTestApp
Class2=CAboutDlg
Class3=CShutDownDlg

ResourceCount=3
Resource1=IDD_TEST_DIALOG
Resource2=IDD_ABOUTBOX (English (U.S.))
Resource3=IDR_MENU1 (English (U.S.))

[CLS:CTestApp]
Type=0
HeaderFile=ShutDown.h
ImplementationFile=ShutDown.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=ShutDownDlg.cpp
ImplementationFile=ShutDownDlg.cpp

[CLS:CShutDownDlg]
Type=0
BaseClass=CDialog
HeaderFile=ShutDownDlg.h
ImplementationFile=ShutDownDlg.cpp
LastObject=IDC_FORCE_SHTDOWN

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg

[DLG:IDD_TEST_DIALOG]
Type=1
Class=CShutDownDlg
ControlCount=25
Control1=IDC_EDITHOUR,edit,1350631552
Control2=IDC_SPINHOUR,msctls_updown32,1342177331
Control3=IDC_EDITMIN,edit,1350631552
Control4=IDC_SPINMIN,msctls_updown32,1342177331
Control5=IDC_EDITSEC,edit,1350631552
Control6=IDC_SPINSEC,msctls_updown32,1342177331
Control7=IDC_SHUTDOWN,button,1342242816
Control8=IDC_LOGOFF,button,1342242816
Control9=IDC_RESTART,button,1342242816
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_OUTPUT,edit,1350633600
Control13=IDC_STATIC,static,1342308352
Control14=IDC_ENDTIME,static,1342308352
Control15=IDC_STATIC,static,1342308354
Control16=IDC_STATIC,static,1342308354
Control17=IDC_STARTTIME,static,1342308352
Control18=IDC_CURRTIME,static,1342308352
Control19=IDC_STATIC,static,1342308354
Control20=IDC_ACTION,static,1342312704
Control21=IDC_FORCE_SHTDOWN,button,1342242819
Control22=IDC_SAVE_LIST,combobox,1344339971
Control23=IDC_REMFROMLIST,button,1342242816
Control24=IDC_ADDTOLIST,button,1342242816
Control25=IDC_ESCAPE,button,1342242816

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[MNU:IDR_MENU1 (English (U.S.))]
Type=1
Class=?
Command1=ID_ABOUTBOX
CommandCount=1

