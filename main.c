#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <winspool.h>

void time_Watch(int sec, int minute, int hour);
void stop_Watch(int sec, int minute, int hour);

int main(){
  int sec = 0, minute = 0, hour = 0;
  
  while (1) {
    int choice;

    system("cls");
    printf("~-Time Manager-~\n\n");
    printf("1. Timer Watch\n");
    printf("2. Stop Watch\n");
    printf("3. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 3){
      exit(0);
    }

    switch (choice) {
      case 1:
        time_Watch(sec, minute, hour);
        break;
      case 2:
        stop_Watch(sec, minute, hour);
        break;
    }
  }
  return 0;
}

void time_Watch(int sec, int minute, int hour){
  system("cls");
  printf("~-Timer-~\n\n");

  printf("Enter hour: ");
  scanf("%d", &hour);
  
  printf("Enter minute: ");
  scanf("%d", &minute);

  printf("Enter sec: ");
  scanf("%d", &sec);

  printf("<--Stop--> [s] | <--Reset--> [f] | <--Back--> [q] |\n");
  printf("-------------- | --------------- | -------------- |\n\n");

  while (1) {
    if (sec == 0) {
      if (minute == 0) {
        if (hour == 0) {
          printf("\nPrint any key to continue... ");
          _getch();
          break;  // countdown complete
        } 
        else {
          hour--;
          minute = 59;
          sec = 59;
        }
      } 
      else {
        minute--;
        sec = 59;
      }
    } 
    else {
      sec--;
    }

    printf("\r%02d:%02d:%02d ", hour, minute, sec);
    fflush(stdout);
    
    Sleep(1000);

    if(_kbhit()){
      char inpTM_I = _getch();

      //resumes the code
      if(inpTM_I == 's'){
        printf("\nThe time was: %02d:%02d:%02d\n\n", hour, minute, sec);
        printf("<--Resume--> [r] | <--Reset--> [f] | <--Back--> [q] |\n");
        printf("---------------- | --------------- | -------------- |\n\n");
        
        char inpTM_J = _getch();

        //resumes the time
        if(inpTM_J == 'r'){
          continue;
        }

        //resets the time
        else if (inpTM_J == 'f'){
          printf("\n");
          fflush(stdout);

          printf("Enter hour: ");
          scanf("%d", &hour);
  
          printf("Enter minute: ");
          scanf("%d", &minute);

          printf("Enter sec: ");
          scanf("%d", &sec);

          continue;
        }

        //breaks the loop and goes to main menu
        else if (inpTM_J == 'q') {
          break; 
        }
      }

      else if (inpTM_I == 'f') {
        printf("\n");
        fflush(stdout);
          
        printf("Enter hour: ");
        scanf("%d", &hour);
  
        printf("Enter minute: ");
        scanf("%d", &minute);

        printf("Enter sec: ");
        scanf("%d", &sec);

        continue;
      }
      
      //breaks the loop and goes to main menu
      else if (inpTM_I == 'q'){
        break;
      }

    }

  }

}

void stop_Watch(int sec, int minute, int hour){
  system("cls");
  printf("~-Stop Watch-~\n\n");
  printf("<--Stop--> [s] | <--Record--> [d] | <--Back--> [q] |\n");
  printf("-------------- | ---------------- | -------------- |\n\n");

  while (1) {
    sec++;
    if(sec == 60){
      sec = 0;
      minute++;

      if(minute == 60){
        minute = 0;
        hour++;
      }
    }
    
    printf("\r%02d:%02d:%02d ", hour, minute, sec);
    fflush(stdout);

    //printing after 1 second
    Sleep(1000);

    //input functionality
    if(_kbhit()){
      char inpSW_I = _getch();

      //stops the stopwatch
      if(inpSW_I == 's'){
        printf("\nThe time was: %02d:%02d:%02d\n\n", hour, minute, sec);
        printf("<--Resume--> [r] | <--Reset--> [f] | <--Back--> [q] |\n");
        printf("---------------- | --------------- | -------------- |\n\n");

        char inpSW_J = _getch();
        
        //resumes the timer
        if(inpSW_J == 'r'){
          continue;
        }
        
        //resets the time
        else if (inpSW_J == 'f') {
          sec = 0; minute = 0; hour = 0;
          continue;
        }

        //breaks the loop and goes to main menu
        else if (inpSW_J == 'q') {
          break;
        }
      }
      
      //records the time
      else if(inpSW_I == 'd'){
        printf("\nThe recorded: %02d:%02d:%02d\n\n", hour, minute, sec);
        continue;
      }

      //breaks the loop and goes to main menu
      else if (inpSW_I == 'q') {
        break;
      }
    }
  }
}
