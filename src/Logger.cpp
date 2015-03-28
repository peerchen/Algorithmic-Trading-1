//
//  Logger.cpp
//  Algorithmic Trading SENG3011
//
//  Created on 03/03/15.
//  Copyright (c) Revitpo. All rights reserved.
//

#include "Logger.h"

namespace std {
	Logger::Logger(string dataFile) {
	output = ofstream(dataFile, ios::trunc);
	if(output.is_open()) {
          isLogging = true;
          output << "Revitpo Version: 1.00" << endl;
          output << "Developed By: Samuel Whitton, Mohammad Ghasembegi, Ian Wong, Jason Ng and Antheny Yu" << endl;
	}
   }

   void Logger::log(int type, string message) {
         if(isLogging) {
               stringstream ss;
               switch(type) {
                     case __LOG_INFO:
                     ss << "[INFO] ";
                     break;
                     case __LOG_ERROR:
                     ss << "[ERROR] ";
                     break;
                     case __LOG_DEBUG:
                     ss << "[DEBUG] ";
                     break;
               }
               ss << Helper::datetime() << ' ';
               ss << message;
               output << ss.str() << endl;
         }
   }


    void Logger::stopLogging() {
         isLogging  = false;
         output.close();
   }

}
