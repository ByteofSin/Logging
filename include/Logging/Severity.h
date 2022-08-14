#pragma once
namespace byteofsin::logging {
    #define stringify (name) # name


    enum class Severity {
        Debug           = 0,
        Info            = 1,
        Warning         = 2,
        Critical        = 3,
        Fatal           = 4,
    };

    constexpr const char* SeverityToString(Severity givenSeverity){
        switch(givenSeverity){
            case Severity::Debug: return "Debug(0): ";
            case Severity::Info: return "Info(1): ";
            case Severity::Warning: return "Warning(2): ";
            case Severity::Critical: return "Critical(3): ";
            case Severity::Fatal: return "Fatal(4): ";
            default: return "Severity Not Given (-1): ";
        };
    };
};