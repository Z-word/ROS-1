cmake_minimum_required(VERSION 2.8.3)
project(learning_topic)
#添加需要的依赖库 roscpp
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs geometry_msgs turtlesim #增加message_generation，自定义消息编译时需要依赖message_generation
message_generation)

#添加自定义的msg文件，意味着编译msg目录下的Person.msg文件   注意，msg文件在msg文件夹下，直接写这个add_message_files会报错，应该在FILES前加DIRECTORY msg
add_message_files(
  DIRECTORY msg
  FILES
  Person.msg
)

#注释放开，不需要修改。意味着如果要编译Person.msg 要依赖于std_msgs  #要在catkin_package前,add_message_files后
generate_messages(
  DEPENDENCIES
  std_msgs
)

#catkin_package()
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES pub_sub
 CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
#  DEPENDS system_lib
)

include_directories(
${catkin_INCLUDE_DIRS}
)
#声明想要的可执行文件的文件名，以及所需要的源列表，如果有多个源列表，空格列在此处
add_executable(main src/main.cpp)
add_executable(sub src/sub.cpp)

add_executable(msg_pub src/Person_publisher.cpp)
add_executable(msg_sub src/Person_subscriber.cpp)

#这儿是为了避免先编译cpp文件时，cpp文件中使用了自定义的消息类型还未编译。导致编译失败
add_dependencies(msg_pub ${PROJECT_NAME}_generate_messages_cpp)
add_dependencies(msg_sub ${PROJECT_NAME}_generate_messages_cpp)

#添加自定义的msg文件，意味着编译msg目录下的Person.msg文件   注意，msg文件在msg文件夹下，直接写这个add_message_files会报错，应该在FILES前加DIRECTORY msg
#add_message_files(
#  DIRECTORY msg
#  FILES
#  Person.msg
#)

#注释放开，不需要修改。意味着如果要编译Person.msg 要依赖于std_msgs  #要在catkin_package前
#generate_messages(
#  DEPENDENCIES
#  std_msgs
#)

#catkin_package()

#运行时依赖message_runtime
#catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES pub_sub
# CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
#  DEPENDS system_lib
#)

#告诉Cmake当链接此可执行文件时需要链接哪些库
target_link_libraries(main ${catkin_LIBRARIES})
target_link_libraries(sub ${catkin_LIBRARIES})

target_link_libraries(msg_pub
  ${catkin_LIBRARIES}
)
 
target_link_libraries(msg_sub
  ${catkin_LIBRARIES}
)

