#pragma once
#include <vector>
#include <string>
#include "Include_date.h"
#include <tuple>
#include <fstream>
#include <ctime>
#include <direct.h>
#include <functional>

class TLog_r
{
  std::string Path;
  categorry   CategorryIn;
  bool        Active;

  std::vector<LogDate> ListError;
  std::vector<LogDate> ListWarning;
  std::vector<LogDate> ListInformation;


        void         initialisation();
        void         destroy();
        std::time_t  get_time();
        std::string  get_directory();
        bool         check_log_date(const categorry& cat, const LogDate& date);
static  void         paste_line(std::ostream& out);
static  std::string  sget_time();
static  std::string  sget_time(const std::time_t& tobj);

static  std::string  vget(const std::vector<std::tuple<std::string,std::string>>& obj);
static  std::string  vget(const std::vector<std::tuple<std::string,bool>>& obj);
static  std::string  vget(const std::vector<std::tuple<std::string,int>>& obj);


  friend std::ofstream& operator<<(std::ofstream& out,const std::vector<LogDate>& List);
  std::string  SaveFormat(const std::vector<LogDate>& List);

public:

  TLog_r();
  TLog_r(const std::string& SaveLog);
  ~TLog_r();

  void         AddLog(const std::string& PName, const std::string& PValue, const std::string& Message,  const categorry& cat);
  void         AddLog(std::tuple<std::string,std::string,std::string,categorry>& RTuple);

  void         SaveLog();
  void         SaveLog(const std::string& Path);

  std::string  GetPath();
  void         SetPath(const std::string& Path);

  categorry    GetCategorryIn();
  void         SetCategorryIn(const categorry& CategorryIn);

  bool         GetActive();
  void         SetActive(const bool& Active);
};
