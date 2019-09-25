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

class District_PMC : public vle::devs::Dynamics
{
public:
    District_PMC(const vle::devs::DynamicsInit& init,
           const vle::devs::InitEventList& events)
      : vle::devs::Dynamics(init, events)
    {
    }

    ~District_PMC() override = default;

    vle::devs::Time init(vle::devs::Time /*time*/) override
    {
        return vle::devs::infinity;
    }

    void output(vle::devs::Time /*time*/,
                vle::devs::ExternalEventList& /*output*/) const override
    {
        // Example:
        // output.emplace_back("out");
        // output.back().addDouble(0.001);
    }

    vle::devs::Time timeAdvance() const override
    {
        return vle::devs::infinity;
    }

    void internalTransition(vle::devs::Time /*time*/) override
    {
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
        // Example:
        // return vle::Double::create(123.321);
        return 0;
    }

    void finish()
    {
    }
};

} // namespace example

DECLARE_DYNAMICS(POHMVietnam::District_PMC)
