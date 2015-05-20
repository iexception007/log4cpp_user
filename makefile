# 可执行文件  
TARGET=Testor
# 指令编译器和选项  
CC=g++  
# CPP文件  
SRCS = main.cpp logger.cpp  
# 目标文件  
OBJS = $(SRCS:.cpp=.o)  

#INCLUDE =-I./include
# 库文件
LIBS     =-L/usr/local/lib -llog4cpp -lpthread 
# 指定运行时路径
RPATH    =-Wl,-rpath=/usr/local/lib 

$(TARGET):$(OBJS)  
#   @echo TARGET:$@  
#   @echo OBJECTS:$^  
#	$(CC) -o $@ $^ $(INCLUDE) $(INCLUDE) $(LIBS) $(RPATH)
	$(CC) -o $@ $^ $(INCLUDE) $(LIBS) $(RPATH)
%.o:%.cpp
	$(CC) -o $@ -c $< $(INCLUDE)

clean:  
	rm -rf $(TARGET) $(OBJS)  

