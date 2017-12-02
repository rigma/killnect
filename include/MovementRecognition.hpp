/**
 * @file MovementRecognition.hpp
 * @brief Movement recognition manager
 * @author Romain Failla
 * @version 1.2
 */

#ifndef MOVEMENT_RECOGNITION_HPP
#define MOVEMENT_RECOGNITION_HPP

#include <boost/signals2/signal.hpp>
#include <map>
#include <vector>

#include "Action.hpp"
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

    /**
    * @struct DetectionBox
    * @brief Represents the configuration of a detection box
    */
    struct DetectionBox {
        boost::signals2::signal<void(const std::string&, const std::vector<std::string>&, const Skeleton*)> sig;
        std::vector<std::string> joints;
        Box box;
        bool active;
    };

    /**
    * @class DetectionAction
    * @brief Represents the configuration of a recognizable action
    */
    struct DetectionAction {
        boost::signals2::signal<void(const std::string&, const std::vector<std::string>&, const Skeleton*)> sig;
        std::vector<std::string> joints;
        Action action;
    };

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
    const DetectionBox &detectionBox(const std::string &name) const;
    const DetectionBox &detectionBox(const char *name) const;

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

public:
    const DetectionAction &action(const std::string &name) const;
    const DetectionAction &action(const char *name) const;

private:
    std::map<std::string, DetectionBox> _detectionBoxes;
    std::map<std::string, DetectionAction> _actions;
    Skeleton *_skeleton;
};

#endif
