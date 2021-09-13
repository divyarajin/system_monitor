#include <string>
#include <iomanip>
#include <cmath>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    int total_seconds = round(seconds);
    int total_mins = int(total_seconds / 60);
    int hh = int(total_mins / 60);
    int mm = int(total_mins - hh * 60);
    int ss = int(total_seconds - mm * 60 - hh * 60 * 60);

    std::ostringstream stream;
    stream << std::setw(2) << std::setfill('0') << std::to_string(hh) << ":" 
     << std::setw(2) << std::setfill('0') << std::to_string(mm) << ":"
     << std::setw(2) << std::setfill('0') << std::to_string(ss);
    return stream.str(); 
    }