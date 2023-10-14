参考我的截图

还有一点但不常用

#添加自定义的msg文件，意味着编译msg目录下的Person.msg文件   注意，msg文件在msg文件夹下，直接写这个add_message_files会报错，应该在FILES前加DIRECTORY msg
add_message_files(
  DIRECTORY msg
  FILES
  Person.msg
)
添加DIRECTORY msg(这是你所自定义的那个文件方的文件夹)在 FILES前，一般不用
