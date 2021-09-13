#include "process.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() {
  string line;
  long int value, utime, stime, cutime, cstime, starttime;
  std::ifstream stream(LinuxParser::kProcDirectory + std::to_string(pid_) +
                       LinuxParser::kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    for (int i = 0; i < 22; ++i) {
      linestream >> value;
      if (i == 13) {
        utime = value;
      }
      if (i == 14) {
        stime = value;
      }
      if (i == 15) {
        cutime = value;
      }
      if (i == 16) {
        cstime = value;
      }
      if (i == 21) {
        starttime = value;
      }
    }
    long int totaltime = utime + stime + cutime + cstime;
    long int seconds =
        LinuxParser::UpTime() - (starttime / sysconf(_SC_CLK_TCK));
    cpuUtilization_ = 100 * ((totaltime / sysconf(_SC_CLK_TCK)) / seconds);
  }
  return cpuUtilization_;
}

// TODO: Return the command that generated this process
string Process::Command() {
  command_ = LinuxParser::Command(Process::Pid());
  return command_;
}

// TODO: Return this process's memory utilization
string Process::Ram() {
  ram_ = LinuxParser::Ram(Process::Pid());
  return ram_;
}

// TODO: Return the user (name) that generated this process
string Process::User() {
  user_ = LinuxParser::User(Process::Pid());
  return user_;
}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() {
  upTime_ = LinuxParser::UpTime(Process::Pid());
  return upTime_;
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
  return cpuUtilization_ > a.cpuUtilization_;
}

Process::Process(int process_id) : pid_(process_id) {
  user_ = Process::User();
  command_ = Process::Command();
  cpuUtilization_ = 0.0;
  ram_ = Process::Ram();
  upTime_ = Process::UpTime();
}