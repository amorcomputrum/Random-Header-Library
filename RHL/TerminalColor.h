#pragma once

#include "Exception.h"

#include <stdlib.h>
#include <string>

namespace RHL{
	namespace TerminalColor{
		//Color TEXT IN TERMINAL
		namespace TEXT_COLOR{
			const std::string BLACK   = "\033[30m";
			const std::string BLUE    = "\033[34m";
			const std::string CYAN    = "\033[36m";
			const std::string GREEN   = "\033[32m";
			const std::string MAGENTA = "\033[35m";
			const std::string RED     = "\033[31m";
			const std::string WHITE   = "\033[37m";
			const std::string YELLOW  = "\033[33m";
		};

		//MODIFY TEXT
		namespace MODIFIER{
			const std::string BOLD      = "\033[1m";
			const std::string FAINT     = "\033[2m";
			const std::string ITALIC    = "\033[3m";
			const std::string RESET     = "\033[0m";
			const std::string REVERSE   = "\033[7m";
			const std::string STRIKE    = "\033[9m";
			const std::string UNDERLINE = "\033[4m";
		}

		//SET TEXT COLOR IN TERMINAL USING 0-255 RANGE
		inline std::string textColorCode(uint8_t textColor){
			return "\033[38;5;" + std::to_string(textColor) + 'm';
		}

		//SET TEXT COLOR IN TERMINAL USING 0-255 RANGE AND MODIFY TEXT
		inline std::string textColorCode(int modifier, int textColor){
			if(modifier > 107){
				throw RHL::exception(TEXT_COLOR::RED + "TerminalColor.h -> INVALID MODIFIER: " + std::to_string(modifier) + MODIFIER::RESET);
			}

			return "\033[" + std::to_string(modifier) + 'm' + "\033[38;5;" + std::to_string(textColor) + 'm';
		}

	}
}