/*
 * Particle.h
 *
 *  Created on: 10 Nov 2019
 *      Author: Pavel Smirnov
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace Methods {
struct Particle {
	double m_x;
	double m_y;
private:
	double m_speed;
	double m_direction;
private:
	void init();
public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};
} /* namespace Methods */
#endif /* PARTICLE_H_ */
