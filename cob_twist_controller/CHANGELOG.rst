^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package cob_twist_controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.6.10 (2015-08-31)
-------------------

0.6.9 (2015-08-25)
------------------
* authors in package xml
* Corrections integrated from PR: [WIP] Finalizing/Testing of TwistController features (`#51 <https://github.com/ipa-fxm/cob_control/issues/51>`_). Renaming from frame_to_collision to link_to_collision.
* - Fixed bug in constraint implementation: sign was "-" but must be "+".
  - Moved scripts.
* - Added more text to package.xml
  - Moved scripts to subfolder test.
* Added new script for raw3-1.
* In config file avoided setting of 0 tolerance (DIV/0!). Removed additional output.
* - Made some changes for test. - Decreased Duration time for markers. - Corrected pose update for self collision check frames. - Added new scripts.
* Added comment to activation buffer.
* boost revision
* Merge branch 'test_of_feature' into test_of_feature_with_adapt_frame_tracker
* Overwritten numerical_filtering with false.
* Some preparations for test: IMarker smaller, Alpha settings, More scripts. Default value for Frame Tracker params.
* - Added parameters for activation buffer and critical threshold of CA and JLA constraints.
  - Removed method getActivationThreshold because parameter can be used directly.
  - Packed thresholds into struct.
  - Commented some outputs.
* - CA: Increased exp. decay from 0.1 to 0.2 - Added comments. - Moved constraints set and management to base class. - Added time delta to test script.
* - Removed parameter mu. - Added obstacle id for identification of collision pair in ObstacleDistance.msg. - Added Frametracking to DataCollector. - Restructured obstacle distance data collecting. - In debug trajectory marker added explicit usage of frame_tracker/tracking_frame.
* merge
* explicit dependency to boost
* Fixed bug when obstacles move away from robot. Clear distances list when new distances arrive (also in case nothing is available for current link) to avoid no movement.
* - Renaming obstacle_marker_server for interactive obstacle
  - Now publishing all obstacle distances instead of the minimal distance only. Defined a MIN_DISTANCE for selection of data to publish (e.g. > than 0.5 m doesn't make sense for CA).
  - Selection of the minimal distance in debug node.
  - Callback data mediator processes all obstacles for a frame of interest id now.
  - Restructured methods in constraint classes.
  - In CA constraint now processing all collision pairs for one link in a CollisionAvoidance instance.
  - Removed unnecessary output.
* Resolved merge conflicts.
* more fixes for migration afer merge
* merge with package_xml_2
* remove trailing whitespaces
* migrate to package format 2
* - Removed unnecessary commented code.
* - Added handling of no exception: Save files.
* - Avoided drawing of self-collision frames -> can be done via rviz.
  - Increased CA activation threshold to 0.25 m
* Deleted unnecessary files.
* - Renamed dynamics_tasks_readjust_solver -> stack_of_tasks_solver. Therefore adapted corresponding cfg and data_types.
  - Created Python package for data collection.
* fix HardwareInterfacePosition
* consider PR review comments
* - Removed experiment solvers for task stacks. Now the dynamic_tasks_readjust_solver works better than them.
  - adapted MakeLists and config and data_types.
* - For BVH introduced a shared_ptr member -> so a collision object can be created without copying the whole BVH. This saves computation time (5% for 3 SCA and 1 torus)
  - Decreased rate for cob_obstacle_distance because the movement does not change that often.
  - According to the rate adapted the moving average for distance in constraint_ca_impl
* updates from ipa-fxm-mb
* Implemented Python package to set dyn_reconfigure params. Made test_move_around_torus use of this class.
* cleanup
* sort dependencies
* Created test, Removed commends, Removed output.
* Fixed bugs in cartesian_controller: waitFor last available transform else extrapolation error; send always a new constructed StampedTransform instead of using an already existent one, else end-effector is decoupled from manipulator and other confusing things happen...; Added responsible node to tf error msg.
* Merged with ipa-fxm/test_of_feature branch.
* Separated JLA and CA constraints from constraint_impl.h
* - Corrected JLA constraint. - Added weighting of GPM prio dependent. - Added buffer region for CA constraint to become active.
* Made movinge average generic for other data types. Using moving average for CA constraint.
* simplify simpson
* - Removed PredictDistance Service (not necessary anymore; found a lightweight computational algorithm).
  - Made KDL::ChainFkSolverVel_recursive in CA constraint available for prediction.
  - Replace constraints update method prediction variable with JntArrayVel.
  - Refactored ObstacleDistance.msg: Reduced number of members, renamings, added frame_of_interest for registration and made use of header->frame_id for arm_base_link.
  - Renamed service for registration.
  - Improved input twist damping in case of a constraint is in CRITICAL state.
* check for frame existence
* allow target_frame to be configured via private param, beautifying
* Further tests and adaptations for test.
* Added generated const from .cfg; Styling
* re-implementation of trajectory_publisher in c++
* Added Python package to collect data and write collected data into a file.
* Fixed parameter initialization.
* fix parameter initialization + add max_vel_base to cfg
* add topic name to ROS_WARN output
* add doxygen documentation
* add example launch file
* publish joint_states in separate thread
* adding JointStateInterface
* add base_marker to publisher
* generalize scripts, minor changes
* Corrected default values in cfg.
* Corrected CMakeLists.txt. Replaced ASSIMP_LIBRARIES with assimp.
* Added consideration of origin from URDF tags. Removed shape_type and so Registration.srv and replaced by SetString service. Removed comments.
* Considering visual tag as fallback now. Removed duplicate map and struct.
* Considered further proposals from https://github.com/ipa-fxm/cob_control/pull/7.
* Considered proposals from https://github.com/ipa-fxm/cob_control/pull/7
* Integrated comments of https://github.com/ipa-fxm/cob_control/pull/7. Replaced static link2collision map with URDF parser. Added class for URDF parser and create marker shapes.
* Added functions to represent a registered robot link as a mesh instead of simple shapes. Added a mapping between robot link name and mesh resource name.
* Integration. To avoid controller jump into critical region again introduced in cart vel damping.
* Fixed DIV/0 error in distance cost function calculation.
* Reassignment of corrected values to twist_controller_params\_ instance.
* Added JLA inequality constraint to be used within the dynamic task strategy. Added checking and resetting of dynamic_reconfigure params. Corrected formatting of LSV damping.
* Moved TaskStackController to parameters list. Added new damping factor for constraints (to avoid algo. singularities). Added new inverse for testing.
* Separated constraints from solvers and vice versa. Added new parameters. Prettified GUI.
* Added a Simple Python node to publish a line strip to see the real trajectory and the desired one.
* Made CA possible with active base. Bug fixing of solvers in case of base active. Corrected JLA constraints.
* more style unification
* parameter initialization
* enforceLimits now in inv_diff_kin_solver
* enum for KinematicExtension and styling for constants
* consider remarks from CodeReview: mainly styling and beautify
* hardware_interface_type renaming
* re-arrange Parameter structs
* Merge branch 'task_stack_prio_feature' of github.com:ipa-fxm-mb/cob_control into multi_feature_merge
* Added new method for dynamic tasks readjustment. Implemented prediction of distance now for vectors.
* resolve conflicts after merging ipa-fxm-mb/task_stack_prio_feature
* KinematicExtensionBaseActive works
* WIP: further cleanup and introduction of abstract helper class
* WIP: kinematic_extension replaces base_active
* Refactored task stack solvers. Fixed creation of solver instances. Removed unnecessary test code.
* beautify and code-review
* remove auto generatable doc
* merge with ipa320
* generic interface types
* Added chain recursive fk vel calculator. Corrected calculation of translational Jacobian for CA. Introduced further msg types to achieve that. Extended solvers: CA as first prio task, CA as GPM, CA as GPM with disappearing main tasks.
* Added task stack controller.
* Corrected dist calclation for GPM CA
* Added stack of tasks and Macijewski task prio CA.
* Added stack of tasks and further developments on GPM CA.
* Further developments.
* Implemented proposals from discussion https://github.com/ipa320/cob_control/pull/38. Removed tabs. Corrected node handles.
* Merge with IPA320 Indigo Dev.
* removed bug
* merged
* Added moving average filter and simpson integration formula
* New octave script to check whether split of vector v into separate tasks works.
* Removed rad variable.
* Fixed issue in WLN_JLA: Removed conversion to radian.
* Made code more CppStyleGuide ROS compliant.
* Made corrections proposed in https://github.com/ipa320/cob_control/pull/38#
* - Renaming: AugmentedSolver -> InverseDifferentialKinematicsSolver
  - Merged cob_twist_controller_data_types and augmented_solver_data_types -> cob_twist_controller_data_types
  - Renamings: According to ROS C++ Style Guide.
* - Added doxygen comments
  - Corrected the messages produced by catkin_lint
  - Created a static method to return SolverFactory
* - Made obstacle tracking independent from arm_right.
  - Refactored signatures of solve methods: Instead of using dynamic vector now a 6d vector is used because twists are of dim 6d.
  - Removed unnecessary comments.
  - Introduced eigen_conversions to have simple converters instead of filling matrices and vectors manually -> Reduces typing and copying errors!
* - Renamed some variables according to ROS C++ style guide
  - Moved advanced chain fk solver from cob_twist_controller to cob_obstacle_distance.
  - Replaced complicated transformation of base_link to arm_base_link with simpler and direct one.
  - Removed unnecessary services and replaced with message publisher and subscriber (for distance calculation).
  - Added example launch file for cob_obstacle_distance.
  - Corrected handling of objects of interest. Now in both packages frames are used (instead of joint names) -> made it similar to KDL and tf handlings.
  - Removed commented code.
  - Removed pointer where objects could be used directly (constraint params generation)
  - callback data mediator keeps old distance values until new ones were received. An iterator is used to go through the container.
* Added missing modules
* - Created a obstacle distance publisher in cob_obstacle_distance package and a subscriber in cob_twist_controller package.
  - Created registration service in cob_obstacle_distance
  - Creation of multiple CA constraints dependent on formerly registered joint regions.
* test
* Renaming
* Added collision avoidance feature. Solve with GPM. Made usage of cob_collision_object_publisher via ROS service.
* Added possibility to calculate self motion magnitude dependent from joint velocity limits.
* Removed tracking error publisher / subscriber and removed additional p gain for PD-Control (already done in FrameTracker with PID controller)
* Solved merge conflicts
* WIP:
  - Added new solver feature: GradientProjectionMethod.
  - Added cost function for: JLA, JLA_MID, CA
  - Added kappa parameter to set GPM scaling.
  - Added builder to support build of multiple constraints.
* Added new implementation for KDL::ChainFkSolverPos_recursive. Provides storage of joint positions.
* Beautify.
  Corresponding to PR https://github.com/ipa-fxm-mb/cob_control/pull/1.
* renamed parameters and functions
* Generischer Ansatz
* Low Isotropic Damping
* - Added constraints for JLA and JLA mid.
  - Added calculation for step size.
* - Prepared the implementation of a builder to create a set of constraints.
  - Decoupled constraints generation from solver class GPM (now they could be used for other methods as well).
  - Removed asParams from constraints. Only necessary for constraintParams.
* - Added a possibility to implement constraint functions.
  - Added a registration mechanism to the solver (registration in a priorized set).
  - Added a parameter to select it
* - Renamed pseudoinverse_calculation -> inverse_jacobian_calculation
* - Decoupled pseudoinverse calculation from constraint_solvers. That allows new implementations for pseudoinverse calculations. Additionally it allows to calculate pseudoinverses of further Jacobians (e.g. for constraints)
  - Removed unnecessary _base.cpp files and removed them from CMakeLists.txt.
* - Refactored parametrization of damping -> damping method is now given to solver for extensions (like numerical filtering)
  - Considered damping method NONE in case of no damping for solving IK.
* - Added a publisher for the tracking errors to send them to cob_twist_controller
  - Added a subscriber to collect the errors and put them to the solver.
  - Added a parameter to set the p gain. If 0.0 old behavior is active (default value).
* Contributors: ipa-fxm, ipa-fxm-cm, ipa-fxm-mb

* add missing include
* Contributors: ipa-fxm

* missing dependency
* Contributors: ipa-fxm

0.6.8 (2015-06-17)
------------------

0.6.7 (2015-06-17)
------------------
* reduce output in limiters
* restructure namespaces for parameters of cartesian controllers
* - Instead of creating png create eps.
* - Added new damping method None
  - Added enum value to select damping None
  - Removed pure pointer usage and added boost::shared_ptr usage (which provides pointer management / ensure deletion of objects)
  - Removed unused includes
  - Renamings
* - Removed unnecessary ROS_INFO_STREAMs
  - Removed temporary variables for test code
* - Added debug code
  - Removed truncation
  - Removed unused members
* - Grouped limiters in one .h and one .cpp
  - Grouped damping_methods in one .h and one .cpp
  - Removed separate factories. Made SolverFactory generic by introducing template parameters.
  - Made usage of boost::shared_ptr instead of own pointer handling.
  - Adapted CMakeLists.txt according to changes.
  - Split parameter enforce_limits into enforce_pos_limits and enforce_vel_limits
* - To enforce limits for joint positions and velocities created new classes.
  - Additionally added parameter for keeping direction or not when enforcing limits.
  - Therefore removed normalize_velocities and enforce_limits from cob_twist_controller. Instead the new limiter_container is used.
  - Added new struct to provide cob_twist_controller params.
  - Removed debug code.
* - Take care: W^(1/2) * q_dot = weighted_pinv_J * x_dot -> One must consider the weighting!!!
  - Added script to check pseudo-inverse calculation.
* - Take care: W^(1/2) * q_dot = weighted_pinv_J * x_dot -> One must consider the weighting!!!
  - Added an octave script to verify the statement above.
* - Removed unnecessary file
* - Added doxygen comments
  - Activated graphviz for doc generation
  - Added const to method signatures to avoid undesired JntArray-Data change.
* - moved enfore_limits from augmented_solver to cob_twist_controller
  - Added a base case WeightedLeastNorm to constraint solvers
  Instantiated it acts like an unconstraint solver.
  - Renamed JointLimitAvoidanceSolver to WLN_JointLimitAvoidanceSolver
  - WLN_JointLimitAvoidanceSolver inherits from WeightedLeastNormSolver and implements calculate_weighting
* - moved enfore_limits from augmented_solver to cob_twist_controller
  - Added a base case WeightedLeastNorm to constraint solvers
  Instantiated it acts like an unconstraint solver.
  - Renamed JointLimitAvoidanceSolver to WLN_JointLimitAvoidanceSolver
  - WLN_JointLimitAvoidanceSolver inherits from WeightedLeastNormSolver and implements calculate_weighting only. -> Solving is done by the WLN Solver.
* Added validation outputs.
  Added comments for doxygen generation.
  Did some renaming.
* Made restructured changes active.
  Corrected some implementation.
  Activated both old and new implementation for comparison and testing purposes.
* Made usages of ConstraintSolverFactoryBuilder:
  - Creates DampingMethod
  - Creates ConstraintSolver
  - Executes calculation of joint velocities.
* Split up augmented_solver.cpp into different constraint solvers: JLA constraints and unconstraint.
* - Restructured augmented_solver.
  - Renamed class augmented_solver to AugmentedSolver.
  - Created damping_methods as classes to ease creation of dampings (and new ones).
* add comments
* cleanup
* beautify CMakeLists
* using correct base topic names
* fix debug node
* remove obsolete code for parameter initialization, enforce_limits behaviour
* revision, simplification and cleanup
* remove obsolete files
* twist controller analyser
* last update
* update working frame_tracker
* base compensation test
* temporary adjust base topics
* reduce output
* twist series test script
* use component specific joint_states topic
* no output
* merge
* cleaning up
* new publisher and transformation names
* merge with cm
* added commentary, tolerance as dynamic reconfigure, modified enforce_limits
* Debug functions
* merge with cm
* Merge branch 'indigo_dev' of https://github.com/ipa320/cob_control into fm_cm_merged_new
* last commit before merging
* new rqt_features
* delete all test packages
* delete all test packages
* fixed errors from merging
* merged from ipa-fxm-cm
* beautify, added commentary, limit enforcing and dynamic reconfigure for JLA
* new debug twist
* add tracking_action
* test
* new features
* test
* Merge branch 'merge_fm_cm' of github.com:ipa-fxm-fm/cob_control into cm_dev
* changes
* Corrected errors from merging
* First merge attempt
* Joint Limit Avoidance added and cleaned up
* Added publisher for the pose
* Modified for the new structure
* cleaned up again
* Cleaned up
* New features
* a commit a day keeps the doctor away
* Contributors: Christian Ehrmann, ipa-fxm, ipa-fxm-cm, ipa-fxm-fm, ipa-fxm-mb

0.6.6 (2014-12-18)
------------------
* remove dep to cob_srvs and std_srvs
* Contributors: Florian Weisshardt

0.6.5 (2014-12-18)
------------------
* Merge branch 'indigo_dev' into indigo_release_candidate
* add dep
* Contributors: Florian Weisshardt

0.6.4 (2014-12-16)
------------------

0.6.3 (2014-12-16)
------------------
* add dependency to nav_msgs
* Contributors: Florian Weisshardt

0.6.2 (2014-12-15)
------------------
* Merge branch 'indigo_dev' into indigo_release_candidate
* fix twist_control dimensions for any-DoF
* merge with fxm-cm
* merge with fxm-fm
* cleaning up
* branch with features for merging
* topics according to new structure
* remove brics_actuator
* more topic renaming according to new structure
* renaming debug topic
* adapt namespaces for cartesian_controller to new structure
* dynamic reconfigure
* revision of cob_twist_controller
* merge_cm
* merge_fm
* temporary commit
* temporary commit
* changes in initialization
* restructure test_twist publisher scripts
* fix twist_controller to be usable without base again
* able to add base DoFs to Jacobian solver - first tests - needs more debugging
* null-space syncMM
* add test script for twist_stamped
* able to apply twists wrt to various coordinate system orientations
* cleanup, restructure and fix
* missing include
* merge with fxm-fm + clean up
* add twist publisher script
* add output publisher
* cleaning up
* beautify
* Add fixes provided by @ipa-fxm-fm
* fix controller and add damping
* add twist publisher script
* add output publisher
* Add fixes provided by @ipa-fxm-fm
* Contributors: Florian Weisshardt, ipa-fxm, ipa-fxm-cm, ipa-fxm-fm

0.6.1 (2014-09-22)
------------------

0.5.4 (2014-08-26)
------------------
* fix dependency-hell on multiple cores
* moved cob_twist_controller
* Contributors: Alexander Bubeck, ipa-fxm
