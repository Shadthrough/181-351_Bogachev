//For Windows static library is .lib, dynamic is .dll
//For linux static .a, dynamic is .so (source obj)
//Code from static librs is put in .exe after compilation
//If several exe's are using one lib the libs is multiplued
//dynamic librs may be explicit and not
//	1. smth
//	2. Static
//	3. DLL
// 3.1
// Dynamic librs have expantion .dll dynamic link library
// Dll files are supplied seperatly by the same dll file on a user's machine can be
// used by several applications at the same time. Expample is a system programms.
// -: dll is stored as separate file and can be lost, 
// however can be used at the same time by many func
// +: exe's are not becoming hevier because of copying libr in them unlike for the static
// +: DLL may be loaded in memory when needed and than outloaded
// -: dll demands an installer for putting requiered libraries and files
// -: more coplex code structure and more complex exe connection
// 3.2 
// Types of dll connecting
//		Static binding
// dll is loading in RAM by the time exe is runned, if no dll it does not work,
// this way also requeres three files: dll, header and sub lib library, that stores dll adresses
// for constructor
//		Dynamic binding
// +: dll is loaded not when exe is runned but by the time programmer has determined by
// using special func "load library"
// +: third file lib with matching table is not needed,
// funcs inside dll is searched by name using func "getprocadress"
// -: code will be more complex
// 3.3
// Connecting dll to progect
// For static binding:
// header is connected to the initial file, lib with table is loaded into linker,
// path is named for lib, dll must be near .exe
// For dynamic binding:
// same for header, same for near .exe, should be written loadlibrary.
// 3.4
// In point
// In dll may be determined a special func (dllmain), it will be loaded when application is run.

#include "pch.h"
#include <iostream>
#include "../lib/lib.h"


int main()
{
	dynamic_matrix A, B;
	A.input(); A.print();
	B.input(); B.print();
	(A + B).print();
	(A * B).print();
	std::cout << std::endl << A;
	return 0;
}

