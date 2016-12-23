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

MYSIMPLENATIVEDLL_API int Add(int x, int y)
{
    return x + y;
}