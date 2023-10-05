all		:

00		:
		cc -Wall -Wextra -Werror 00_unix.c -o _unix 
		@echo -e
		@./_unix

01		:
		cc -Wall -Wextra -Werror 01_unix.c -o _unix 
		@echo -e
		@./_unix

02		:
		cc -Wall -Wextra -Werror 02_unix.c -o _unix 
		@echo -e
		@./_unix

03		:
		cc -Wall -Wextra -Werror 03_unix.c -o _unix 
		@echo -e
		@./_unix

04		:
		cc -Wall -Wextra -Werror 04_unix.c -o _unix 
		@echo -e
		@./_unix

05		:
		cc -Wall -Wextra 05_unix.c -o _unix 
		@echo -e
		@./_unix

06		:
		cc -Wall -Wextra -Werror 06_unix.c -o _unix 
		@echo -e
		@./_unix

07		:
		cc -Wall -Wextra -Werror 07_unix.c -o _unix 
		@echo -e
		@./_unix

08		:
		cc -Wall -Wextra -Werror 08_unix.c -o _unix 
		@echo -e
		@./_unix

09		:
		cc -Wall -Wextra -Werror 09_unix.c -o _unix 
		@echo -e
		@./_unix

10		:
		cc -Wall -Wextra -Werror 10_unix.c -o _unix 
		@echo -e
		@./_unix

11		:
		cc -Wall -Wextra -Werror 11_unix.c -o _unix 
		@echo -e
		@./_unix

12		:
		cc -Wall -Wextra -Werror 12_unix.c -o _unix 
		@echo -e
		@./_unix

13		:
		cc -Wall -Wextra -Werror 13_unix.c -o _unix 
		@echo -e
		@./_unix

14		:
		cc -Wall -Wextra -Werror 14_unix.c -o _unix 
		@echo -e
		@./_unix

15_1	:
		cc -Wall -Wextra -Werror 15_1_unix.c -o _unix 
		@echo -e
		@./_unix

15_2	:
		cc -Wall -Wextra -Werror 15_2_unix.c -o _unix 
		@echo -e
		@./_unix

16_1	:
		cc -Wall -Wextra -Werror 16_1_unix.c -o _unix 
		@echo -e
		@./_unix

16_2	:
		cc -Wall -Wextra -Werror 16_2_unix.c -o _unix 
		@echo -e
		@./_unix

17		:
		cc -Wall -Wextra -Werror 17_unix.c -o _unix 
		@echo -e
		@./_unix

18		:
		cc -Wall -Wextra -Werror 18_unix.c -o _unix 
		@echo -e
		@./_unix

19		:
		cc -Wall -Wextra -Werror 19_unix.c -o _unix 
		@echo -e
		@./_unix

20		:
		cc -Wall -Wextra -Werror 20_unix.c -o _unix 
		@echo -e
		@./_unix


fclean	:
		rm *unix

.PHONY	: all fclean
