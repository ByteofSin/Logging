#pragma once
#include "iLogger.h"
#include "Severity.h"

#include <ostream>

namespace byteofsin::logging {
    template <typename CharT, typename Traits = std::char_traits<CharT>>
    class OutputStreamLogger : public iLogger {
        public:
            // OutputStreamLogger(/* std::basic_ostream<charType, streamTraits>& stream */) {

            OutputStreamLogger(std::basic_ostream<CharT, Traits> & outputStream) : Stream{outputStream} { 
            };

            iLogger& operator << (Severity inputSeverity) override { 
                Stream << SeverityToString(inputSeverity);
                return *this;
            }

            iLogger& operator << (std::string const& message) override {
                Stream << message;
                return *this;
            }

            iLogger& operator << (bytelog::EndLine) override {
                Stream << std::endl;
                return *this;
            }

            iLogger& operator << (bytelog::Flush) override {
                Stream << std::flush;
                return *this;
            }

        private:
            std::basic_ostream<CharT, Traits>& Stream;
    };
};

