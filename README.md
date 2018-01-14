# Killnect

Killnect is an **academic project** lead during the lectures of **AR and VR applications** in [Efrei Paris](http://www.efrei.fr), a french school of engineers.

It is built over the [VRPN](http://vrpn.org) library.

## Structure of the project

Killnect is mostly a library to manage a Kinect skeleton served by a [FAAST](http://projects.ict.usc.edu/mxr/faast/) server. Also, it provides tools to detect parts of the skeleton in space and action performed by the user.

On this Git project, you can found two samples of use of this academic project:

- [Paint](/rigma/killnect/tree/paint), an example of interaction with another application installed on a computer
- [SFML](/rigma/killnect/tree/sfml), an example of how Killnect can be used with other libraries

## Paint (aka Pain)

This example of application is accessible [here](/rigma/killnect/tree/paint). Or by typing `git checkout paint` in your git terminal.

To use it, just launch your FAAST server and connect it with your Kinect. Then, start the application using the [Visual Studio](http://www.visualstudio.com/vs) Project.

The interactions will be the following ones:

- Your right hand will be the mouse
- Raise your left hand above your left shoulder to press down the virtual left button of your mouse
- Lower yout left hand under your left shoulder to release the virtual left button of your mouse
- Clap your hand to open Microsoft Paint
- Lower quickly your hand to the bottom to close Paint

## SFML (aka Is your arm up?)

This example of application is accessible [here](/rigma/killnect/tree/sfml). Or by typing `git checkout sfml` in your git terminal.

To use it, just launch your FAAST server and connect it with your Kinect. Then, start the application using the [Visual Studio](http://www.visualstudio.com/vs) Project.

The interactions will be the following ones:

- The visual indicator will be green while no skeleton is detected yet
- The indicator will be blue when no arm is raised
- The indicator will be red when at least one arm is raised
