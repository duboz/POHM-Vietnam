/*
* @@tagdynamic@@
* @@tagdepends:@@endtagdepends
*/
#include <vle/value/Value.hpp>
#include <vle/devs/Dynamics.hpp>
#include<iostream>

namespace vd = vle::devs;
namespace vv = vle::value;

namespace POHMVietnam {
    
class Perturbation : public vd::Dynamics
{
 public:
  Perturbation(const vd::DynamicsInit& init,
                const vd::InitEventList& events)
        : vd::Dynamics(init, events)
  {
      control_delay    = events.getDouble("control delay");//14.;
      control_duration = events.getDouble("control duration");//10.;
      val_perturbation = events.getDouble("val perturbation");//1.2;
      detection_threshold = events.getDouble("detection threshold");
      I = 0.;
      time_next = vd::infinity;
      phase = IDLE;
  }

  virtual ~Perturbation()
  {
  }

  virtual vd::Time init(vle::devs::Time /*time*/) override
  {
    return 0.;
  }

  virtual void output(vle::devs::Time time,
                      vd::ExternalEventList& output) const override
  {
      vd::ExternalEvent ee = vd::ExternalEvent("C"); 
      switch(phase){
      case ACTIVE:
          {
            ee.addDouble(val_perturbation);    
            output.push_back(ee);
            //std::cout << "perturb " << val_perturbation << "  " << time << std::endl;
          }
          break;
      default:
          {
            ee.addDouble(0.0);
            output.push_back(ee);
            //std::cout << "stop perturb " << time << std::endl;
          }
     }
  }

  virtual vd::Time timeAdvance() const override
  {
     return time_next;
  }

  virtual void internalTransition(vle::devs::Time time) override
  {
      //if(phase == ACTIVE)
        //time_next = control_duration;
      //else
      //time_next = vd::infinity;
      //last_time = time;
      //phase = IDLE;
     switch(phase){
      case IDLE:
          {
            time_next = vd::infinity;
            //phase = ACTIVE;
          }
          break;
      case ACTIVE:
          {
              phase = CONTROL;
              last_time = time;
          }
          break;
      case CONTROL:
          phase = IDLE;
          time_next = vd::infinity;
    }
  }

  virtual void externalTransition(
            const vd::ExternalEventList& events,
            vle::devs::Time time) override
  {
    for (const auto& event : events) {
        if (event.onPort("I")) {
            I = event.getMap().getDouble("value");
            //std::cout << I << std::endl;
        }
    }
    switch (phase){
    case IDLE:
        if (I > detection_threshold){
            phase = ACTIVE;
            time_next = control_delay;
            last_time = time;
            //std::cout << I << '\t' << time << "ACTIVE"<<std::endl;
        }
        else
            time_next = vd::infinity;
        break;
    case ACTIVE:
        //if(time - last_time >= control_delay){
        //    time_next = 0;
        //    last_time = time;
        //    phase = CONTROL;
        //    std::cout << I << '\t' << time << "CONTROL"<<std::endl;
        //}
        //else{
            time_next = control_delay - (time - last_time);
            //std::cout << "time_next" << time_next << std::endl;
        //}
        break;
    case CONTROL:
        //if(time - last_time >= control_duration){
        //    time_next = 0;
        //    last_time = time;
        //    phase = IDLE;
        //    std::cout << I << '\t' << time << "IDLE"<<std::endl;
        //}
        //else{
            time_next = control_duration - (time - last_time);
            //std::cout << "time_next" << time_next << std::endl;
        //}

        //std::cout << I << std::endl;
    }
    //last_time = time;

    /*if (I > 0.2 and phase == IDLE){
        phase = ACTIVE;
        time_next = delay_intervention;
    }
    else if(phase == ACTIVE){
        phase = IDLE;
        time_next = 0;
        std::cout << I << '\t' << time << std::endl;
    }*/
    //time_next = 0.;
    //std::cout << I << '\t' << E << '\t' << I << '\t' << std::endl;
  }

  virtual void confluentTransitions(
            vle::devs::Time time,
            const vd::ExternalEventList& events) override
  {
      internalTransition(time);
      externalTransition(events, time);
  }
  virtual std::unique_ptr<vle::value::Value> observation(
            const vd::ObservationEvent& /*event*/) const override
  {
    return 0;
  }
  virtual void finish()
  {
  }

  private:
    enum PHASE {IDLE, ACTIVE, CONTROL};
    PHASE phase;
    vd::Time time_next;
    vd::Time last_time;
    double control_delay;
    double control_duration;
    double val_perturbation;
    double detection_threshold; 
    double I;
};
} // namespace POHMVietnam
DECLARE_DYNAMICS(POHMVietnam::Perturbation)
