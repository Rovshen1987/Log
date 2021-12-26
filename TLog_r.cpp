#include "TLog_r.h"
/* class TLog_r*/

//------------------------------CONSTRUCTOR/DESTRUCTOR--------------------------
TLog_r::TLog_r()
{
  this->Path   = this->get_directory();
  this->initialisation();
};

//------------------------------------------------------------------------------
TLog_r::TLog_r(const std::string& SaveLog)
{
  this->Path   = SaveLog;
  this->initialisation();
};

//------------------------------------------------------------------------------
TLog_r::~TLog_r()
{
  this->destroy();
};

//------------------------------------------------------------------------------

//------------------------------PUBLIC------------------------------------------

//------------------------------------------------------------------------------
void TLog_r::AddLog(const std::string& PName, const std::string& Message,  const categorry& Cat)
{

  if (this->Active != true)
  {
  return;
  };

    switch (Cat)
    {
    case categorry::INFORMATIONr:{
                                 this->ListInformation.push_back(LogDate{Message,PName, Cat});
                                 break;
                                 };
    case categorry::WARNINGr:{
                             this->ListWarning.push_back(LogDate{Message,PName, Cat});
                             break;
                             };

    case categorry::ERRORr:{
                           this->ListError.push_back(LogDate{Message,PName, Cat});
                           };

     default:{};
    };
};

//------------------------------------------------------------------------------
void TLog_r::SaveLog()
{
  std::function<std::string (const std::vector<LogDate>& List)> f;
  f = this->SaveFormat;

    switch (this->CategorryIn)
    {
    case categorry::INFORMATIONr:{
                                 f(this->ListInformation);
                                 break;
                                 };
    case categorry::WARNINGr:{
                              f(this->ListWarning);
                              break;
                             };

    case categorry::ERRORr:{
                           f(this->ListError);
                           };

     default:{};
    };
};

//------------------------------------------------------------------------------
void TLog_r::SaveLog(const std::string& Path)
{
   this->Path = Path;
   this->SaveLog();
};

//------------------------------------------------------------------------------
std::string TLog_r::GetPath()
{
  return this->Path;
};

//------------------------------------------------------------------------------
void TLog_r::SetPath(const std::string& Path)
{
  this->Path = Path;
};

//------------------------------------------------------------------------------
categorry TLog_r::GetCategorryIn()
{
  return this->CategorryIn;
};

//------------------------------------------------------------------------------
void TLog_r::SetCategorryIn(const categorry& CategorryIn)
{
  this->CategorryIn = static_cast<categorry>(CategorryIn);
};

//------------------------------------------------------------------------------
bool TLog_r::GetActive()
{
  return this->Active;
};

//------------------------------------------------------------------------------
void TLog_r::SetActive(const bool& Active)
{
  this->Active = Active;
};

//------------------------------------------------------------------------------

//------------------------------PRIVATE-----------------------------------------
void TLog_r::initialisation()
{
  this->CategorryIn = ERRORr;
  this->Active      = true;
};

//------------------------------------------------------------------------------
void TLog_r::destroy()
{

};

//------------------------------------------------------------------------------
std::time_t TLog_r::get_time()
{
  std::time_t second = time(NULL);
  std::localtime(&second);
  return second;
};

//------------------------------------------------------------------------------
std::string TLog_r::get_directory()
{
char current_work_dir[FILENAME_MAX];
_getcwd(current_work_dir, sizeof(current_work_dir));
 return std::string(current_work_dir)+std::string("\\");
};

//------------------------------------------------------------------------------
bool TLog_r::check_log_date(const categorry& Cat, const LogDate& date)
{

switch(Cat)
{

case categorry::INFORMATIONr:{
                               for (auto& p: this->ListInformation)
                               {
                                  if (p == date)
                                  {
                                    return true;
                                  }
                               }
                              break;
                             };
case categorry::WARNINGr:{
                               for (auto& p: this->ListWarning)
                               {
                                  if (p == date)
                                  {
                                    return true;
                                  }
                               }
                              break;
                         };

case categorry::ERRORr:{
                               for (auto& p: this->ListError)
                               {
                                  if (p == date)
                                  {
                                    return true;
                                  }
                               }
                       };

     default:{};

};

return false;
};

//------------------------------------------------------------------------------
void TLog_r::paste_line(std::ostream& out)
{
 out << "------------------------------------\n";
};

//------------------------------------------------------------------------------
std::string TLog_r::sget_time()
{
  std::time_t t      = std::time(NULL);
  struct tm* tim     = std::localtime(&t);
  std::string result = "";

  if (t<1)
  {
   return "";
  }

  std::string wday_rus = "";

  switch(tim->tm_wday)
  {
    case 1 :{wday_rus = "пн.  | "; break;}
    case 2 :{wday_rus = "вт.  | "; break;}
    case 3 :{wday_rus = "ср.  | "; break;}
    case 4 :{wday_rus = "чт.  | "; break;}
    case 5 :{wday_rus = "пт.  | "; break;}
    case 6 :{wday_rus = "сб.  | "; break;}
    case 0 :{wday_rus = "вс.  | "; break;}
  };

  (tim->tm_hour<10)?result = std::string("0") + std::to_string(tim->tm_hour)
                   :result = std::to_string(tim->tm_hour);
  result = result + std::string(":");

  (tim->tm_min<10)?result = result + std::string("0") + std::to_string(tim->tm_min)
                  :result = result + std::to_string(tim->tm_min);
  result = result +std::string(":");

  (tim->tm_sec<10)?result = result + std::string("0") + std::to_string(tim->tm_sec)
                  :result = result + std::to_string(tim->tm_sec);
  result = result + std::string(" | ");

  (tim->tm_mday<10)?result = result + std::string("0") + std::to_string(tim->tm_mday)
                   :result = result + std::to_string(tim->tm_mday);
  result = result + std::string(".");

  ((tim->tm_mon+1)<10)?result = result + std::string("0") + std::to_string(tim->tm_mon + 1)
                      :result = result + std::to_string(tim->tm_mon + 1);
  result = result + std::string(".") + std::to_string(tim->tm_year + 1900)
           + std::string("г. ") + wday_rus;

  return result;
};

std::string TLog_r::sget_time(const std::time_t& tobj)
{
struct tm* tim     = std::localtime(&tobj);
  std::string result = "";

  if (tobj<1)
  {
   return "";
  }

  std::string wday_rus = "";

  switch(tim->tm_wday)
  {
    case 1 :{wday_rus = "пн.  | "; break;}
    case 2 :{wday_rus = "вт.  | "; break;}
    case 3 :{wday_rus = "ср.  | "; break;}
    case 4 :{wday_rus = "чт.  | "; break;}
    case 5 :{wday_rus = "пт.  | "; break;}
    case 6 :{wday_rus = "сб.  | "; break;}
    case 0 :{wday_rus = "вс.  | "; break;}
  };

  (tim->tm_hour<10)?result = std::string("0") + std::to_string(tim->tm_hour)
                   :result = std::to_string(tim->tm_hour);
  result = result + std::string(":");

  (tim->tm_min<10)?result = result + std::string("0") + std::to_string(tim->tm_min)
                  :result = result + std::to_string(tim->tm_min);
  result = result +std::string(":");

  (tim->tm_sec<10)?result = result + std::string("0") + std::to_string(tim->tm_sec)
                  :result = result + std::to_string(tim->tm_sec);
  result = result + std::string(" | ");

  (tim->tm_mday<10)?result = result + std::string("0") + std::to_string(tim->tm_mday)
                   :result = result + std::to_string(tim->tm_mday);
  result = result + std::string(".");

  ((tim->tm_mon+1)<10)?result = result + std::string("0") + std::to_string(tim->tm_mon + 1)
                      :result = result + std::to_string(tim->tm_mon + 1);
  result = result + std::string(".") + std::to_string(tim->tm_year + 1900)
           + std::string("г. ") + wday_rus;

  return result;
};

//------------------------------------------------------------------------------
std::ofstream& operator <<(std::ofstream& out,const std::vector<LogDate>& List)
{
 std::time_t sec;
 out << "  create to LOG file !\n" << TLog_r::sget_time() << std::endl;
 TLog_r::paste_line(out);
 for (auto& p: List)
 {
  struct tm * time1 = std::localtime(&p.DateTime);
  std::string Cats;
  switch(p.Cat)
  {
  case categorry::INFORMATIONr:{
                                 Cats = "INFORMATION";
                                 break;
                               };

  case categorry::WARNINGr:   {
                                 Cats = "WARNING";
                                 break;
                              };

  case categorry::ERRORr:     {
                                 Cats = "ERROR";
                                 break;
                              };
  default     :{};

  };
  out << TLog_r::sget_time(p.DateTime)
      << "  " << p.ProcedureName << "  " << p.Message
      << "  " << Cats << std::endl;
 }
 TLog_r::paste_line(out);
 TLog_r::paste_line(out);
 TLog_r::paste_line(out);
 out <<"\n";
 out << "Length in = "<< List.size()<< ";\n";
  return out;
};




//------------------------------------------------------------------------------
std::string TLog_r::SaveFormat(const std::vector<LogDate>& List)
{

 std::string all_path = this->Path + ("Log.txt");
 std::ofstream out(all_path);

 out << List;

 out.close();


 return " ";
};


