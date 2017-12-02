/**
 * @file MovementRecognition.hpp
 * @brief Movement recognition manager
 * @author Romain Failla
 * @version 1.2
 */

#ifndef MOVEMENT_RECOGNITION_HPP
#define MOVEMENT_RECOGNITION_HPP

#include <boost/signals2/signal.hpp>
#include <list>
#include <vector>

#include "Action.hpp"
#include "DetectionAction.hpp"
#include "DetectionBox.hpp"
#include "Box.hpp"
#include "Skeleton.hpp"

/**
 * @class MovementRecognition
 * @brief Manager for recognition of movements
 *
 * This class manages the dictionnary of known movements and detect them when it's asked
 */
class MovementRecognition {
public:
    /**
     * @brief Definition of the detection box callback
     */
    typedef boost::function<void(const std::string&, const std::vector<std::string>&, const Skeleton*)> DetectionCallback;

public:
    /**
     * @brief Constructor
     *
     * Instantiate a new movement recognition manager
     *
     * @param skeleton: the Skeleton instance where the manager performs recognition on
     */
    MovementRecognition(Skeleton *skeleton);

    /**
     * @brief Destructor
     *
     * Default destructor of the class
     */
    ~MovementRecognition();

public:
    /**
     * @brief Launch the recognition process
     *
     * Launch the recognition process of the manager and, if it's asked, refresh its working skeleton
     *
     * @param refreshSkeleton if true, the working skeleton is refreshed by the manager
     */
    void launchRecognition(bool refreshSkeleton = false);

public:
    /**
     * @brief Add a detection box to the manager
     *
     * Add a new detection box to the manager which will call a callback when some joints will be in the box
     *
     * @param name: the name of the detection box
     * @param joints: the name of the joint to detect
     * @param box: the configuration of the box in space
     * @param cb: the callback called when the joints will be in the box
     */
    void addDetectionBox(const std::string &name, const std::vector<std::string> &joints, const Box &box, DetectionCallback cb);
    
    /**
    * @brief Add a detection box to the manager
    *
    * Add a new detection box to the manager which will call a callback when some joints will be in the box
    *
    * @param name: the name of the detection box
    * @param joint: the name of the joint to detect
    * @param box: the configuration of the box in space
    * @param cb: the callback called when the joints will be in the box
    */
    void addDetectionBox(const std::string &name, const std::string &joint, const Box &box, DetectionCallback cb);
    
    /**
    * @brief Add a detection box to the manager
    *
    * Add a new detection box to the manager which will call a callback when some joints will be in the box
    *
    * @param name: the name of the detection box
    * @param joints: the name of the joint to detect
    * @param box: the configuration of the box in space
    * @param cb: the callback called when the joints will be in the box
    */
    void addDetectionBox(const char *name, const std::vector<const char*> &joints, const Box &box, DetectionCallback cb);
    
    /**
    * @brief Add a detection box to the manager
    *
    * Add a new detection box to the manager which will call a callback when some joints will be in the box
    *
    * @param name: the name of the detection box
    * @param joint: the name of the joint to detect
    * @param box: the configuration of the box in space
    * @param cb: the callback called when the joints will be in the box
    */
    void addDetectionBox(const char *name, const char *joint, const Box &box, DetectionCallback cb);

public:
    /**
     * @brief Add an action to the dictionnary to recognize
     *
     * Add a new action to the dictionnary which will be able to be recognized by the manager
     *
     * @param name: the name of the action
     * @param joints: the name of the joints which will perform the action
     * @param action: the configuration of the action
     * @param cb: the cllback callled when the action is recognized
     */
    void addAction(const std::string &name, const std::vector<std::string> &joints, const Action &action, DetectionCallback cb);
    
    /**
    * @brief Add an action to the dictionnary to recognize
    *
    * Add a new action to the dictionnary which will be able to be recognized by the manager
    *
    * @param name: the name of the action
    * @param joints: the name of the joints which will perform the action
    * @param action: the configuration of the action
    * @param cb: the cllback callled when the action is recognized
    */
    void addAction(const char *name, const std::vector<const char*> &joints, const Action &action, DetectionCallback cb);

private:
    std::list<DetectionBox> _detectionBoxes;
    std::list<DetectionAction> _actions;
    Skeleton *_skeleton;
};

#endif
