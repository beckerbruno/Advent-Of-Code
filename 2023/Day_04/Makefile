APPLICATIVO = App
CFLAGS = -c -std=c++11
DASHOES = ${APPLICATIVO}.o

all:			${APPLICATIVO}

${APPLICATIVO}:	${DASHOES}
	@g++ -o ${APPLICATIVO} ${DASHOES}

${APPLICATIVO}.o: 		${APPLICATIVO}.cpp
	g++ ${CFLAGS} ${APPLICATIVO}.cpp

run:			${APPLICATIVO}
	@./${APPLICATIVO}

clean: 			
	del ${DASHOES} ${APPLICATIVO}.exe