
#include "headers/interface.h"

int main(){

	/*Variable initialisation*/
	KB* kb = createEmptyKB();
    FB* fb = createEmptyFB();
    FB* PPool = createEmptyFB(); 
	int quit = 0;
	char* tempPInput;
	char* tempRInput;

	
	/*Main menu*/
	while (quit == 0){
		printmenu();
		int UserInput = 0;
		scanf("%d",&UserInput);
		switch(UserInput){
			case 1 :
				clrscr();
				tempRInput = GetRuleIDInput(); //geting user input
				while(GetRule(kb,tempRInput) != NULL){ //Checking if the rule already exist
					printf("This rule allready exist please choose another name\n");
					tempRInput = GetRuleIDInput();
				}
				UseraddRule(kb,tempRInput); // adding rule to the KB
				printf("New rule created : %s \n",tempRInput);
				printKnowledgeBase(kb);
				break;
			case 2 :
				clrscr();
				tempPInput = GetRulePropositionId();
				while(GetProposition(PPool,tempPInput)){ //Checking if the proposition already exit
					printf("This Proposition allready exist please choose another id\n");
					tempPInput = GetRulePropositionId();
				}
				UseraddProposition(PPool,tempPInput); // adding the Proposition to the Pool
				printf("New Proposition created  : %s \n",tempPInput);
				//newprop
				break;
			case 3 :
				clrscr();
			 	//ruleprem
			 	break;
			case 4 :
				//ruleconclu
				break;
			case 5 :
				//make true
				break;
			case 6 :
				quit = 1;
				break;	
			default:
				printf("Please enter a number between 1 and 6\n");
		}
	}
    printFactBase(fb);
    //printPtrue(fb);

    return EXIT_SUCCESS;
}
