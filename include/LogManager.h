#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <stdio.h>
#include <string>

#pragma clang diagnostic ignored "-Wc++98-compat"
//TODO INCLUDE TIMESTAMPS

class Log
{
public:
	enum PRIORITY 								 { URGENT, 	  WARNING, 	 SUCCESS, 	INFO};
	const char* PriorityString[4] = {"URGENT", "WARNING", "SUCCESS", "INFO"};

	bool Open(const char* _mode);
	bool Write(std::string _toWrite, PRIORITY _type);
	bool Close();
	virtual ~Log();
	Log(std::string _fileName);

private:
	FILE* 					m_file;
	std::string   	m_fileName;
	std::string   	m_logDirectory = "./Logs/";
	std::string  		m_pathName;
};

class LogManager
{
	public:
		LogManager();
		~LogManager();

	protected:
	private:
};

#endif // LOGMANAGER_H
