// Allows multiple logs to all recieve the same input from one source

#pragma once

#include <vector>
#include <string>
#include <functional>

#include "iLogger.h"
#include "Severity.h"

namespace byteofsin::logging {
    class Log {
        public:
            Log(){};
            ~Log(){};

            void AddLog(iLogger& newLog){
                std::reference_wrapper<iLogger> logWrapper = newLog;
                logs.push_back(logWrapper);
            }

            Log& operator << (severity inputSeverity) {
                for(std::reference_wrapper<iLogger> log : logs){
                    log.get() << inputSeverity;
                }

                return *this;
            }

            Log& operator << (std::string const& message){
                for(std::reference_wrapper<iLogger> log : logs){
                    log.get() << message;
                }

                return *this;
            }

            Log& operator << (bytelog::EndLine endl){
                for(std::reference_wrapper<iLogger> log : logs){
                    log.get() << endl;
                }

                return *this;
            }

            Log& operator << (bytelog::Flush flush){
                for(std::reference_wrapper<iLogger> log : logs){
                    log.get() << flush;
                }

                return *this;
            }




        private:
            std::vector <std::reference_wrapper<iLogger>> logs;
    };
};