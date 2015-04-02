/*!
 *****************************************************************
 * \file
 *
 * \note
 *   Copyright (c) 2015 \n
 *   Fraunhofer Institute for Manufacturing Engineering
 *   and Automation (IPA) \n\n
 *
 *****************************************************************
 *
 * \note
 *   Project name: care-o-bot
 * \note
 *   ROS stack name: cob_control
 * \note
 *   ROS package name: cob_twist_controller
 *
 * \author
 *   Author: Marco Bezzon, email: Marco.Bezzon@ipa.fraunhofer.de
 *
 * \date Date of creation: March, 2015
 *
 * \brief
 *   This header contains the interface description to create solvers
 *
 ****************************************************************/
#ifndef SOLVER_FACTORY_H_
#define SOLVER_FACTORY_H_

#include <Eigen/Core>
#include <Eigen/SVD>
#include <kdl/jntarray.hpp>
#include "cob_twist_controller/constraint_solvers/solvers/constraint_solver_base.h"

class SolverFactory
{
    public:
        Eigen::MatrixXd calculateJointVelocities(AugmentedSolverParams &asSolverParams,
                                                 Matrix6Xd &jacobianData,
                                                 Eigen::Transpose<Matrix6Xd> &jacobianDataTransposed,
                                                 const Eigen::VectorXd &inCartVelocities,
                                                 const KDL::JntArray& q,
                                                 const KDL::JntArray& q_dot,
                                                 double dampingFactor);

        virtual ~SolverFactory() = 0;

    protected:
        virtual ConstraintSolver* createSolver(AugmentedSolverParams &asSolverParams,
                                               Matrix6Xd &jacobianData,
                                               Eigen::Transpose<Matrix6Xd> &jacobianDataTransposed) const = 0;

};

#endif /* SOLVER_FACTORY_H_ */
