// MySimpleNativeDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MySimpleNativeDll.h"


// This is an example of an exported variable
MYSIMPLENATIVEDLL_API int nMySimpleNativeDll=0;

// This is an example of an exported function.
MYSIMPLENATIVEDLL_API int fnMySimpleNativeDll(void)
{
    return 42;
}

//// This is the constructor of a class that has been exported.
//// see MySimpleNativeDll.h for the class definition
//CMySimpleNativeDll::CMySimpleNativeDll()
//{
//    return;
//}

PFUNC_MYCALLBACK s_pFuncLog = NULL;

MYSIMPLENATIVEDLL_API int Add(int x, int y)
{
    s_pFuncLog(L"hello");

    {
        int n = 123;
        CString strMsg = L"";
        strMsg.Format(L"n : %lld\n", n);
        ::OutputDebugString(strMsg);//hhddebug
    }

    //CStringW strTest = L"abc";
    //OutputDebugString(strTest);
    //return x + y + strTest.GetLength();

    return x + y;
}

MYSIMPLENATIVEDLL_API LPCWSTR GetStr()
{
    CStringW strTmp = L"abc°¡³ª´Ù123";
    return strTmp.AllocSysString();
}

MYSIMPLENATIVEDLL_API void MyStrCpy(LPWSTR wStr, LPCWSTR wStr2)
{
    lstrcpy(wStr, wStr2);
}

MYSIMPLENATIVEDLL_API LPCWSTR MyPassByteArray(unsigned char* pBuf, int iIdx)
{
    CStringW strTmp;
    strTmp.Format(L"pBuf[%lld] : %c(0x%x)", iIdx, pBuf[iIdx], pBuf[iIdx]);
    BSTR bStr = strTmp.AllocSysString();
    return bStr;
}

MYSIMPLENATIVEDLL_API LPCWSTR MyStrConcat(LPCSTR szStr, LPCSTR szStr2)
{
    USES_CONVERSION;
    CStringA strTmp;
    strTmp.Format("%s, %s", szStr, szStr2);
    BSTR bStr = strTmp.AllocSysString();
    return bStr;
}

MYSIMPLENATIVEDLL_API void MyRegisterLogFunc(PFUNC_MYCALLBACK pFuncLog)
{
    s_pFuncLog = pFuncLog;
}