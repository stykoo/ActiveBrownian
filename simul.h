/*
Copyright (C) Sorbonne Université (2018)
Contributor: Alexis Poncet <aponcet@lptmc.jussieu.fr>

This file is part of ActiveBrownian.

ActiveBrownian is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ForceInCrystal is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ForceInCrystal.  If not, see <http://www.gnu.org/licenses/>.
*/
/*!
 * \file simul.h
 * \author Alexis Poncet <aponcet@lptmc.jussieu.fr>
 * \brief Simulation of the system
 *
 * Header file for simul.cpp. It defines the class Simul.
 */

#ifndef ACTIVEBROWNIAN_SIMUL_H_
#define ACTIVEBROWNIAN_SIMUL_H_

#include <string>
#include <iostream>
// #include "state.h"

//! State of the simulation after initialization
enum SimulInitStatus {
	SIMUL_INIT_SUCCESS, //!< Successful initialization
	SIMUL_INIT_HELP, //!< Display help
	SIMUL_INIT_FAILED //!< Failed initialization
};

/*!
 * \brief Class for simulation
 *
 * This class takes care of both the initialization
 * and the time evolution of the system.
 */
class Simul {
	public:
		Simul(int argc, char **argv); //!< Constructor from arguments
		void run(); //!< Run the simulation
		void print() const; //!< Print the parameters

		//! Get initialization status
		SimulInitStatus getStatus() const { return status; }

	private:
		double rho; //!< Density
		long n_parts; //!< Number of particles
		double pot_strength; //!< Strength of interparticle potential
		double temperature; //!< Temperature
		double activity; //!< Activity
		double dt; //!< Timestep
		long n_iters; //!w Number of time iterations
		int sleep; //!< Number of milliseconds to sleep for between iterations
		double len; //!< Length of the box

		SimulInitStatus status; //!< Status after initialization
};

/*!
 * \brief Check if variable is positive or null.
 *
 * Returns true and prints an error message if the variable
 * is not positive.
 *
 * \param a Variable
 * \param name Name of variable
 * \return false if the variable is positive, true otherwise
 */
template<typename T>
bool notPositive(const T &a, std::string name) {
	if (a < T(0)) {
		std::cerr << "Error: " << name << " should be positive."
		          << std::endl;
		return true;
	}
	return false;
}

/*!
 * \brief Check if variable is strictly positive.
 *
 * Returns true and prints an error message if the variable
 * is not positive or is null.
 *
 * \param a Variable
 * \param name Name of variable
 * \return false if the variable is strictly positive, true otherwise
 */
template<typename T>
bool notStrPositive(const T &a, std::string name) {
	if (a <= T(0)) {
		std::cerr << "Error: " << name << " should be strictly positive."
		          << std::endl;
		return true;
	}
	return false;
}

#endif // ACTIVEBROWNIAN_SIMUL_H_
