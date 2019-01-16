#include "data.h"

Data::Data()
{

}

//jsoncpp
//序列化
void Data::Serialize(std::string &out_string)
{
  Json::Value root;
  root["nick_name"] = nick_name;
  root["school"] = school;
  root["message"] = message;
  root["type"] = type;

  //序列化
  //StyledWriter
  Json::FastWriter w;
  out_string = w.write(root);
}

//反序列化
void Data::Unserialize(std::string &in_string)
{
  Json::Value root;
  Json::Reader r;
  r.parse(in_string, root, false);

  nick_name = root["nick_name"].asString();
  school = root["school"].asString();
  message = root["message"].asString();
  type = root["type"].asString();
}

Data::~Data()
{

}

int main()
{
  Data d;
  d.nick_name = "控心";
  d.school = "XSUT";
  d.message = "你们好";
  d.type = "None";

  std::string out_string;
  d.Serialize(out_string);

  std::cout << out_string << std::endl;
  return 0;
}
