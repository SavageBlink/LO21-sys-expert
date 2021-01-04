
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
		
			case 1 : //Create a new rule and add it to the fact base
				clrscr();
				tempRInput = GetRuleIDInput(); //geting user input
				while(GetRule(kb,tempRInput) != NULL){ //Checking if the rule already exist
					printf("This rule allready exist please choose another name\n");
					tempRInput = GetRuleIDInput();
				}
				UseraddRule(kb,tempRInput); // adding rule to the KB
				clrscr();
				printf("New rule created : %s \n",tempRInput);
				printKnowledgeBase(kb);
				break;
				
			case 2 : //Create a prop and add it to the pool
				clrscr();
				tempPInput = GetRulePropositionId();
				while(GetProposition(PPool,tempPInput) != NULL){ //Checking if the proposition already exit
					printf("This Proposition allready exist please choose another id\n");
					tempPInput = GetRulePropositionId();
				}
				UseraddProposition(PPool,tempPInput); // adding the Proposition to the Pool
				clrscr();
				printf("New Proposition created  : %s \n",tempPInput);
				
				break;
				
			case 3 : //Add a props to a rule premisse
			
				clrscr();
				tempRInput = GetRuleIDInput(); //Getting the rule
				while(GetRule(kb,tempRInput) == NULL){
					printf("This rule must be in the Knowledge base please choose another name\n");
					tempRInput = GetRuleIDInput();
				}
				tempPInput = GetRulePropositionId();
				while(GetProposition(PPool,tempPInput) == NULL){ //Checking if the proposition already exit
					printf("This Proposition must exit to be added\n");
					tempPInput = GetRulePropositionId();
				}
				kb = UseraddPremisse(kb,PPool,tempRInput,tempPInput);
				clrscr();
				printf("%s has been added to the premisse of R1%s\n",tempPInput,tempRInput);
			 	
			 	break;
			 	
			case 4 : //Add a props to a rule conclusion
				clrscr();
				tempRInput = GetRuleIDInput(); //Getting the rule
				while(GetRule(kb,tempRInput) == NULL || GetRule(kb,tempRInput)->Conclusion != NULL ){
					printf("This rule must be in the Knowledge base and don't already have a conclusion\n");
					tempRInput = GetRuleIDInput();
				}
				tempPInput = GetRulePropositionId();
				while(GetProposition(PPool,tempPInput) == NULL){
					printf("This Proposition must exist to be added\n");
					tempPInput = GetRulePropositionId();
				}
				clrscr();
				kb = UseraddConclusion(kb,PPool,tempRInput,tempPInput);
				printf("%s is now the conclusion of %s\n",tempPInput,tempRInput);
				
				break;
				
			case 5 : //Make a prop true and add it to the fact base
				clrscr();
				tempPInput = GetRulePropositionId();
				while(GetProposition(PPool,tempPInput) == NULL){
					printf("this Proposition must exist to be added to the fact base\n");
					tempPInput = GetRuleIDInput();
				}
				clrscr();
				if(GetProposition(fb,tempPInput) != NULL){
					printf("%s is already in the fact base\n",tempPInput);
				}else{
					Proposition * P = GetProposition(PPool,tempPInput);
					P->value = true;
					addFact(fb,P);
					printf("%s was added to the fact base",tempPInput);
				}
				break;
			case 6: //Run the engine
				clrscr();
				printKnowledgeBase(kb);
				printf("Fact base before run engine \n");
				printFactBase(fb);
				printf("after\n");
    			RuNEnGiNe(kb,fb);
    			printFactBase(fb);
				break;
				
			case 7: //Print the existing proposition
				clrscr();
				printPool(PPool);
				break;
			case 8: //Print the Knowleage base
				clrscr(); 
				printKnowledgeBase(kb);
				break;
			case 9: //Print the Fact Base"
				clrscr();
				printFactBase(fb);
				break;
			case 10 : //Exit
				quit = 1;
				break;	
				
			default:
				clrscr();
				printf("Please enter a number between 1 and 6\n");
				UserInput = 0;
				break;
		}
	}

    return EXIT_SUCCESS;
}
