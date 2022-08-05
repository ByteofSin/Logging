#pragma once
namespace byteofsin::logging {
    #define stringify (name) # name


    enum class severity {
        Debug           = 0,
        Info            = 1,
        Warning         = 2,
        Critical        = 3,
        Fatal           = 4,
    };

    constexpr const char* SeverityToString(severity givenSeverity){
        switch(givenSeverity){
            case severity::Debug: return "Debug(0): ";
            case severity::Info: return "Info(1): ";
            case severity::Warning: return "Warning(2): ";
            case severity::Critical: return "Critical(3): ";
            case severity::Fatal: return "Fatal(4): ";
            default: return "Severity Not Given (-1): ";
        };
    };
};