#pragma once

struct CExoString
{
    char * m_sString;
    uint32_t m_nBufferLength;
};

#define CEXOSTR_TO_STR(x)   str(((struct CExoString *)x)->m_sString)
