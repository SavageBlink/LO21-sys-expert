/**
 * @file engine.h
 * @author Guillaume/Hendercraft Driss/SavageBlink
 * @date 30 december 2020
 * @brief C file for the interface, manage prints and user input
 */

#include "headers/interface.h"

void printmenu(){
	printf("------------------------------------------- \n");
	printf("Main menu :\n");
	printf("1 - Create a new rule\n");
	printf("2 - Create a new proposition\n");
	printf("3 - Add a proposition to a rule's premisse\n");
	printf("4 - Add a proposition to a rule's conclusion\n");
	printf("5 - Make a proposition ture and add it to the FactBase\n");
	printf("6 - Run the inference engine\n");
	printf("7 - EXIT\n");
	printf("------------------------------------------- \n");
	return;
}

void printRule(Rule * R){
	if (R == NULL){
		fprintf(stderr,"The pointer given for printRule is NULL \n");
		return;
	}
	ruleElement* pR = R->head;
	
	while (pR != NULL){
		printf("%s ",pR->value->id);
		pR = pR->next;
	}
	printf(" ==> ");
	
	if (R->Conclusion != NULL){
		printf("%s",R->Conclusion->id);
	}
	printf("\n");
	
	return;
}

void printKnowledgeBase(KB* kb){
	if (kb == NULL){
		fprintf(stderr,"The pointer given for printKnowledgeBase is NULL \n");
		return;
	}
	KBElement* pkb = (*kb);
	printf("------------------------------------------- \n");
	printf("Rules curently in the knowledge base are : \n");
	while(pkb != NULL){
		printf("Rule  %s : \n",pkb->KBrule->name);
		printRule(pkb->KBrule);
		pkb = pkb->next;
	}
	printf("------------------------------------------- \n");
	return;
}



void printFactBase(FB* fb){
	if (fb == NULL){
		fprintf(stderr,"The pointer given for printFactBase is NULL \n");
		return;
	}
	factElement * pfb = (*fb);
	printf("------------------------------------------- \n");
	printf("Propositions that ae acctually in the fact base are : \n (");
	while (pfb != NULL){
		printf("%s,",pfb->value->id);
		pfb = pfb->next;
	}
	printf(")\n");
	printf("------------------------------------------- \n");
	return;
}


KB* UseraddRule(KB* kb,char* id){
	if (kb == NULL || id == NULL){
		fprintf(stderr,"One of the the pointers in UseraddRule is NULL (kb = %p, R = %p)\n",(void *) kb,(void *) id);
      	return kb;
    }
    Rule * R = createEmptyRule();
    R->name = id;
    kb = addRule(kb,R);
    return kb;
}
    
FB* UseraddProposition(FB* fb,char* id){
	if (fb == NULL || id == NULL){
		fprintf(stderr,"One of the the pointers in UseraddProposition is NULL (kb = %p, R = %p)\n",(void *) fb,(void *) id);
      	return fb;
    }
    Proposition * P = createEmptyProposition();
    P->id = id;
    P->value = false;
    fb = addFact(fb,P);
    return fb;
}

KB* UseraddPremisse(KB* kb,FB* pool,char* idR,char* idP){
	if (pool == NULL || idR == NULL || idP  == NULL || kb == NULL){
		fprintf(stderr,"One of the the pointers in UseraddPremisse is NULL (pool = %p, kb = %p, idR = %s, idp = %s )\n",(void *) pool,(void *) kb,idR,idP);
    }else{
    	Rule* R = GetRule(kb,idR);
    	if (R == NULL){
    		printf("The rule you're looking for isn't in this kb");
    	}else{
    		Proposition * P = GetProposition(pool,idP);
			if (P == NULL){
    			printf("The Proposition you're looking for isn't in this pool of propostion");
    		}else{
    			addPremisse(R,P);
    		}
    	}
    }
   return kb;
}


KB* UseraddConclusion(KB* kb,FB* pool,char* idR,char* idP){
	if (pool == NULL || idR == NULL || idP  == NULL || kb == NULL){
		fprintf(stderr,"One of the the pointers in UseraddConclusion is NULL (pool = %p, kb = %p, idR = %s, idp = %s )\n",(void *) pool,(void *) kb,idR,idP);
    }else{
    	Rule* R = GetRule(kb,idR);
    	if (R == NULL){
    		printf("The rule you're looking for isn't in this kb in");
    	}else{
    		Proposition * P = GetProposition(pool,idP);
			if (P == NULL){
    			printf("The Proposition you're looking for isn't in this pool of propostion");
    		}else{
    			if (R->Conclusion == NULL){
    				addConclusion(R,P);
    			}
    		}
    	}
    }
   return kb;
}
    
Rule* GetRule(KB* kb,char * id){
	if(kb == NULL || id == NULL){
		fprintf(stderr, "You have a NULL pointer in GetRule function, (kb = %p, id = %p)",(void *) kb,(void *) id);
		return NULL;
    }
    KBElement * pkb = (*kb);
    while (pkb != NULL){
    	if (strcmp(id,pkb->KBrule->name) == 0){
    		return pkb->KBrule;
    	}else{
    		pkb = pkb->next;
    	}
    }
    return NULL;
   }


Proposition* GetProposition(FB* fb,char* id){
	if (fb == NULL || id == NULL){
		fprintf(stderr,"One of the the pointers in GetProposition is NULL (kb = %p, R = %p)\n",(void *) fb,(void *) id);
      	return NULL;
    }
    factElement * pfb = (*fb);
    while (pfb != NULL){
    	if (strcmp(pfb->value->id,id) == 0){
    		return pfb->value;
    	}else{
    		pfb = pfb->next;
    	}
    }
    return NULL;
}
    
char* GetRuleIDInput(KB* kb){
		char* Rname = (char*) malloc(sizeof(char)*255);
	do{	
		printf("Please enter the name of the new rule (must different from previous one and len< 15)\n");
		scanf("%s",Rname);
		}while (strcmp(Rname,"") == 0 || strlen(Rname) > 15);
		return Rname;
}


char* GetRulePropositionId(){
		char* Rname = (char*) malloc(sizeof(char)*255);
	do{	
		printf("Please enter the name of the new proposition (must different from previous one and len< 15)\n");
		scanf("%s",Rname);
		}while (strcmp(Rname,"") == 0 || strlen(Rname) > 15);
		return Rname;
}	




void clrscr()
{
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
       system("clear");
   #endif

   #if defined(_WIN32) || defined(_WIN64)
       system("cls");
   #endif
}
