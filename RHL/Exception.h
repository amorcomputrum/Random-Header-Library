#pragma once

#include <iostream>
#include <exception>
#include <string>

namespace RHL{
	class exception : public std::exception {
	public:
		exception(const char* error){
			std::cerr << error << std::endl;
			exit(1);
		}

		exception(std::string error){
			std::cerr << error << std::endl;
			exit(1);
		}
	};
}