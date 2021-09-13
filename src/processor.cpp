#include "processor.h"

#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  std::vector<float> CPUUtilzationData = LinuxParser::CpuUtilization();
  float totalTime = CPUUtilzationData.at(0);
  float idleTime = CPUUtilzationData.at(1);
  float totalTimeDelta = totalTime - getPrevTotalTime();
  float idleTimeDelta = idleTime - getPrevIdleTime();
  setPrevTotalTime(totalTime);
  setPrevIdleTime(idleTime);
  return (totalTimeDelta - idleTimeDelta) / totalTimeDelta;
}

void Processor::setPrevTotalTime(float totalTime) { prevTotalTime = totalTime; }

void Processor::setPrevIdleTime(float idleTime) { prevIdleTime = idleTime; }

float Processor::getPrevTotalTime() { return prevTotalTime; }

float Processor::getPrevIdleTime() { return prevIdleTime; }