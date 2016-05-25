#include "Exception.h"


Exception::Exception()
{
    strcpy(m_message, "Default Exception");
}
Exception::Exception(char * msg)
{
    
}
Exception::Exception(const Exception & cp)
{
    
}

Exception::~Exception()
{
    
}

Exception & Exception::operator = (const Exception &)
{
    
}
const char * Exception::getMessage()
{
    
}
void Exception::setMessage(char * msg)
{
    
}
