# 可执行文件  
TARGET=./bin/Testor  
# 指令编译器和选项  
CC=g++  
# CPP文件  
SRCS = main.cpp logger.cpp  
# 目标文件  
OBJS = $(SRCS:.cpp=.o)  

INCLUDE = -I./include
LIBS = -llog4cpp -lpthread 
RPATH   = -Wl,-rpath=. 

$(TARGET):$(OBJS)  
#   @echo TARGET:$@  
#   @echo OBJECTS:$^  
	$(CC) -o $@ $^ $(INCLUDE) $(LIBS) $(RPATH)
%.o:%.cpp
	$(CC) -o $@ -c $< $(INCLUDE)

clean:  
	rm -rf $(TARGET) $(OBJS)  

