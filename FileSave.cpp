// FileSave.cpp: implementation of the CFileSave class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "shutdown.h"
#include "FileSave.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFileSave::CFileSave()
{
	//open file
	if(!m_File.Open("shutdown_save.txt", CFile::modeReadWrite)) {
		//if file do not exist create new file
		m_File.Open("shutdown_save.txt", CFile::modeCreate|CFile::modeReadWrite);
	};
}

CFileSave::~CFileSave()
{
	m_File.Close();
}

void CFileSave::AddDataToFile(FILE_DATA_STR Data)
{
	//add data to file
	m_File.Write(&Data, sizeof(FILE_DATA_STR));

	m_File.Flush();
}

void CFileSave::ReadData(void)
{
	
	m_ucCount = 0;
	//get element count

	delete m_pData;

	m_pData = new FILE_DATA_STR;

	//set file pointer to begin and read all data
	m_File.SeekToBegin();
	while(m_File.Read(m_pData, sizeof(FILE_DATA_STR)) != 0) {
		m_ucCount++;
	}

	delete m_pData;
	
	//allocate array for all elements
	m_pData = new FILE_DATA_STR[m_ucCount];

	//set file pointer to begin and read all data
	m_File.SeekToBegin();
	m_ucCount = 0;
	//read all elements again
	while(m_File.Read(m_pData+m_ucCount, sizeof(FILE_DATA_STR)) != 0) {
		m_ucCount++;
	}

	//return pointer to data and count
}
void CFileSave::RemoveDataByIndex(const unsigned char ucRemIndex) {

	//rename file name

	//close old file
	CFile TempFile;
	//create new file and open d
	TempFile.Open("temp.txt", CFile::modeCreate|CFile::modeReadWrite);

	//copy data from old to new file except removed index
	FILE_DATA_STR TempData;
	unsigned char index = 0;
	m_File.SeekToBegin();
	while(m_File.Read(&TempData, sizeof(FILE_DATA_STR)) != 0) {
		index++;
		if(index == ucRemIndex) continue;
		TempFile.Write(&TempData, sizeof(FILE_DATA_STR));
	}

	TempFile.Close();
	
	//close and remove old file
	m_File.Close();
	m_File.Remove("shutdown_save.txt");

	//rename temp file to original file name
	m_File.Rename("temp.txt", "shutdown_save.txt");

	//open new file
	m_File.Open("shutdown_save.txt", CFile::modeReadWrite);
}

unsigned char CFileSave:: GetDataCount(void) {
	return m_ucCount;
}

FILE_DATA_STR CFileSave:: GetDataByIndex(const unsigned char ucIndex) {
	return *(m_pData+ucIndex);
}