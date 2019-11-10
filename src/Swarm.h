/*
 * Swarm.h
 *
 *  Created on: 10 Nov 2019
 *      Author: Pavel Smirnov
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace Methods {
class Swarm {
public:
	const static int NPARTICLES = 5000;
private:
	Particle * m_pParticles;
	int lastTime;
public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);
	const Particle * const getParticles() { return m_pParticles; };
};
} /* namespace Methods */
#endif /* SWARM_H_ */
