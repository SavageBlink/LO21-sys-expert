/**
 * @file engine.h
 * @author Guillaume/Hendercraft Driss/SavageBlink
 * @date 30 december 2020
 * @brief C file for the interface, manage prints and user input
 */

#include "headers/interface.h"


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



	
	
