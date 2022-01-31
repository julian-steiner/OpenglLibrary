#pragma once

class Initializable {
protected:
  bool initialized = false;
  virtual void initialize() = 0;
  bool isInitialized() { return initialized; };
};