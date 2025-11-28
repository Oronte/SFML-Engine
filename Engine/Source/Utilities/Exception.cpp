#include "Exception.h"
#include "Logger.h"

engine::Exception::Exception(const Error& _error, const Error& _debugInfo)
{
	message = _error + " " + _debugInfo;
	if (_debugInfo == "") message += DEBUG_INFO;

	engine::Logger::Shutdown();
}

const char* engine::Exception::what() const noexcept
{
	return message.c_str();
}

const char* engine::Exception::What() const
{
	return what();
	
}
