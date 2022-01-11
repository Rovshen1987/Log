#pragma once
#include "TLog_r.h"

enum categorry {INFORMATIONr,WARNINGr,ERRORr};

struct LogDate
{
 std::time_t DateTime;
 std::string ProcedureName;
 std::string ProcedureValue;
 std::string Message;
 categorry   Cat;

 LogDate() = delete;
 LogDate(const std::string& PName, const std::string& PValue, const std::string& Message, const categorry& Cat)
 {
  std::time_t second = time(NULL);



  this->DateTime       = second;
  this->ProcedureName  = PName;
  this->ProcedureValue = PValue;
  this->Message        = Message;
  this->Cat            = Cat;
 };

   bool operator ==(const LogDate& last)
  {

   if ((this->DateTime == last.DateTime) || (this->Message == last.Message)||
      (this->Cat == last.Cat) || (this->ProcedureValue == last.ProcedureValue))
   {
    return true;
   };

   return false;
  };

 ~LogDate(){};
};
