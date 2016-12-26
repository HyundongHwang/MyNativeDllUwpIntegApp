// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MYSIMPLENATIVEDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MYSIMPLENATIVEDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MYSIMPLENATIVEDLL_EXPORTS
#define MYSIMPLENATIVEDLL_API extern "C" __declspec(dllexport)
#else
#define MYSIMPLENATIVEDLL_API extern "C" __declspec(dllimport)
#endif

//// This class is exported from the MySimpleNativeDll.dll
//class MYSIMPLENATIVEDLL_API CMySimpleNativeDll {
//public:
//	CMySimpleNativeDll(void);
//	// TODO: add your methods here.
//};

MYSIMPLENATIVEDLL_API int nMySimpleNativeDll;

MYSIMPLENATIVEDLL_API int fnMySimpleNativeDll(void);

MYSIMPLENATIVEDLL_API int Add(int x, int y);

MYSIMPLENATIVEDLL_API LPCWSTR GetStr();

MYSIMPLENATIVEDLL_API void MyStrCpy(LPWSTR wStr, LPCWSTR wStr2);

MYSIMPLENATIVEDLL_API LPCWSTR MyPassByteArray(unsigned char* pBuf, int iIdx);

MYSIMPLENATIVEDLL_API LPCWSTR MyStrConcat(LPCSTR szStr, LPCSTR szStr2);

extern "C" typedef void (*PFUNC_MYCALLBACK) (LPCWSTR wLog);

MYSIMPLENATIVEDLL_API void MyRegisterLogFunc(PFUNC_MYCALLBACK pFuncLog);