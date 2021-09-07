# Adapter

- There are some times when the interface datatype may rely on other library and the library may be changed as the requirements changes or there is another updated version after code refractor.
- Hence, internal self-sustain module or code should not rely directly on the datatype provided by other library.
- That is the reason why in this design, all type of robots would rely on the common type (self-sustain) and the mapping / adapter is done at the robot_interface part.
- In other words, any renaming or conversion of datatype should be only done at the robot_interface side so that the code of each robot would remain unchanged and there is less chance to break the code of robot.