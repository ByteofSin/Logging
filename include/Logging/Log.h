/** Title: Logging Header
 *	@version: v0.0.0.1
 *	@author: ByteofSin
 *	Contacts: 
 *		Email: ByteofSin@gmail.com 
 *	Created: 08/22/2022 
 *	Modified: 08/22/2022
 *	@brief: A library to handle logging output
 *	Externals: 
 *	@bug: none yet
 */

#ifndef BOS_LOGGING_H
#define BOS_LOGGING_H

#include <vector>
#include <string>
#include <functional>
#include <chrono>
#include <ctime>

#include "iLogger.h"
#include "Severity.h"
#include "Colors.h"

namespace byteofsin::logging {
    //TODO Split into generic log file and header for extern
    struct Settings {
        
    };

    class Log {
        public:
            Log(){};
            ~Log(){};

            void AddLog(iLogger& newLog){
                std::reference_wrapper<iLogger> logWrapper = newLog;
                logs.push_back(logWrapper);
            }

            Log& operator << (Severity inputSeverity) {
                if(newLine){
                    BeginLine();
                }

                for(std::reference_wrapper<iLogger> log : logs){
                    //TODO: Add timestamp
                    if(this->displaySeverity){
                        log.get() << inputSeverity;
                    }
                }

                return *this;
            }

            Log& operator << (std::string const& message){
                if(newLine){
                    BeginLine();
                }

                for(std::reference_wrapper<iLogger> log : logs){
                    log.get() << message;
                }

                return *this;
            }

            Log& operator << (bytelog::EndLine endl){
                if(newLine){
                    BeginLine();
                }
                for(std::reference_wrapper<iLogger> log : logs){
                    log.get() << endl;
                    this->newLine = true;
                }

                return *this;
            }

            Log& operator << (bytelog::Flush flush){
                if(newLine){
                    BeginLine();
                }
                for(std::reference_wrapper<iLogger> log : logs){
                    log.get() << flush;
                }

                return *this;
            }

            /*	Settings
             =========================*/
            /*	Severity
             --------------------*/
            void ToggleSeverity(){
                this->displaySeverity = !this->displaySeverity;
            }

            /*	Tabs
             --------------------*/
            void ToggleTabs(){
                this->displayTabs = !this->displayTabs;
            }

            void IncreaseTabs(){
                this->currentTab += 1;
            }

            void DecreaseTabs(){
                this->currentTab -= 1;

                if(this->currentTab < 0){
                    this->currentTab = 0;
                }
            }

            void SetTabs(int newTabs){
                this->currentTab = newTabs;
            }

            int GetTabs(){
                return this->currentTab;
            }

            void SetTabString(std::string newTabString){
                this->tabString = newTabString;
            }

            /*	Timestamp
             --------------------*/
            void ToggleTimestamp(){
                this->displayTimestamp = !this->displayTimestamp;
            }


        private:
            std::vector <std::reference_wrapper<iLogger>> logs;

            bool newLine = true;

            bool displayTabs = false;
            bool displayTimestamp = false;
            bool displaySeverity = false;

            int currentTab = 0;
            std::string tabString = "\t";


            std::string GetTabString(){
                std::string tabCount = "";

                for(int i = 0; i < this->currentTab; i++){
                    tabCount += this->tabString;
                }

                return tabCount;
            }

            void PrintTabs(){
                for(std::reference_wrapper<iLogger> log : logs){
                    log.get() << GetTabString();
                }
            }

            void BeginLine(){
                this->newLine = false;
                
                for(std::reference_wrapper<iLogger> log : logs){
                    if(this->displayTabs){
                        PrintTabs();
                    }
                }
            }
    };
};

extern byteofsin::logging::Log Bytelog;
#define Severity byteofsin::logging::Severity
#define endLine byteofsin::logging::endl


#define TabBlockStart Bytelog.IncreaseTabs();
#define TabBlockEnd Bytelog.DecreaseTabs();

#endif