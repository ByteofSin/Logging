/** Title: Logging Enumerators
 *	@version: v0.0.0.1
 *	@author: ByteofSin
 *	Contacts: 
 *		Email: ByteofSin@gmail.com 
 *	Created: 09/03/2022 
 *	Modified: 09/03/2022
 *	@brief: A set of needed enumerators
 *	Externals: 
 *	@bug: none yet
 */

#ifndef BOS_LOGGING_ENUMS_H
#define BOS_LOGGING_ENUMS_H

#include <string>

namespace byteofsin::logging {
    struct EndLine{};
    struct Flush{};

    const EndLine endLine;
    const Flush flush;


    /** @brief Defines the settings for how the log will be implemented
     */
    struct Settings {
        /*	Settings
         =========================*/
        bool newLineFormatting = true;
        bool displayTabs = false;
        bool displayTimestamp = false;
        bool displaySeverity = false;
        bool printToConsole = true;
        bool printToFile = true;
        bool holdFileBuffer = true;

        /*	Variables to assist settings
         ===================================*/
        int tabs = 0;
        std::string tabOutput = "\t";

        enum TimestampFormat {
            DMY
        };
        std::string timestampSeperator = "/";
        TimestampFormat timestampFormat = TimestampFormat::DMY;

        //TODO Make vector or list for output files

        /*	Setting Manipulation
         =========================*/

        /*	Utility Functions
         =========================*/

        std::string FormatNewLine(){
            std::string output = "";

            if(newLineFormatting){
                if(displayTabs){
                    output += GetTabString();
                };

                if(displayTimestamp){

                };

                if(displaySeverity){

                }
            }

            return output;
        }

        std::string GetTabString(){
            std::string tabString = "";

            for(int i = 0 < i < tabs; i ++){
                tabString += tabOutput;
            }

            return tabString;
        }
    };
};


#endif