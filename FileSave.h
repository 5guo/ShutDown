// FileSave.h: interface for the CFileSave class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILESAVE_H__94948CD6_32ED_485E_8F23_98BE228A49B5__INCLUDED_)
#define AFX_FILESAVE_H__94948CD6_32ED_485E_8F23_98BE228A49B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct{
	unsigned short usHours;
	unsigned short usMinutes;
	unsigned short usSeconds;
}FILE_DATA_STR;

class CFileSave  
{
public:
	void ReadData(void);
	void AddDataToFile(FILE_DATA_STR data);
	unsigned char GetDataCount(void);
	FILE_DATA_STR GetDataByIndex(const unsigned char );
	void RemoveDataByIndex(const unsigned char);
	CFileSave();
	virtual ~CFileSave();

private:
	CFile m_File;
	FILE_DATA_STR * m_pData;
	unsigned char m_ucCount;
};

#endif // !defined(AFX_FILESAVE_H__94948CD6_32ED_485E_8F23_98BE228A49B5__INCLUDED_)
