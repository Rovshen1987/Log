#include <vcl.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused

#include <tchar.h>

#include <stdio.h>
#include <ctime.h>
#include "TLog_r.h"
std::unique_ptr<TLog_r> p = std::make_unique<TLog_r>();

int plus(const int& A,const int& B)
{
 p->AddLog("int plus(const int& A,const int& B)","A + B",WARNINGr);
 return int(A+B);
};

int _tmain(int argc, _TCHAR* argv[])
{
//p->SetActive(true);
//        std::time_t sec  = std::time(NULL);
//        struct tm* wolk  = std::localtime(&sec);
//
//        std::cout << wolk->tm_wday <<std::endl;
//        std::cout << std::asctime(wolk)<<"ol";
          std::cout << plus(36,41) << std::endl;

      p->SetCategorryIn(WARNINGr);
      p->AddLog("main","Message",WARNINGr);
      p->SaveLog();

      std::system("pause");
	return 0;
}
