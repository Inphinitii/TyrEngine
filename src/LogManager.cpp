#include "LogManager.h"
#include <iostream>

Log::Log(std::string _fileName)
{
	m_fileName = _fileName.c_str();
	m_file = NULL;
}

Log::~Log()
{
	fclose(m_file);
	delete m_file;
	m_file = NULL;
}

bool Log::Open(const char* _mode)
{
	m_pathName = m_logDirectory + m_fileName;

	if(m_file == NULL)
	{
		m_file = fopen(m_pathName.c_str(), _mode);

		if(m_file != NULL)
			return true;
	}
	return false;
}

bool Log::Close()
{
	if(m_file != NULL)
	{
		if(fclose(m_file) != 0)
			return false;

		m_file = NULL;
		return true;
	}
	return false;
}

bool Log::Write(std::string _toWrite , PRIORITY _type)
{
	if(m_file != NULL)
	{
		std::string _priorityLevel =  PriorityString[static_cast<int>(_type)];
		std::string _output = "[" + _priorityLevel + "]:" + _toWrite;
		fputs(_output.c_str(), m_file);

		return true;
	}
	return false;
}

LogManager::LogManager()
{
	//ctor
}

LogManager::~LogManager()
{
	//dtor
}
