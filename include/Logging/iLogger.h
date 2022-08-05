#pragma once
#include "Severity.h"
#include <string>
#include <map>

namespace byteofsin::logging {
    struct EndLine {};
    struct Flush{};

    const EndLine endl;
    const Flush flush;

    namespace bytelog = byteofsin::logging;
    
    class iLogger {
        public:
            virtual ~iLogger() = default;
            //virtual void SetSeverity(Severity severity);

            // Filtering
            //virtual Severity filter() const = 0;
            //virtual void SetFilter(Severity severity) = 0;   
            // void ToggleFilter(Severity severity){
                
            // }

            // Access
            virtual iLogger& operator << (severity inputSeverity) = 0;
            virtual iLogger& operator << (std::string const& message) = 0;
            // virtual iLogger& operator << () = 0; make work with text stream/abstract string

            // iLogger& operator << (std::string const& message) {
            //     return (*this) << std::string{message};
            // }


            // Formatiing
            virtual iLogger& operator << (bytelog::EndLine) = 0;
            virtual iLogger& operator << (bytelog::Flush) = 0;
        protected:
            //std::map<Severity, bool> filters;
        
    };  
};