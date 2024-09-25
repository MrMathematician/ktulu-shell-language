#include <bits/stdc++.h>
#include <fstream>

class Command{
private:
  std::unordered_map<std::string, std::string> command_map;
  void read_file(){
    std::ifstream input_file("commands.bin");
    if(!input_file.is_open()){
      std::cerr << "Error opening the file!!!\n";
    }
      
  }
public:
  std::string command_buffer;
  Command(std::string command_buffer){
    this -> command_buffer = command_buffer;
  }

  void command_parse(){
    read_file();
    std::ifstream inputFile("command.add");
    if(!inputFile.is_open()){
      std::cerr << "Error while opening the file!\n";
      return;
    }

  }
};





