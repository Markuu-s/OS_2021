## First task
Output is different because when create a new processes (child and parent) they are used free PID by order(if PID will be max value, PID will be cleared and will be 2 (because 0 is unused and 1 for init proccess reserved))
## Second task
Every child(and after parrent) procces create new child procces by help fork() and after that will be tree. After change of count of cycle tree will be bigger 

