#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  void setPrevIdleTime(float idleTime);
  float getPrevIdleTime();
  void setPrevTotalTime(float totalTime);
  float getPrevTotalTime();

  // TODO: Declare any necessary private members
 private:
  float prevIdleTime = 0.0, prevTotalTime = 0.0;
};

#endif