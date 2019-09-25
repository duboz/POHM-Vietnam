/*
 * This file is part of VLE, a framework for multi-modeling, simulation
 * and analysis of complex dynamical systems
 * http://www.vle-project.org
 *
 * Copyright (c) 2018 INRA http://www.inra.fr
 *
 * See the AUTHORS or Authors.txt file for copyright owners and contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <vle/DifferentialEquation.hpp>
#include <iostream>

namespace POHMVietnam {

    using namespace vle::ode;

    class Seir :
        public DifferentialEquation
    {
    public:
        Seir(const vle::devs::DynamicsInit& model,
             const vle::devs::InitEventList& events) :
                 DifferentialEquation(model,events)
        {

            m = events.getDouble("m");// = 0.9
            v = events.getDouble("v"); //= 0.2
            c = events.getDouble("c"); // = 0.5
            g = events.getDouble("g");// = 0.0
            b = events.getDouble("b");

            S.init(this, "S", events);
            E.init(this, "E", events);
            I.init(this, "I", events);
            R.init(this, "R", events);
            C.init(this, "C", events);
            n = S()+I()+R();//+E()

        }
        virtual ~Seir(){}

        void compute(const vle::devs::Time& /*time*/)
        {
            n = S() + I() + R(); //+E()
            grad(S) =  m*(1.-v) - b*I()*S() -m*S() + (g+C()) * (1-v)*I();
            //beta*S()*I()/n - nu*S() - C()*S();
            //grad(E) =  beta*S()*I()/n - sigma*E() - C()*E();
            grad(I) = b*I()*S() - (C()+g)*I() - m*I();
            //sigma*E() - gamma * I() - C()*I();
            grad(R) = (C()+g)*v*I() -m*R() + m*v;
            //gamma*I()  + nu*S() + C() * (S()+E()+I());
            grad(E) = v * m * n + v * g * I() + (v + 1.) * C() * I(); 
            //std::cout << "C = " << C() << '\n';
        }

    private:
        //total population, should be constant
        double n;// = 11;
        double m;//beta;// = 0.9;
        //rate an infected recovers and moves into the resistant phase.
        double v;//gamma; //= 0.2,
        //rate at which an exposed person becomes infective.
        double c;//sigma; // = 0.5,
        //vaccination rate
        double g;//nu = 0.0)
        double b;

        Var S;//susceptible
        Var I;// infectious
        Var R;// recovered
        Var E;// effort
        Var C;// EXT !!!  Control
    };

} // namespace POHMVietnam

DECLARE_DYNAMICS(POHMVietnam::Seir)
