#pragma once

#include "TerminalColor.h"

#include <fstream>
#include <ctime>
#include <iostream>
#include <string>

namespace RHL{
	class Logger
	{
	public:
		//Enable Log File
		inline static void enableLoggerFile(std::string path){
			if(!file.is_open()){
				file.open(path.c_str(), std::ios::app);
				std::time_t time = std::time(nullptr);
				file << std::asctime(std::localtime(&time));
			}
		}

		//Disable Log File
		inline static void disableLoggerFile(){
			if(file.is_open())
				file.close();
		}

		//Print Warning To Terminal and log into file(if enabled)
		inline static void critical(std::string critical){
			std::cout << RHL::TerminalColor::textColorCode(1, 160) << "CRITICAL -> " << critical << RHL::TerminalColor::MODIFIER::RESET << "\n";

			if(file.is_open())
				file << "CRITICAL -> " + critical + "\n";
		}

		//Print Warning To Terminal and log into file(if enabled)
		inline static void debug(std::string debug){
			std::cout << RHL::TerminalColor::textColorCode(1, 220) << "DEBUG -> "    << debug    << RHL::TerminalColor::MODIFIER::RESET << "\n";

			if(file.is_open())
				file << "DEBUG -> "    + debug    + "\n";
		}

		//Print Warning To Terminal and log into file(if enabled)
		inline static void info(std::string info){
			std::cout << RHL::TerminalColor::textColorCode(1, 15 ) << "INFO -> "     << info     << RHL::TerminalColor::MODIFIER::RESET << "\n";

			if(file.is_open())
				file << "INFO -> "     + info     + "\n";
		}

		//Print Warning To Terminal and log into file(if enabled)
		inline static void warn(std::string warning){
			std::cout << RHL::TerminalColor::textColorCode(1, 202) << "WARNING -> "  << warning  << RHL::TerminalColor::MODIFIER::RESET <<"\n";

			if(file.is_open())
				file << "WARNING -> "  + warning  + "\n";
		}

	private:
		inline static std::fstream file;
	};
}