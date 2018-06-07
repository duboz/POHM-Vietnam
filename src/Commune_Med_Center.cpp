/*
 * This file is part of VLE, a framework for multi-modeling, simulation
 * and analysis of complex dynamical systems.
 * http://www.vle-project.org
 *
 * Copyright (c) 2003-2018 Gauthier Quesnel <quesnel@users.sourceforge.net>
 * Copyright (c) 2003-2018 ULCO http://www.univ-littoral.fr
 * Copyright (c) 2007-2018 INRA http://www.inra.fr
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

/*
 * @@tagdynamic@@
 * @@tagdepends:@@endtagdepends
 */

#include <vle/devs/Dynamics.hpp>
#include <vle/value/Value.hpp>
#include <iostream>

namespace POHMVietnam {

class Commune_Med_Center : public vle::devs::Dynamics
{
private:
    bool   isConsulted;
    int    nb_patients;
    double init_consult_duration;
    vle::devs::Time consultation_duration;

public:
    Commune_Med_Center(const vle::devs::DynamicsInit& init,
           const vle::devs::InitEventList& events)
      : vle::devs::Dynamics(init, events)
    {
        init_consult_duration = events.getDouble("consult duration");
    }

    ~Commune_Med_Center() override = default;

    //
    // Process the initialization of the model by initializing the initial
    // state and return the duration of the initial state.
    // Default, @c init function returns vle::devs::infinity
    //
    vle::devs::Time init(vle::devs::Time time) override
    {
        isConsulted = false;
        nb_patients = 0;
        return vle::devs::infinity;
    }

    //
    // Process the output function: add external event into the @c output.
    //
    void output(vle::devs::Time time,
                vle::devs::ExternalEventList& output) const override
    {
        output.emplace_back("inform");
        std::string s = "P" + std::to_string(nb_patients);
        output.back().addString(s);
        //vle::devs::Dynamics::output(time, output);
    }

    //
    // Compute the duration of the current state. As the @c init function, @c
    // timeAdvance function default returns vle::devs::infinity.
    //
    vle::devs::Time timeAdvance() const override
    {
        return consultation_duration;
        //vle::devs::Dynamics::timeAdvance();
    }

    //
    // Compute the new state of the model with the internal transition
    // function. Default function does nothing.
    //
    void internalTransition(vle::devs::Time time) override
    {
        nb_patients--;
        if (nb_patients == 0)
            consultation_duration = vle::devs::infinity;
        else
            consultation_duration = init_consult_duration;
        //vle::devs::Dynamics::internalTransition(time);
    }

    //
    // Compute the new state of the model when at least one external event
    // occurs. Default function does nothing.
    //
    void externalTransition(const vle::devs::ExternalEventList& events,
                            vle::devs::Time time) override
    {
        bool event_value = false;
        for (const auto& elem : events) {
             if (elem.getPortName() == "isConsulted" and
                 elem.attributes()->isBoolean()) {
                     event_value = elem.getBoolean().value();
             }
             else if (elem.getPortName() == "getResults"){
                 event_value = elem.getBoolean().value();
             }        
        }
        if (event_value){
             isConsulted = true;
             nb_patients++;
             consultation_duration = init_consult_duration;
        }
        //externalTransition(events, time);
    }

    //
    // Compute the new state of the model when both at least one external event
    // occurs and an internal event. Default function is to call internal
    // transition and external transition as follow:
    //
    void confluentTransitions(
      vle::devs::Time time,
      const vle::devs::ExternalEventList& events) override
    {
        //internalTransition(time);
        //externalTransition(events, time);
        confluentTransitions(time, events);
    }

    //
    // Compute the current state of the model at a specified time and for a
    // specified observation port.
    //
    std::unique_ptr<vle::value::Value> observation(
      const vle::devs::ObservationEvent& event) const override
    {
        return vle::value::Integer::create(nb_patients);
        //return vle::devs::Dynamics::observation(event);
    }

    //
    // When the simulation of the atomic model is finished, the finish method
    // is invoked. Default function does nothing.
    //
    void finish()
    {
        vle::devs::Dynamics::finish();
    }
};

} // namespace example

DECLARE_DYNAMICS(POHMVietnam::Commune_Med_Center)
