#pragma once

#ifdef MYSIMPLENATIVEDLL_EXPORTS
#define MYSIMPLENATIVEDLL_API extern "C" __declspec(dllexport)
#else
#define MYSIMPLENATIVEDLL_API extern "C" __declspec(dllimport)
#endif

MYSIMPLENATIVEDLL_API int Add(int x, int y);