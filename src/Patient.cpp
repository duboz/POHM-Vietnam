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

class Patient : public vle::devs::Dynamics
{
private:
    enum PHASE {Sain, Sick};
    PHASE phase;

public:
    Patient(const vle::devs::DynamicsInit& init,
           const vle::devs::InitEventList& events)
      : vle::devs::Dynamics(init, events)
    {
    }

    ~Patient() override = default;

    vle::devs::Time init(vle::devs::Time) override
    {
        phase = Sain;
        return 0;//vle::devs::Dynamics::init(time);
    }

    void output(vle::devs::Time /*time*/,
                vle::devs::ExternalEventList& /*output*/) const override
    {
        //output.emplace_back("consult");
        //output.back().addBoolean(phase == Sick);
        //vle::devs::Dynamics::output(time, output);
    }

    vle::devs::Time timeAdvance() const override
    {
        return 5.0;//vle::devs::Dynamics::timeAdvance();
    }

    void internalTransition(vle::devs::Time /*time*/) override
    {
        if (phase == Sain)
                phase = Sick;
        else
           phase = Sain;
        //std::cout << "Time " << time << " " << phase << std::endl;
    }

    void externalTransition(const vle::devs::ExternalEventList& /*events*/,
                            vle::devs::Time /*time*/) override
    {
        // Example:
        // for (const auto& elem : events) {
        //     if (elem.attributes()->isDouble()) {
        //         //         double value = elem.getDouble().value();
        //     }
        // }
    }

    void confluentTransitions(
      vle::devs::Time time,
      const vle::devs::ExternalEventList& events) override
    {
        internalTransition(time);
        externalTransition(events, time);
    }

    std::unique_ptr<vle::value::Value> observation(
      const vle::devs::ObservationEvent& /*event*/) const override
    {
        return vle::value::Integer::create(phase);
    }

    void finish()
    {
    }
};

} // namespace POHMVietnam

DECLARE_DYNAMICS(POHMVietnam::Patient)
