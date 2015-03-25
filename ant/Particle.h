#ifndef ANT_PARTICLE_H
#define ANT_PARTICLE_H

#include "base/types.h"
#include "ParticleType.h"
#include "Track.h"

#include "TLorentzVector.h"
#include <list>
#include <ostream>
#include "base/printable.h"

namespace ant {

/**
 * @brief Base particle class
 */
class Particle: public TLorentzVector, public printable_traits {
public:
    typedef std::list<const Particle*> ParticleList_t;

protected:
    const ant::ParticleTypeDatabase::Type* type;
    const Particle* parent;
    ParticleList_t daughters;

public:

    Particle(const ant::ParticleTypeDatabase::Type& _type, ant::mev_t _Ek, ant::radian_t _theta, ant::radian_t _phi);

    Particle(const ParticleTypeDatabase::Type &_type, const TLorentzVector &_lorentzvector):
        TLorentzVector(_lorentzvector),
        type(&_type)
    {}

    virtual ~Particle() {}

    mev_t Ek() const { return E() - type->Mass(); }


    const ParticleTypeDatabase::Type& Type() const { return *type; }
    void ChangeType(const ParticleTypeDatabase::Type& newtype );

    void SetLorentzVector( const TLorentzVector& lv ) { *((TLorentzVector*)this) = lv; }


    const Particle* Partent()           const { return parent; }
    const ParticleList_t& Daughters()   const { return daughters; }

    bool hasParent() const { return parent != nullptr; }
    bool hasDaughters() const { return daughters.size() != 0; }

    void SetParent(const Particle* particle) { parent = particle; }
    void AddDaughter(const Particle* particle) { daughters.push_back(particle); }

    virtual std::ostream& Print(std::ostream& stream) const;

};


/**
 * @brief Particle class for Monte Carlo true data
 *
 * This is the same as Particle for the moment. Can be extended as needed.
 */
class MCParticle: public Particle {
protected:
    bool isfinalstate;

public:
    MCParticle(const ant::ParticleTypeDatabase::Type& _type, ant::mev_t _Ek, ant::radian_t _theta, ant::radian_t _phi, bool finalstate=true):
        Particle(_type, _Ek, _theta, _phi ), isfinalstate(finalstate)
    {}

    MCParticle(const ParticleTypeDatabase::Type& _type, const TLorentzVector& _lorentzvector, bool finalstate=true):
        Particle(_type, _lorentzvector),isfinalstate(finalstate)
    {}

    virtual ~MCParticle() {}

    virtual std::ostream& Print(std::ostream& stream) const;

    bool IsFinalState() const { return isfinalstate; }
};



/**
 * @brief Particle class for reconstructed particles.
 *
 * Stores additional track and detector inforamtion
 */

class RecParticle: public Particle {
protected:
    const ant::Track* track;

public:
    RecParticle(const ParticleTypeDatabase::Type& _type, const ant::Track* _track):
        Particle(_type, _track->ClusterEnergy(), _track->Theta(), _track->Phi()),
        track(_track)
    {}

    RecParticle(const ant::Particle& _particle, const ant::Track* _track):
        Particle(_particle),
        track(_track)
    {}

    const ant::Track* Track() const { return track; }

    virtual std::ostream& Print(std::ostream& stream) const;

};

}

#endif