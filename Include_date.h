#pragma once
#include "TLog_r.h"

enum categorry {INFORMATIONr,WARNINGr,ERRORr};

struct LogDate
{
 std::time_t DateTime;
 std::string Message;
 std::string ProcedureName;
 categorry   Cat;

 LogDate() = delete;
 LogDate(const std::string& Message,const std::string& PName, const categorry& Cat)
 {
  std::time_t second = time(NULL);
//  std::localtime(&second);


  this->DateTime      = second;
  this->Message       = Message;
  this->ProcedureName = PName;
  this->Cat           = Cat;
 };

   bool operator ==(const LogDate& last)
  {

   if ((this->DateTime == last.DateTime) || (this->Message == last.Message)||
      (this->Cat == last.Cat))
   {
    return true;
   };

   return false;
  };

 ~LogDate(){};
};
