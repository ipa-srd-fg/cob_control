/*!
 *****************************************************************
 * \file
 *
 * \note
 *   Copyright (c) 2014 \n
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
 * \date Date of creation: June, 2015
 *
 * \brief
 *   Methods implementation of the callback data mediator.
 *   Collects data from ROS callbacks and provides the data
 *   for constraint parameters.
 *
 ****************************************************************/
#include <ros/ros.h>

#include "cob_twist_controller/callback_data_mediator.h"

#include <eigen_conversions/eigen_msg.h>

/// Counts all currently available distances to obstacles.
uint32_t CallbackDataMediator::obstacleDistancesCnt()
{
    boost::mutex::scoped_lock lock(distances_to_obstacles_lock_);
    return this->obstacle_distances_.size();
}

/// Consumer: Consumes elements from distances container
bool CallbackDataMediator::fill(ConstraintParamsCA& params_ca)
{
    boost::mutex::scoped_lock lock(distances_to_obstacles_lock_);
    bool success = false;
    double last_min_distance = std::numeric_limits<double>::max();
    params_ca.current_distances_.clear();
    for(ObstacleDistancesIter_t it = this->obstacle_distances_.begin(); it != this->obstacle_distances_.end(); it++)
    {
        if(it->first == params_ca.id_) // select the appropriate distances for frame id of interest
        {
            params_ca.current_distances_ = it->second; // copy all distances for frame to current distances of param struct
            success = true;
        }
    }

    return success;
}

/// Can be used to fill parameters for joint limit avoidance.
bool CallbackDataMediator::fill(ConstraintParamsJLA& params_jla)
{
    return true;
}

/// Producer: Fills obstacle distances but only when they are empty
void CallbackDataMediator::distancesToObstaclesCallback(const cob_obstacle_distance::ObstacleDistances::ConstPtr& msg)
{
    boost::mutex::scoped_lock lock(distances_to_obstacles_lock_);
    this->obstacle_distances_.clear();
    for(cob_obstacle_distance::ObstacleDistances::_distances_type::const_iterator it = msg->distances.begin(); it != msg->distances.end(); it++)
    {
        ObstacleDistanceData d;
        d.min_distance = it->distance;
        tf::vectorMsgToEigen(it->frame_vector, d.frame_vector);
        tf::vectorMsgToEigen(it->nearest_point_frame_vector, d.nearest_point_frame_vector);
        tf::vectorMsgToEigen(it->nearest_point_obstacle_vector, d.nearest_point_obstacle_vector);
        this->obstacle_distances_[it->link_of_interest].push_back(d);
    }

}
