#include<stdio.h>
#include<signal.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	char opt1[] = "pwd";
	char opt2[] = "clear";
	char opt3[] = "ls";
	char opt4[] = "exit";
	char opt5[] = "beliebig";

	while(1){
		printf("1. %s \n2. %s \n3. %s\n4. %s\n5. %s\n", opt1, opt2, opt3, opt4, opt5);

		int userInput;
		printf("Auswahl: ");
		scanf("%d", &userInput);
		//while(getchar() != '\n');
		if(userInput < 1 || userInput > 5){
			printf("Fehler: Die ausgewählt Option existiert nicht!\n");
			return 1;
		}else{
			if(userInput == 1){ printf("Es wurde %s gewaehlt\n", opt1); }else if (userInput == 2){ printf("Es wurde %s gewaehlt\n", opt2);}
			else if(userInput == 3){ printf("Es wurde %s gewaehlt\n", opt3);} else if(userInput == 4){ printf("Es wirde %s gewaehlt\n", opt4); }
			else if(userInput == 5){ printf("Es wurde %s gewaehlt\n", opt5);}
		}
		pid_t pid = fork();
		if(pid <= -1){
			perror("Fehler: fork()");
			exit(EXIT_FAILURE);
		}else if(pid > 0){
			int status;
			if(wait(&status) == pid && WIFEXITED(status)){
				printf("Beendet mit %d\n", pid);
				printf("\n");
			}if(userInput == 4){ break;}
		}else{
			if(userInput == 1){
				printf("My pid "); //<- Wird ignoriert?
				execlp("pwd","pwd",(char*) NULL);
				//perror("pwd");
				//exit(EXIT_FAILURE);
				printf("pwd fehlgeschlagen");
				return 1;

			}else if(userInput == 2){
				execlp("clear", "clear", (char*) NULL);
				//perror("pwd");
				//exit(EXIT_FAILURE);0
				printf("clear fehlgeschlagen");
				return 1;

			}else if(userInput == 3){
				execlp("ls", "ls", (char*) NULL);
				printf("ls fehlgeschlagen");
				return 1;

			}else if(userInput == 4){
				exit(20);

			}else if(userInput == 5){
				char befehl[5];
				printf("Befehl eingeben (max. laenge 5 char) : ");
				scanf("%5s", &befehl);
				//while(getchar() != '\n');
				execlp(befehl, befehl,(char*) NULL);
				printf("Befehl nicht gefunden\n");
				return 1;
			}
		}
	}
	return 0;
}

