#ifndef __BASE_CONTROLLER_H__
#define __BASE_CONTROLLER_H__

class BaseController {
public:
  virtual ~BaseController() {}

  //Called once at startup
  virtual void init() = 0;

  //Called each iteration in the main loop
  virtual void run() = 0;

  //Called by the interrupt handler
  virtual void update() = 0;
};

#endif //__BASE_CONTROLLER_H__
