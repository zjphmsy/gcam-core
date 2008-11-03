#ifndef _NEWTON_RAPHSON_H_
#define _NEWTON_RAPHSON_H_
#if defined(_MSC_VER)
#pragma once
#endif

/*
 * LEGAL NOTICE
 * This computer software was prepared by Battelle Memorial Institute,
 * hereinafter the Contractor, under Contract No. DE-AC05-76RL0 1830
 * with the Department of Energy (DOE). NEITHER THE GOVERNMENT NOR THE
 * CONTRACTOR MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY
 * LIABILITY FOR THE USE OF THIS SOFTWARE. This notice including this
 * sentence must appear on any copies of this computer software.
 * 
 * EXPORT CONTROL
 * User agrees that the Software will not be shipped, transferred or
 * exported into any country or used in any manner prohibited by the
 * United States Export Administration Act or any other applicable
 * export laws, restrictions or regulations (collectively the "Export Laws").
 * Export of the Software may require some form of license or other
 * authority from the U.S. Government, and failure to obtain such
 * export control license may result in criminal liability under
 * U.S. laws. In addition, if the Software is identified as export controlled
 * items under the Export Laws, User represents and warrants that User
 * is not a citizen, or otherwise located within, an embargoed nation
 * (including without limitation Iran, Syria, Sudan, Cuba, and North Korea)
 *     and that User is not otherwise prohibited
 * under the Export Laws from receiving the Software.
 * 
 * All rights to use the Software are granted on condition that such
 * rights are forfeited if User fails to comply with the terms of
 * this Agreement.
 * 
 * User agrees to identify, defend and hold harmless BATTELLE,
 * its officers, agents and employees from all liability involving
 * the violation of such Export Laws, either directly or indirectly,
 * by User.
 */


/*! 
* \file log_newton_raphson.h
* \ingroup objects
* \brief This is the header file for the LogNewtonRaphson solver component class.
*
* \author Josh Lurz
*/
#include <string>
#include <boost/numeric/ublas/matrix.hpp> 

typedef boost::numeric::ublas::matrix<double> Matrix;

class CalcCounter; 
class Marketplace;
class World;
class SolverInfoSet;

/*! 
* \ingroup Objects
* \brief A SolverComponent based on the Newton-Raphson algorithm using logarithmic values. 
* \author Josh Lurz
*/

class LogNewtonRaphson: public SolverComponent {
public:
    LogNewtonRaphson( Marketplace* aMarketplace, World* aWorld, CalcCounter* aCalcCount, double aDeltaPrice );
    virtual ~LogNewtonRaphson(){};
    virtual void init();
    static const std::string& getNameStatic();
    ReturnCode solve( const double solutionTolerance, const double edSolutionFloor,
                      const unsigned int maxIterations, SolverInfoSet& solverSet, const int period );
    
protected:
    virtual const std::string& getName() const;
    virtual ReturnCode calculateDerivatives( SolverInfoSet& solverSet, Matrix& JFSM, Matrix& JFDM, Matrix& JF, int period );

    double mDeltaPrice; //!< The amount to adjust prices by when calculation derivatives.
};

#endif // _NEWTON_RAPHSON_H_